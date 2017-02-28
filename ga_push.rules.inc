<?php
/**
 * @file
 * Rules implementation.
 */

/**
 * Implements hook_rules_action_info().
 */
function ga_push_rules_action_info() {

  $items['ga_push_action_push_event'] = array(
    'label' => t('Ga push: event'),
    'group' => t('GA Push'),
    'named parameter' => TRUE,
    'parameter' => array(
      'method' => array(
        'type' => 'text',
        'label' => t('Method'),
        'description' => t("Select the method"),
        'options list' => 'ga_push_get_methods_option_list_event',
        'default value' => GA_PUSH_METHOD_DEFAULT,
        'optional' => FALSE,
      ),
      'event' => array(
        'type' => 'text',
        'label' => t('Event'),
        'optional' => TRUE,
        'description' => t('The event name for Data Layer.'),
      ),
      'category' => array(
        'type' => 'text',
        'label' => t('Category'),
        'description' => t('The name you supply for the group of objects you want to track.'),
      ),
      'action' => array(
        'type' => 'text',
        'label' => t('Action'),
        'description' => t('A string that is uniquely paired with each category, and commonly used to define the type of user interaction for the web object.'),
        'translatable' => TRUE,
      ),
      'label' => array(
        'type' => 'text',
        'label' => t('Label'),
        'description' => t('An optional string to provide additional dimensions to the event data.'),
        'translatable' => TRUE,
        'optional' => TRUE,
      ),
      'value' => array(
        'type' => 'text',
        'label' => t('Value'),
        'description' => t("An integer that you can use to provide numerical data about the user event."),
        'optional' => TRUE,
      ),
      'non-interaction' => array(
        'type' => 'text',
        'label' => t('Non interaction'),
        'description' => t("A boolean that when set to true, indicates that the event hit will not be used in bounce-rate calculation. (Not compatible with SSGA method)."),
        'options list' => 'ga_push_get_event_non_interaction_option_list',
        'default value' => FALSE,
        'optional' => TRUE,
      ),
    ),
    'callbacks' => array(
      'form_alter' => 'ga_push_action_push_event_form_alter',
    ),
  );

  $items['ga_push_action_push_pageview'] = array(
    'label' => t('Ga push: page view'),
    'group' => t('GA Push'),
    'named parameter' => TRUE,
    'parameter' => array(
      'location' => array(
        'type' => 'text',
        'label' => t('Location'),
        'description' => t('URL of the page being tracked. By default, analytics.js sets this to the full document URL, excluding the fragment identifier.'),
        'translatable' => FALSE,
        'optional' => TRUE,
      ),
      'page' => array(
        'type' => 'text',
        'label' => t('Page'),
        'description' => t("A string that is uniquely paired with each category, and commonly used to define the type of user interaction for the web object."),
        'optional' => TRUE,
      ),
      'title' => array(
        'type' => 'text',
        'label' => t('Title'),
        'description' => t("The title of the page."),
        'optional' => TRUE,
      ),
      'method' => array(
        'type' => 'text',
        'label' => t('Method'),
        'description' => t("Select the method"),
        'options list' => 'ga_push_get_methods_option_list_pageview',
        'default value' => GA_PUSH_METHOD_DEFAULT,
        'optional' => FALSE,
      ),
    ),
  );

  $items['ga_push_action_push_social'] = array(
    'label' => t('Ga push: social'),
    'group' => t('GA Push'),
    'named parameter' => TRUE,
    'parameter' => array(
      'socialNetwork' => array(
        'type' => 'text',
        'label' => t('Social network'),
        'description' => t('The network on which the action occurs (e.g. Facebook, Twitter).'),
        'translatable' => FALSE,
        'optional' => FALSE,
      ),
      'socialAction' => array(
        'type' => 'text',
        'label' => t('Social action'),
        'description' => t("The type of action that happens (e.g. Like, Send, Tweet)."),
        'optional' => FALSE,
      ),
      'socialTarget' => array(
        'type' => 'text',
        'label' => t('Social target'),
        'description' => t("Specifies the target of a social interaction. This value is typically a URL but can be any text. (e.g. http://mycoolpage.com)."),
        'optional' => FALSE,
      ),
      'method' => array(
        'type' => 'text',
        'label' => t('Method'),
        'description' => t("Select the method"),
        'options list' => 'ga_push_get_methods_option_list_social',
        'default value' => GA_PUSH_METHOD_DEFAULT,
        'optional' => FALSE,
      ),
    ),
  );

  $items['ga_push_action_push_exception'] = array(
    'label' => t('Ga push: exception'),
    'group' => t('GA Push'),
    'named parameter' => TRUE,
    'parameter' => array(
      'exDescription' => array(
        'type' => 'text',
        'label' => t('Description'),
        'description' => t('A description of the exception..'),
        'translatable' => FALSE,
        'optional' => TRUE,
      ),
      'exFatal' => array(
        'type' => 'boolean',
        'label' => t('Is Fatal?'),
        'description' => t('Indicates whether the exception was fatal. true indicates fatal.'),
        'optional' => TRUE,
      ),
      'method' => array(
        'type' => 'text',
        'label' => t('Method'),
        'description' => t("Select the method"),
        'options list' => 'ga_push_get_methods_option_list_exception',
        'default value' => GA_PUSH_METHOD_DEFAULT,
        'optional' => FALSE,
      ),
    ),
  );

  return $items;
}

