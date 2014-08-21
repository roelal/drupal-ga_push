<?php
/**
 * @file
 * Javascript: method and functions
 */


/**
 * Callback for Javascript Classic method.
 *
 * @param type $push
 * @param type $type
 */
function ga_push_method_javascript($push, $type, $options) {

  $push_info = array(
    'push' => $push,
    'type' => $type,
  );
  $_SESSION['ga_push'][] = $push_info;

}

/**
 * Send the ga push to JS on page load
 * @see https://developers.google.com/analytics/devguides/collection/gajs
 */
function ga_push_method_javascript_push() {
  if (isset($_SESSION['ga_push'])) {

    $id = variable_get('googleanalytics_account', '');

    if (!empty($id)) {
      $script = "var _gaq = _gaq || [];\n ";

      foreach ($_SESSION['ga_push'] as $queued) {

        $push = $queued['push'];
        $type = $queued['type'];

        switch ($type) {

          case GA_PUSH_TYPE_EVENT:


            // Optional: default values
            $push += array(
              'label' => '',
              'value' => 1,
              // 'non-interaction' => false,
            );

            $push_map = array(
              'category' => 'category',
              'action'   => 'action',
              'label'    => 'label',
              'value'    => 'value',
              'non-interaction' => 'non-interaction',
            );

            // Mapping.
            $mapped_push = ga_push_push_mapper($push_map, $push);

            // Add method.
            array_unshift($mapped_push, '_trackEvent');

            // Convert to JSON to avoid special chars problems that could broke syntax.
            $script_params = json_encode(array_values($mapped_push));

            // Convert to JS function.
            $script = '_gaq.push(' . $script_params . ");\n";

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

            // Currency: by default, you can configure a common, global, currency
            // for all transactions and items through the Google Analytics management
            // web interface. By default, the global currency is used for all items
            // and transactions.
            if (!empty($push['trans']['currency'])) {
              $script .= "_gaq.push(['_set', 'currencyCode', '"
                . $push['trans']['currency'] . "']);\n";
            }

            //Transaction - end:
            $script .= "_gaq.push(['_trackTrans']);\n ";

            break;

        }

      }

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