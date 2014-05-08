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
  $form['submit'] = _get_costbenefit_form_submit_element('Update');
  return $form;
}

/**
 * Submit callback for costbenefit_form().
 */
function costbenefit_form_submit($form, &$form_state) {
  // If a cb_id exists, load existing entity.
  if (isset($form_state['values']['cb_id'])) {
    $entity = costbenefit_load($form_state['values']['cb_id']);
  }
  // Else create a new entity to save.
  else {
    $entity = entity_create('costbenefit', array());
  }
  $entity->title = $form_state['values']['title'];
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
  $label = 'A ' . _costbenefit_get_box_label($box, FALSE, $cb->title) . ' is:';
  $form['cb_id'] = array(
    '#type' => 'hidden',
    '#value' => $cb->cb_id,
    //'#access' => FALSE,
  );
  $form['box'] = array(
    '#type' => 'hidden',
    '#value' => $box,
    //'#access' => FALSE,
  );
  $form['body'] = array(
    '#type' => 'fieldset',
  );
  $form['body']['title'] = array(
    '#title' => $label,
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['body']['type'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#options' => _costbenefit_get_type_options(),
  );
  $form['submit'] = _get_costbenefit_form_submit_element('Add');
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
  $entity->type = $form_state['values']['type'];
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
    // And this has to be default_value, not value to get the mutiple forms working.
    '#default_value' => $item->cb_item_id,
    // This breaks the whole multiple form thing.
    //'#access' => FALSE,
  );
  $form['title'] = array(
    '#title' => 'A ' . _costbenefit_get_box_label($item->box, FALSE, drupal_get_title()) . ' is:',
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $item->title,
  );
  $form['type'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#options' => _costbenefit_get_type_options(),
    '#default_value' => $item->type,
  );
  $form['submit'] = _get_costbenefit_form_submit_element('Update');
  // $form['footer'] = array(
  //   '#markup' => l('Delete this item', 'cb/' . $item->cb_id . '/' . $item->cb_item_id . '/delete'),
  // );
  return $form;
}

/**
 * Submit callback for costbenefit_item_add_form().
 */
function costbenefit_item_edit_form_submit($form, &$form_state) {
  global $user;
  $cb_item_id = $form_state['values']['cb_item_id'];
  $entity = costbenefit_item_load($cb_item_id);
  $entity->title = $form_state['values']['title'];
  $entity->type = $form_state['values']['type'];
  $entity->save();
  $form_state['redirect'] = 'cb/' . $entity->cb_id;
  drupal_set_message("Item <em>" . $entity->title . "</em> has been updated.");
}

/**
 * Form constructor for a reportback delete form.
 *
 * @param object $entity
 *   The costbenefititem entity to delete.
 *
 * @ingroup forms
 */
function costbenefit_item_delete_form($form, &$form_state, $entity) {
  $form['cb_item_id'] = array(
    '#type' => 'hidden',
    '#value' => $entity->cb_item_id,
    '#access' => FALSE,
  );
  $form['cb_id'] = array(
    '#type' => 'hidden',
    '#value' => $entity->cb_id,
    '#access' => FALSE,
  );
  $form['title'] = array(
    '#type' => 'hidden',
    '#value' => $entity->title,
    '#access' => FALSE,
  );
  $form['warning'] = array(
    '#markup' => t("Are you sure you want to delete this item?  This cannot be undone."),
  );
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Delete'),
    ),
  );
  return $form;
}

/**
 * Submit callback for dosomething_reportback_delete_form().
 */
function costbenefit_item_delete_form_submit($form, &$form_state) {
  $cb_item_id = $form_state['values']['cb_item_id'];
  entity_delete('costbenefit_item', $cb_item_id);
  $form_state['redirect'] = 'cb/' . $form_state['values']['cb_id'];
  drupal_set_message("Item " . $form_state['values']['title'] . " deleted.");
}

function _get_costbenefit_form_submit_element($label) {
  return array(
    '#type' => 'submit',
    '#value' => $label,
    '#prefix' => '<div class="modal-footer"><button type="button" class="btn btn-default" data-dismiss="modal">Cancel</button>',
    '#suffix' => '</div>'
  );
}