/**
 * Ga push event action form alter.
 *
 * @param array $form
 * @param array $form_state
 */
function ga_push_action_push_event_form_alter(&$form, &$form_state) {
  // Event only will be visible if:
  // - Datalayer method is selected.
  // - Default method is selected and is set up as datalayer.

  $default_method_key = variable_get('ga_push_default_method', GA_PUSH_METHOD_ANALYTICS_JS);
  $states = array();
  $states['visible'] = array(
    '#edit-parameter-method-settings-method' => array(
      array('value' => 'datalayer-js'),
    ),
  );

  if ($default_method_key == GA_PUSH_METHOD_DATALAYER_JS) {
    $states['visible']['#edit-parameter-method-settings-method'][] = array('value' => 'default');
  }

  $form['parameter']['event'] += array(
    '#states' => $states,
  );
}

/**
 * Add a push event from a rules action.
 */
function ga_push_action_push_event($parameters) {
  $value = trim($parameters['value']);
  $push = array(
    'eventCategory'        => $parameters['category'],
    'eventAction'          => $parameters['action'],
    'eventLabel'           => $parameters['label'],
    'eventValue'           => strlen($value) ? (int) $value : NULL,
    'non-interaction' => (bool) $parameters['non-interaction'],
  );

  // Add event property only for datalayer.
  $default_method_key = variable_get('ga_push_default_method', GA_PUSH_METHOD_ANALYTICS_JS);
  if ($parameters['method'] == GA_PUSH_METHOD_DATALAYER_JS
    || ($parameters['method'] == GA_PUSH_METHOD_DEFAULT
      && $default_method_key == GA_PUSH_METHOD_DATALAYER_JS)) {
    $push['event'] = $parameters['event'];
  }
  ga_push_add_event($push, $parameters['method']);
}

/**
 * Add a push exception from a rules action.
 */
function ga_push_action_push_exception($parameters) {
  $push = array(
    'exDescription' => $parameters['exDescription'],
    'exFatal'       => (bool) $parameters['exFatal'],
  );
  ga_push_add_exception($push, $parameters['method']);
}

/**
 * Add a push pageview from a rules action.
 */
function ga_push_action_push_pageview($parameters) {
  $push = array(
    'location'        => $parameters['location'],
    'page'            => $parameters['page'],
    'title'           => $parameters['title'],
  );
  ga_push_add_pageview($push, $parameters['method']);
}

/**
 * Add a push pageview from a rules action.
 */
function ga_push_action_push_social($parameters) {
  $push = array(
    'socialNetwork' => $parameters['socialNetwork'],
    'socialAction'  => $parameters['socialAction'],
    'socialTarget'  => $parameters['socialTarget'],
  );
  ga_push_add_social($push, $parameters['method']);
}
