<?php

/**
 * @file
 * Hooks provided by Services for the definition of new services.
 */

function _walter_costbenefit_resource_access() {
  return TRUE;
}

function _walter_costbenefit_resource_retrieve($uid) {
  // This is silly.  
  // @todo: Change get_cb_id to retrieve for $uid instead of $user object.
  $account = user_load($uid);
  if ($cb_id = walter_costbenefit_get_cb_id($account)) {
    $cb = costbenefit_load($cb_id);
    return array(
      'cb_id' => $cb_id,
      'title' => $cb->title,
    );
  }
  return FALSE;
}
