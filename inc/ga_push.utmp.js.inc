<?php
/**
 * @file
 * UTMP Javascript: method and functions
 */



function ga_push_method_utmp_js($push, $type) {
  $push_info = array(
    'push' => $push,
    'type' => $type,
  );
  $_SESSION['ga_push_utmp'][] = $push_info;
}


/**
 * Send the ga push to JS on page load using Universal Analytics Event Tracking.
 */
function ga_push_method_utmp_js_push() {
  if (isset($_SESSION['ga_push_utmp'])) {
    $id = variable_get('googleanalytics_account', '');
    if (!empty($id)) {
      $script = "var ga = ga || [];\n ";

      // Process each push data that needs to be sent to Google Analytics.
      foreach ($_SESSION['ga_push_utmp'] as $queued) {
        $push = $queued['push'];
        $type = $queued['type'];

        switch ($type) {
          case GA_PUSH_TYPE_EVENT:
            $script .= _ga_push_method_utmp_js_push_event_script($push);
          break;

          case GA_PUSH_TYPE_ECOMMERCE:
            $script .= _ga_push_method_utmp_js_push_ecommerce_script($push);
          break;
        }
      }
      _ga_push_method_utmp_js_add_script($script);
      unset($_SESSION['ga_push_utmp']);
    }
  }
}


/**
 * Generates the ga JS code for pushing an event to GA.
 *
 * @param array $push
 *   Event data.
 *
 * @return string
 *   JS code with push code.
 */
function _ga_push_method_utmp_js_push_event_script($push) {


}



/**
 * Generates the ga JS code for pushing an ecommerce to GA.
 *
 * @param array $push
 *   Event data.
 *
 * @return string
 *   JS code with push code.
 */
function _ga_push_method_utmp_js_push_ecommerce_script($push) {


}


/**
 * Adds generated script with push data.
 *
 * Used by ga_push_method_utmp_js_push.
 *
 * @see ga_push_method_utmp_js_push().
 *
 * @param string $script
 *   Generated script code to add.
 */
function _ga_push_method_utmp_js_add_script($script) {
  $options = array(
    'type' => 'inline',
    'scope' => 'footer',
    //'weight' => 0,
    //'group' => JS_DEFAULT,
  );
  drupal_add_js($script, $options);
}