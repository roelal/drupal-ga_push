<?php
/**
 * @file
 * SSGA: method and functions
 */

/**
 * Method: SSGA
 */
function ga_push_method_ssga($push, $type) {

  if (class_exists('ssga')) {

    $ga = new ssga();

    //Set your Google Analytics key
    $id = variable_get('googleanalytics_account', '');
    $ga->setAccountId($id);

    //Set your charset
    $ga->setCharset("UTF-8");

    //Set your hostname
    $ga->setHostName($GLOBALS['base_url']); //TODO: domain?

    //Set language
    $ga->setLanguage($GLOBALS['language']->language); //TODO: CAmbiar

    //Set an event (based on http://code.google.com/apis/analytics/docs/tracking/eventTrackerGuide.html)

    switch ($type) {

      case GA_PUSH_TYPE_EVENT:
        //Category, Acction, Label, Value
        $ga->setEvent($push[0], $push[1], $push[2], $push[3]);
        break;
      /*
      case '_trackPageview': //TODO ¿Tiene sentido?

        //Set a pageview
        $ga->setPageView("/de/serverside/test"); //TODO: cambiar
        //Set page title
        $ga->setPageTitle("Test"); //TODO: cambiar

        break;
      */
    }

    //Submit an event
    $ga->create(); //createEvent

  }
  else {
    //Throw an error
  }

}