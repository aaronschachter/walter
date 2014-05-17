<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function bootstrap_float_preprocess_page(&$variables) {
  // Hide page titles on cb/* pages.
  $variables['show_title'] = TRUE;
  if (arg(0) == 'cb') {
    $variables['show_title'] = FALSE;
  }
  // Adds Bootstrap Validator files.
  drupal_add_css(drupal_get_path('theme', 'bootstrap_float') . '/validator/css/bootstrapValidator.min.css');
  drupal_add_js(drupal_get_path('theme', 'bootstrap_float') . '/validator/js/bootstrapValidator.min.js');
  drupal_add_js(drupal_get_path('theme', 'bootstrap_float') . '/js/validator.js');
}

/**
 * Implements theme_form_required_marker().
 */
function bootstrap_float_form_required_marker($variables) {
  return;
}

/**
 * Implements hook_form_alter().
 */
function bootstrap_float_form_alter(&$form, $form_state, $form_id) {
  if (substr($form_id,0, 6) == 'walter') {
    $form['#attributes']['class'][] = 'bv-form';
    bootstrap_float_add_bootstrap_validator_wrapper($form, 'title');
  }
  switch ($form_id) {
    case 'user_login_block':
      $form['#attributes']['class'][] = 'form-inline';
      break;
  }
}

/**
 * Adds Bootstrap Validator elements for given form element name.
 */
function bootstrap_float_add_bootstrap_validator_wrapper(&$form, $name) {
  $form[$name]['#prefix'] = '<div class="form-group">';
  $form[$name]['#suffix'] = '</div>';
}
