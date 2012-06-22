<?php

/**
 * Views for the default order UI.
 */

/**
 * Implements hook_views_default_views().
 */
function ga_push_browser_views_default_views() {
  $views = array();
  
  $view = new view;
  $view->name = 'ga_push_browser_event';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'ga_push_browser_event';
  $view->human_name = 'Ga push browser events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ga push browser events';
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascendente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Campo: Ga Push Browser entity: Ga push browser entity ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Campo: Ga Push Browser entity: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Nombre';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  /* Campo: Ga Push Browser entity: Selector */
  $handler->display->display_options['fields']['selector']['id'] = 'selector';
  $handler->display->display_options['fields']['selector']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['selector']['field'] = 'selector';
  $handler->display->display_options['fields']['selector']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['external'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['selector']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['selector']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['selector']['alter']['html'] = 0;
  $handler->display->display_options['fields']['selector']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['selector']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['selector']['hide_empty'] = 0;
  $handler->display->display_options['fields']['selector']['empty_zero'] = 0;
  $handler->display->display_options['fields']['selector']['hide_alter_empty'] = 1;
  /* Campo: Ga Push Browser entity: Bind */
  $handler->display->display_options['fields']['bind']['id'] = 'bind';
  $handler->display->display_options['fields']['bind']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['bind']['field'] = 'bind';
  $handler->display->display_options['fields']['bind']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['external'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['bind']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['bind']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['bind']['alter']['html'] = 0;
  $handler->display->display_options['fields']['bind']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['bind']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['bind']['hide_empty'] = 0;
  $handler->display->display_options['fields']['bind']['empty_zero'] = 0;
  $handler->display->display_options['fields']['bind']['hide_alter_empty'] = 1;
  /* Campo: Ga Push Browser entity: Ga_category */
  $handler->display->display_options['fields']['ga_category']['id'] = 'ga_category';
  $handler->display->display_options['fields']['ga_category']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['ga_category']['field'] = 'ga_category';
  $handler->display->display_options['fields']['ga_category']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ga_category']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ga_category']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ga_category']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ga_category']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ga_category']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ga_category']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ga_category']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ga_category']['hide_alter_empty'] = 1;
  /* Campo: Ga Push Browser entity: Ga_action */
  $handler->display->display_options['fields']['ga_action']['id'] = 'ga_action';
  $handler->display->display_options['fields']['ga_action']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['ga_action']['field'] = 'ga_action';
  $handler->display->display_options['fields']['ga_action']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ga_action']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ga_action']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ga_action']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ga_action']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ga_action']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ga_action']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ga_action']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ga_action']['hide_alter_empty'] = 1;
  /* Campo: Ga Push Browser entity: Ga_label */
  $handler->display->display_options['fields']['ga_label']['id'] = 'ga_label';
  $handler->display->display_options['fields']['ga_label']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['ga_label']['field'] = 'ga_label';
  $handler->display->display_options['fields']['ga_label']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ga_label']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ga_label']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ga_label']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ga_label']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ga_label']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ga_label']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ga_label']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ga_label']['hide_alter_empty'] = 1;
  /* Campo: Ga Push Browser entity: Ga_value */
  $handler->display->display_options['fields']['ga_value']['id'] = 'ga_value';
  $handler->display->display_options['fields']['ga_value']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['ga_value']['field'] = 'ga_value';
  $handler->display->display_options['fields']['ga_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ga_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ga_value']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ga_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ga_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ga_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ga_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ga_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ga_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['ga_value']['format_plural'] = 0;
  /* Campo: Ga Push Browser entity: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'ga_push_browser_event';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Estado';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['format_plural'] = 0;
  /* Campo: Global: Texto personalizado */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/config/system/ga-push/browser/[id]/edit';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/config/system/ga-push/browser';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'GA Push Browser';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['ga_push_browser_event'] = array(
    t('Master'),
    t('Ga push browser events'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Ascendente'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('Ga push browser entity ID'),
    t('.'),
    t(','),
    t('Nombre'),
    t('Selector'),
    t('Bind'),
    t('Ga_category'),
    t('Ga_action'),
    t('Ga_label'),
    t('Ga_value'),
    t('Estado'),
    t('edit'),
    t('admin/config/system/ga-push/ga-browser/[id]/edit'),
    t('Page'),
  );
  
  $views[$view->name] = $view;

  return $views;
}