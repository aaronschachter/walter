<?php
/**
 * @file
 * walter_costbenefit.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function walter_costbenefit_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create costbenefit'.
  $permissions['create costbenefit'] = array(
    'name' => 'create costbenefit',
    'roles' => array(
      'beta user' => 'beta user',
    ),
    'module' => 'walter_costbenefit',
  );

  // Exported permission: 'delete own costbenefit'.
  $permissions['delete own costbenefit'] = array(
    'name' => 'delete own costbenefit',
    'roles' => array(
      'beta user' => 'beta user',
    ),
    'module' => 'walter_costbenefit',
  );

  return $permissions;
}
