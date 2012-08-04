<?php

/**
 * Method: PHP-GA
 */
function ga_push_method_php_ga($push, $type) {

  $php_ga_path = libraries_get_path('php-ga');
  include_once($php_ga_path . '/src/autoload.php');

  //use UnitedPrototype\GoogleAnalytics;  //causes 500 Internal Server error, so need to use full namespace references eg UnitedPrototype\GoogleAnalytics\Tracker instead of GoogleAnalytics\Tracker

  $ua = variable_get('googleanalytics_account', '');
  $host = str_replace(array('http://', 'https://'), array('',''), $GLOBALS['base_url']);
  $tracker = new UnitedPrototype\GoogleAnalytics\Tracker($ua, $host);

  $visitor = new UnitedPrototype\GoogleAnalytics\Visitor();
  $visitor->setIpAddress($_SERVER['REMOTE_ADDR']);
  $visitor->setUserAgent($_SERVER['HTTP_USER_AGENT']);
  $session = new UnitedPrototype\GoogleAnalytics\Session();

  switch ($type) {

    case GA_PUSH_TYPE_EVENT:
      $event = new UnitedPrototype\GoogleAnalytics\Event();
      $event->setCategory($push[0]);
      $event->setAction($push[1]);
      $event->setLabel($push[2]);
      $event->setValue($push[3]);
      if (isset($push[4])) {
        $event->setNoninteraction($push[4]);
      }
      $tracker->trackEvent($event, $session, $visitor);
      break;

    case GA_PUSH_TYPE_ECOMMERCE:

      if (isset($push['trans']) && isset($push['items']) && count($push['items'])) {

        $transaction = new UnitedPrototype\GoogleAnalytics\Transaction();
        $transaction->setOrderId($push['trans'][0]);
        $transaction->setAffiliation($push['trans'][1]);
        $transaction->setTotal($push['trans'][2]);
        $transaction->setTax($push['trans'][3]);
        $transaction->setShipping($push['trans'][4]);
        $transaction->setCity($push['trans'][5]);
        $transaction->setRegion($push['trans'][6]);
        $transaction->setCountry($push['trans'][6]);

        foreach ($push['items'] as $value) {
          $item = new UnitedPrototype\GoogleAnalytics\Item();
          $item->setOrderId($value[0]);
          $item->setSku($value[1]);
          $item->setName($value[2]);
          //$item->setCategory($value[3]);
          //Until it changes in the current library, the category method  -> set Variation. http://code.google.com/p/php-ga/issues/detail?id=13
          $item->setVariation($value[3]);
          $item->setPrice($value[4]);
          $item->setQuantity($value[5]);

          $transaction->addItem($item);
        }

        $tracker->trackTransaction($transaction, $session, $visitor);

      }

      break;

  }

  //dpm('set');
  //print 'set';
  /*
  $page = new GoogleAnalytics\Page('/path'); //TODO
  $page->setTitle('Títle') //TODO
  //$tracker->trackPagevire($page, $session, $visitor);
  */

}