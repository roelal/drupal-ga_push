<?php
/**
 * Method: javascript
 */
function ga_push_method_javascript($push, $type) {

  $push_info = array(
    'push' => $push,
    'type' => $type,
  );
  $_SESSION['ga_push'][] = $push_info;

}

/**
 * Send the ga push to JS on page load
 */
function ga_push_method_javascript_push() {
  if (isset($_SESSION['ga_push'])) {

    $id = variable_get('googleanalytics_account', '');

    if (!empty($id)) {
      $script = "var _gaq = _gaq || [];\n ";

      foreach ($_SESSION['ga_push'] as $queued) {

        $num = 0;
        $push = $queued['push'];
        $type = $queued['type'];

        switch ($type) {

          case GA_PUSH_TYPE_EVENT:

            $script .= "_gaq.push([";

            $script .= "'_trackEvent', ";
            while ($num < count($push)) {
              $script .=  ($num != 3) ? "'" . $push[$num] . "'" : $push[$num];
              $script .= isset($push[$num+1]) ? ", " : "";
              $num++;
            }

            $script .= "]); \n";

            break;

          case GA_PUSH_TYPE_ECOMMERCE:

            //Transaction:
            $script .= "_gaq.push(['_addTrans', " .
                       "'" . $push['trans'][0] . "', " . // order ID - required
                       "'" . $push['trans'][1] . "', " . // affiliation or store name
                       "'" . $push['trans'][2] . "', " . // total - required
                       "'" . $push['trans'][3] . "', " . // tax
                       "'" . $push['trans'][4] . "', " . // shipping
                       "'" . $push['trans'][5] . "', " . // city
                       "'" . $push['trans'][6] . "', " . // state or province
                       "'" . $push['trans'][7] . "'" .   // country
                       "]);\n ";


            foreach ($push['items'] as $value) {

              $script .= "_gaq.push(['_addItem', " .
                         "'" . $value[0] . "', " . // order ID - required
                         "'" . $value[1] . "', " . // SKU/code - required
                         "'" . $value[2] . "', " . // product name
                         "'" . $value[3] . "', " . // category or variation
                         "'" . $value[4] . "', " . // unit price - required
                         "'" . $value[5] . "'" .   // quantity - required
                         "]);\n ";

            }

            //Transaction - end:
            $script .= "_gaq.push(['_trackTrans']);\n ";

            break;

        }



      }
      //dpm($script, 't');
      unset($_SESSION['ga_push']);

      $options = array(
        'type' => 'inline',
        'scope' => 'footer',
        //'weight' => 0,
        //'group' => JS_DEFAULT,
      );
      drupal_add_js($script, $options);

    }
  }
}