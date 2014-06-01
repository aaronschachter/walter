<?php

/**
 * @file
 * Hooks provided by Services for the definition of new services.
 */

function _walter_costbenefit_resource_access() {
  return TRUE;
}

/**
 * Retrieves costbenefit data for given $uid.
 */
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
