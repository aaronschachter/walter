<?php
/**
 * @file
 * costbenefit.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function costbenefit_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cb_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'costbenefit';
  $view->human_name = 'CB List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Cost-Benefit: Cost-benefit ID */
  $handler->display->display_options['fields']['cb_id']['id'] = 'cb_id';
  $handler->display->display_options['fields']['cb_id']['table'] = 'costbenefit';
  $handler->display->display_options['fields']['cb_id']['field'] = 'cb_id';
  $handler->display->display_options['fields']['cb_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cb_id']['separator'] = '';
  /* Field: Cost-Benefit: Label */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'costbenefit';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'cb/[cb_id]';
  /* Field: Cost-Benefit: Updated */
  $handler->display->display_options['fields']['updated']['id'] = 'updated';
  $handler->display->display_options['fields']['updated']['table'] = 'costbenefit';
  $handler->display->display_options['fields']['updated']['field'] = 'updated';
  /* Contextual filter: Cost-Benefit: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'costbenefit';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'cb';
  $export['cb_list'] = $view;

  return $export;
}
