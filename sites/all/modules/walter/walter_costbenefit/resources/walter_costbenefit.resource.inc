<?php

/**
 * @file
 * Hooks provided by Services for the definition of new services.
 */

function _walter_costbenefit_resource_access() {
  return TRUE;
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
