<?php
/**
 * @file
 * Rules implementation
 */

/**
 * Implements hook_rules_action_info
 */
function ga_push_rules_action_info() {

  $items['ga_push_action_push_event'] = array(
    'label' => t('Ga push: event'),
    'group' => t('Others'),
    'parameter' => array(
      'category' => array(
          'type' => 'text',
          'label' => t('Category'),
          'description' => t('Category'),
        ),
      'action' => array(
          'type' => 'text',
          'label' => t('Action'),
          'description' => t('Action'),
          'translatable' => TRUE,
        ),
      'label' => array(
          'type' => 'text',
          'label' => t('Label'),
          'description' => t('Label'),
          'translatable' => TRUE,
      ),
      'value' => array(
          'type' => 'text',
          'label' => t('Value'),
          'description' => t("Numeric"),
          'optional' => TRUE,
        ),
      'method' => array(
          'type' => 'text',
          'label' => t('Method'),
          'description' => t("Select the method"),
          'options list' => 'ga_push_get_methods_option_list_event',
          'default value' => GA_PUSH_METHOD_DEFAULT,
          'optional' => FALSE,
        ),
      ),
  );

  return $items;
}

/**
 * Add a push form a rule action
 */
function ga_push_action_push_event($category, $action, $label, $value, $method) {
  $push = array(
    'category' => $category,
    'action'   => $action,
    'label'    => $label,
    'value'    => (int) $value
  );
  ga_push_add($push, GA_PUSH_TYPE_EVENT, $method);
}