<?php

/**
 * Form: ga_push settings().
 */
function ga_push_settings_form($form, $form_state) {

  $form = array();

  //TODO: hacer filtro de los métodos en función de disponibilidad: (PHP);
  $options = array();
  $methods = ga_push_get_methods();

  foreach ($methods as $key => $method) {
    if (ga_push_method_available($key)) {
      $options[$key] = $method['name'] . ': ' . $method['description'];
    }
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