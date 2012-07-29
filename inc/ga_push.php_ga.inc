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

  $event = new UnitedPrototype\GoogleAnalytics\Event();
  $event->setCategory($push[0]);
  $event->setAction($push[1]);
  $event->setLabel($push[2]);
  $event->setValue($push[3]);
  if (isset($push[4])) {
    $event->setNoninteraction($push[4]);
  }
  $tracker->trackEvent($event, $session, $visitor);
  //dpm('set');
  //print 'set';
  /*
  $page = new GoogleAnalytics\Page('/path'); //TODO
  $page->setTitle('Títle') //TODO
  //$tracker->trackPagevire($page, $session, $visitor);
  */

}