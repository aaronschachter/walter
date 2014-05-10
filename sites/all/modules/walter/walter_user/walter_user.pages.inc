<?php
/**
 * @file
 * Provides page callbacks for the walter_user module.
 */

/**
 * Page callback for /front.
 */
function walter_user_front_page() {
  if (!user_is_logged_in()) {
    $login_form = drupal_get_form('user_login_block');
    dsm($login_form);
    $register_form = drupal_get_form('user_register_form');
    return theme('walter_front_page', array(
      'login_form' => $login_form,
      'register_form' => $register_form,
    )); 
  }

  $list = views_embed_view('cb_list', 'default');
  $add_form = drupal_get_form('walter_costbenefit_form', NULL);
  return theme('costbenefit_list', array(
    'list' => $list,
    'add_form' => $add_form,
  ));
}
