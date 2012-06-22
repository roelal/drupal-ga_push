<?php

/**
 * Implements hook_rules_action_info
 */

function ga_push_rules_action_info() {
  
  $items['ga_push_action_push'] = array(
    'label' => t('Ga push'),
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
          'description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
          'optional' => TRUE,
        ),
      ),
  );
  
  return $items;
  
}

/**
 * Add a push form a node action
 */
function ga_push_action_push($category, $action, $label, $value) {
  $push = array($category, $action, $label, $value);
  ga_push_add($push);
}