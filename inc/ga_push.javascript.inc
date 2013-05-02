<?php
/**
 * @file
 * Javascript: method and functions
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
                       "'" . $push['trans']['order_id'] . "', " . // order ID - required
                       "'" . $push['trans']['affiliation'] . "', " . // affiliation or store name
                       "'" . $push['trans']['total'] . "', " . // total - required
                       "'" . $push['trans']['total_tax'] . "', " . // tax
                       "'" . $push['trans']['total_shipping'] . "', " . // shipping
                       "'" . $push['trans']['city'] . "', " . // city
                       "'" . $push['trans']['region'] . "', " . // state or province
                       "'" . $push['trans']['country'] . "'" .   // country
                       "]);\n ";


            foreach ($push['items'] as $value) {

              $script .= "_gaq.push(['_addItem', " .
                         "'" . $value['order_id'] . "', " . // order ID - required
                         "'" . $value['sku'] . "', " . // SKU/code - required
                         "'" . $value['name'] . "', " . // product name
                         "'" . $value['category'] . "', " . // category or variation
                         "'" . $value['price'] . "', " . // unit price - required
                         "'" . $value['quantity'] . "'" .   // quantity - required
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