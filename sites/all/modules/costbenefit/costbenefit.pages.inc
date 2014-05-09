<?php

/**
 * @file
 * Provides page callbacks for the Costbenefit module.
 */

/**
 * Page callback for /home.
 */
function costbenefit_home_page() {
  if (!user_is_logged_in()) { return t('Please sign in.'); }

  $list = views_embed_view('cb_list', 'default');
  $add_form = drupal_get_form('costbenefit_form', NULL);
  return theme('costbenefit_list', array(
    'list' => $list,
    'add_form' => $add_form,
  ));
}
