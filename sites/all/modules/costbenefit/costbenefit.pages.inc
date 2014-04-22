<?php

/**
 * @file
 * Provides page callbacks for the Costbenefit module.
 */

/**
 * Page callback for /home.
 */
function costbenefit_home_page() {
  $output = '';
  if (user_is_logged_in()) {
    $output .= '<p class="text-right">';
    $output .= l('Create new', 'cb/add', array(
      'attributes' => array(
        'class' => 'btn btn-primary',
      )
    ));
    $output .= '</p>';
    $output .= views_embed_view('cb_list', 'default');
  }
  else {
    $output .= t('Please sign in.');
  }
  return $output;
}
