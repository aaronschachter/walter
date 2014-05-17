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
  drupal_add_css(drupal_get_path('theme', 'bootstrap_float') . '/dist/css/bootstrapValidator.css');
  drupal_add_js(drupal_get_path('theme', 'bootstrap_float') . '/dist/css/bootstrapValidator.js');}

/**
 * Implements theme_form_required_marker().
 */
function bootstrap_float_form_required_marker($variables) {
  return;
}
