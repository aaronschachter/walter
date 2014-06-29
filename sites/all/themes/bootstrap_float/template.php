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
  // Add login form variable.
  if (!user_is_logged_in()) {
    $variables['login_form'] = drupal_get_form('user_login_block');
  }
  else {
    $variables['costbenefit_nav'] = walter_costbenefit_index_item_list();
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
    $form['title']['#attributes']['class'][] = 'input-lg';
    $form['submit']['#attributes']['class'][] = 'btn-lg';
  }
  switch ($form_id) {
    case 'user_login_block':
      $form['#attributes']['class'][] = 'navbar-form';
      unset($form['name']['#title']);
      unset($form['pass']['#title']);
      $form['name']['#attributes']['placeholder'] = 'Email address';
      $form['pass']['#attributes']['placeholder'] = 'Password';
      break;
    case 'user_pass':
      drupal_set_title("Password reset");
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


/**
 * Implements theme_button().
 *
 * Here's a good reason why it sucks sometimes to use a starter theme.
 * The Bootstrap theme is automatically adding btn-success for some reason.
 *
 * @see bootstrap_button().
 *
 */
function bootstrap_float_button($variables) {
  $element = $variables['element'];
  $label = $element['#value'];
  element_set_attributes($element, array('id', 'name', 'value', 'type'));

  foreach ($element['#attributes']['class'] as $delta => $class) {
    // If the success class,
    if ($class == 'btn-success') {
      // Replace it with the primary.
      $element['#attributes']['class'][$delta] = 'btn-primary';
    }
  }

  // This line break adds inherent margin between multiple buttons.
  return '<button' . drupal_attributes($element['#attributes']) . '>' . $label . "</button>\n";
}
