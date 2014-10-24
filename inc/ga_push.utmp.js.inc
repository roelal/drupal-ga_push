<?php
/**
 * @file
 * UTMP Javascript: method and functions.
 */

/**
 * GA Push Method callback: UTMP (js).
 */
function ga_push_method_utmp_js($push, $type, $options) {
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
      $script = "var ga = ga || [];\n";

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

          case GA_PUSH_TYPE_EXCEPTION:
            $script .= _ga_push_method_utmp_js_push_exception_script($push);
            break;

          case GA_PUSH_TYPE_PAGEVIEW:
            $script .= _ga_push_method_utmp_js_push_send_script($push, 'pageview');
            break;

          case GA_PUSH_TYPE_SOCIAL:
            $script .= _ga_push_method_utmp_js_push_send_script($push, 'social');
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

  // Optional: default values.
  $push += array(
    'eventLabel' => '',
    'eventValue' => 1,
    'non-interaction' => FALSE,
  );

  // Convert to JS function.
  $script = _ga_push_method_utmp_js_push_send_script($push, 'event');

  return $script;
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

  // Include needed additional ga e-commerce library.
  $script = "ga('require', 'ecommerce', 'ecommerce.js');\n";

  // Transaction:
  $script .= "ga('ecommerce:addTransaction', " . json_encode($push['trans']) . ");\n";

  // Items:
  foreach ($push['items'] as $value) {
    $script .= "ga('ecommerce:addItem', " . json_encode($value) . ");\n";
  }

  // Sending!
  $script .= "ga('ecommerce:send');\n";

  return $script;
}

/**
 * Generates the ga JS code for pushing an exception to GA.
 *
 * @param array $push
 *   Event data.
 *
 * @return string
 *   JS code with push code.
 */
function _ga_push_method_utmp_js_push_exception_script($push) {
  // Remove empty parameters:
  $push = array_filter($push);

  // Convert to JS function.
  $script = "ga('send', 'exception', " . json_encode($push) . ");\n";

  return $script;
}

/**
 * Generates the ga send JS code.
 *
 * @param array $push
 *   Data.
 * @param string $hit_type
 *   The hit type: social, pageview...
 *
 * @return string
 *   JS code with push code.
 */
function _ga_push_method_utmp_js_push_send_script($push, $hit_type) {
  // Remove empty parameters:
  $push = array_filter($push);

  // Add the hitType: social.
  $push['hitType'] = $hit_type;

  // Convert to JS function.
  $script = "ga('send', " . json_encode($push) . ");\n";

  return $script;
}

/**
 * Adds generated script with push data.
 *
 * Used by ga_push_method_utmp_js_push.
 *
 * @see ga_push_method_utmp_js_push()
 *
 * @param string $script
 *   Generated script code to add.
 */
function _ga_push_method_utmp_js_add_script($script) {
  $options = array(
    'type' => 'inline',
    'scope' => 'footer',
    // 'weight' => 0,
    // 'group' => JS_DEFAULT,
  );
  drupal_add_js($script, $options);
}
