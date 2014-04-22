<?php

/**
 * @file
 * Provides form functions for the Costbenefit module.
 */

/**
 * Form constructor for Costbenefit entity add/edit.
 */
function costbenefit_form($form, &$form_state, $entity = NULL) {
  $label = t('Create');
  if ($entity) {
    $form['cb_id'] = array(
      '#type' => 'hidden',
      '#value' => $entity->cb_id,
      '#access' => FALSE,
    );
    $label = t('Update');
  }
  $form['title'] = array(
    '#title' => t('The substance or activity to consider is:'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => isset($entity->title) ? $entity->title : NULL,
  );
  // Provide a submit button.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $label,
  );
  return $form;
}

/**
 * Submit callback for costbenefit_form().
 */
function costbenefit_form_submit($form, &$form_state) {
  global $user;
  $values = array(
    'title' => $form_state['values']['title'],
    'uid' => $user->uid,
  );
  if (isset($form_state['values']['cb_id'])) {
    $entity = costbenefit_load($form_state['values']['cb_id']);
    $entity->title = $form_state['values']['title'];
  }
  else {
    $entity = entity_create('costbenefit', $values);    
  }
  $entity->save();
  $form_state['redirect'] = 'cb/' . $entity->cb_id;
}

/**
 * Form constructor for Costbenefit Item entity add.
 *
 * @param object $cb
 *   The cost-benefit entity to add a cb-item to.
 * @param int $box
 *   The box number the cb-item belongs to.
 */
function costbenefit_item_add_form($form, &$form_state, $cb, $box) {
  $form['cb_id'] = array(
    '#type' => 'hidden',
    '#value' => $cb->cb_id,
    '#access' => FALSE,
  );
  $form['box'] = array(
    '#type' => 'hidden',
    '#value' => $box,
  );
  $form['header'] = array(
    '#markup' => 'Box ' . $box,
  );
  $form['title'] = array(
    '#title' => t('Title:'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Add Item',
  );
  return $form;
}

/**
 * Submit callback for costbenefit_item_add_form().
 */
function costbenefit_item_add_form_submit($form, &$form_state) {
  global $user;
  $entity = entity_create('costbenefit_item', array());
  $entity->cb_id = $form_state['values']['cb_id'];  
  $entity->box = $form_state['values']['box'];
  $entity->title = $form_state['values']['title'];
  $entity->save();
  $form_state['redirect'] = 'cb/' . $entity->cb_id;
}


/**
 * Form constructor for Costbenefit Item entity edit.
 *
 * @param object $item
 *   The cost-benefit entity the cb-item belongs to.
 */
function costbenefit_item_edit_form($form, &$form_state, $item) {
  $form['cb_item_id'] = array(
    '#type' => 'hidden',
    '#value' => $item->cb_item_id,
    '#access' => FALSE,
  );
  $form['header'] = array(
    '#markup' => 'Box ' . $item->box,
  );
  $form['title'] = array(
    '#title' => t('Title:'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $item->title,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Update Item',
  );
  return $form;
}

/**
 * Submit callback for costbenefit_item_add_form().
 */
function costbenefit_item_edit_form_submit($form, &$form_state) {
  global $user;
  $entity = costbenefit_item_load($form_state['values']['cb_item_id']); 
  //$entity->box = $form_state['values']['box'];
  $entity->title = $form_state['values']['title'];
  $entity->save();
  $form_state['redirect'] = 'cb/' . $entity->cb_id;
}
