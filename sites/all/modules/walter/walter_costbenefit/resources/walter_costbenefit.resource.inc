<?php

/**
 * @file
 * Hooks provided by Services for the definition of new services.
 */

/**
 * Access callback for given $cb_id.
 */
function _walter_costbenefit_resource_access($cb_id) {
  global $user;

  $cb = costbenefit_load($cb_id);
  // Only true when the global user is the author.
  $has_access = $user->uid == $cb->uid;
  // Log any ratfuckery.
  if (!$has_access) {
    $msg = 'API access denied for cb_id ' . $cb_id;
    watchdog('walter_costbenefit', $msg, NULL, WATCHDOG_WARNING);
  }
  return $has_access;
}

/**
 * Retrieves costbenefit entity for given $cb_id.
 */
function _walter_costbenefit_resource_retrieve($cb_id) {
  if ($entity = costbenefit_load($cb_id)) {
    return $entity;
  }
  return FALSE;
}

/**
 * Creates a new cb_item with given $box num and $title.
 */
function _walter_costbenefit_resource_add_item($cb_id, $title) {
  //@todo: Create cb_item add helper function to use here and in form submit.
  $entity = entity_create('costbenefit_item', array());
  $entity->cb_id = $cb_id;
  $entity->title = $title;
  // Hardcode these values for now.
  $entity->box = 1;
  $entity->type = 1;
  $entity->save();
  return TRUE;
}
