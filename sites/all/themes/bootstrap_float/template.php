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
 * Implemlents hook_form_alter().
 */
function bootstrap_float_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'walter_costbenefit_item_edit_form') {
    $form['#attributes']['class'][] = 'bv-form';
    $form['title']['#prefix'] = '<div class="form-group">';
    $form['title']['#suffix'] = bootstrap_float_get_required_error('title') . '</div>';
    $form['title']['#attributes']['data-bv-field'][] = 'title';
  }
}

function bootstrap_float_get_required_error($name) {
  return '<small data-bv-validator="notEmpty" data-bv-validator-for="' . $name . '" class="help-block" style="display: none;">The ' . $name . ' is required and cannot be empty</small>';
}
