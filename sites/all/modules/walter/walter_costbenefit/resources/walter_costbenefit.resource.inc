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
  return walter_costbenefit_get_cb_id($account);
}
