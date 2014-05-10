<?php

/**
 * @file
 * Provides page callbacks for the walter_costbenefit module.
 */

/**
 * Page callback for /home.
 */
function walter_costbenefit_home_page() {
  if (!user_is_logged_in()) { 
    return theme('costbenefit_front'); 
  }

  $list = views_embed_view('cb_list', 'default');
  $add_form = drupal_get_form('walter_costbenefit_form', NULL);
  return theme('costbenefit_list', array(
    'list' => $list,
    'add_form' => $add_form,
  ));
}
