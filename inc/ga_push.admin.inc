<?php

/**
 * Form: ga_push settings().
 */
function ga_push_settings_form($form, $form_state) {
  
  $form = array();
  
  //TODO: hacer filtro de los métodos en función de disponibilidad: (PHP);
  
  if (ga_push_method_available(GA_PUSH_METHOD_JS)) {
    $options[GA_PUSH_METHOD_JS] = t('Javascript');
  }
  if (ga_push_method_available(GA_PUSH_METHOD_SSGA)) {
    $options[GA_PUSH_METHOD_SSGA] = t('SSGA: requires php 5.2+ and ssga libraries');
  }
  if (ga_push_method_available(GA_PUSH_METHOD_PHP_GA)) {
    $options[GA_PUSH_METHOD_PHP_GA] = t('PHP GA: requires php 5.3 and php-ga libraries');
  }
  
  $form['ga_push_default_method'] = array(
    '#type' => 'radios',
    '#title' => t('Default method'),
    '#options' => $options,
    '#default_value' => variable_get('ga_push_default_method', 'javascript'),
    '#required' => TRUE,
  );  
  
  return system_settings_form($form);
  
}