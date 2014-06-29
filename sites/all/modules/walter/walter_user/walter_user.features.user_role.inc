<?php
/**
 * @file
 * walter_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function walter_user_user_default_roles() {
  $roles = array();

  // Exported role: beta user.
  $roles['beta user'] = array(
    'name' => 'beta user',
    'weight' => 2,
  );

  return $roles;
}
