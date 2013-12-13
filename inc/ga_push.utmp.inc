<?php
/**
 * @file
 * UTMP: method and functions for Universal Tracking Measure Protocol.
 */


// Google UTMP Endpoint URL.
define('GA_PUSH_METHOD_UTMP_HOST_ENDPOINT', 'www.google-analytics.com');



/**
 * Method: UTMP
 */
function ga_push_method_php_utmp($push, $type) {



  $data = array();

  switch ($type) {

    case GA_PUSH_TYPE_EVENT:

      $data['t'] = 'event';

      // Required:
      $data['ec'] = $push['category'];
      $data['ea'] = $push['action'];

      // Optional:
      if (isset($push['label'])) {
        $data['el'] = $push['label'];
      }
      if (isset($push['value'])) {
        $data['ev'] = $push['value'];
      }

      // @TODO: Check if this attribute is still used.
      //if (isset($push['non-interaction'])) {
      //
      break;

    case GA_PUSH_TYPE_ECOMMERCE:
//
//      if (isset($push['trans']) && isset($push['items']) && count($push['items'])) {
//
//        $transaction = new UnitedPrototype\GoogleAnalytics\Transaction();
//        $transaction->setOrderId($push['trans']['order_id']);
//        $transaction->setAffiliation($push['trans']['affiliation']);
//        $transaction->setTotal($push['trans']['total']);
//        $transaction->setTax($push['trans']['total_tax']);
//        $transaction->setShipping($push['trans']['total_shipping']);
//        $transaction->setCity($push['trans']['city']);
//        $transaction->setRegion($push['trans']['region']);
//        $transaction->setCountry($push['trans']['country']);
//
//        foreach ($push['items'] as $value) {
//          $item = new UnitedPrototype\GoogleAnalytics\Item();
//          $item->setOrderId($value['order_id']);
//          $item->setSku($value['sku']);
//          $item->setName($value['name']);
//          //$item->setCategory($value['category]);
//          //Until it changes in the current library, the category method  -> set Variation. http://code.google.com/p/php-ga/issues/detail?id=13
//          $item->setVariation($value['category']);
//          $item->setPrice($value['price']);
//          $item->setQuantity($value['quantity']);
//
//          $transaction->addItem($item);
//        }
//
//        $tracker->trackTransaction($transaction, $session, $visitor);
//
//      }

      break;

  }

  if (!empty($data)) {
    // @TODO: Check response.
    ga_push_method_php_utmp_request($data);
  }
}


function ga_push_method_php_utmp_request($data = array(), $method = 'POST') {
  $data += array(
    'v' => 1,
    'tid' => variable_get('googleanalytics_account', ''),
    'cid' => ga_push_method_php_utmp_gen_uuid(), /// @TODO determine this value.
  );


  $url = 'http://' . GA_PUSH_METHOD_UTMP_HOST_ENDPOINT;


  $options = array(
    'method' => $method,
    'data' => drupal_http_build_query($data),
  );

  // @TODO: Check errors here so caller doesn't have to do it.
  $response = drupal_http_request($url, $options);

  return;

}

/**
 * Generates an UUID ver 4 identifier.
 *
 * Thanks to Andrew Mooer at php.net.
 * http://www.php.net/manual/en/function.uniqid.php#94959
 *
 * @return type
 */
function ga_push_method_php_utmp_gen_uuid() {
  return sprintf( '%04x%04x-%04x-%04x-%04x-%04x%04x%04x',
    // 32 bits for "time_low"
    mt_rand(0, 0xffff ), mt_rand(0, 0xffff),

    // 16 bits for "time_mid"
    mt_rand(0, 0xffff),

    // 16 bits for "time_hi_and_version",
    // four most significant bits holds version number 4
    mt_rand(0, 0x0fff) | 0x4000,

    // 16 bits, 8 bits for "clk_seq_hi_res",
    // 8 bits for "clk_seq_low",
    // two most significant bits holds zero and one for variant DCE1.1
    mt_rand(0, 0x3fff) | 0x8000,

    // 48 bits for "node"
    mt_rand(0, 0xffff), mt_rand(0, 0xffff), mt_rand(0, 0xffff)
  );
}