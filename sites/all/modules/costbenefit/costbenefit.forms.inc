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
