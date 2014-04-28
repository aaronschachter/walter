<?php

/**
 * @file
 * Provides classes for the Costbenefit Entity.
 */

/**
 * Our Costbenefit entity class.
 */
class CostbenefitEntity extends Entity {
  protected $item_table = 'costbenefit_item';

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'cb/' . $this->identifier());
  }

  /**
   * Returns array of costbenefit_item objects for entity's given $box.
   */
  public function getBoxItems($box) {
    $items = array();
    $query = db_select($this->item_table, 'cbi')
      ->fields('cbi')
      ->condition('cb_id', $this->cb_id)
      ->condition('box', $box);
    $result = $query->execute()->fetchAll();
    foreach ($result as $delta => $record) {
      $items[$delta] = $record;
      $items[$delta]->type_desc = $record->type ? 'Long term' : 'Short term';
    }
    return $items;
  }
}

/**
 * Our custom controller for the Costbenefit entity.
 */
class CostbenefitEntityController extends EntityAPIController {

  /**
   * Overrides buildContent() method.
   *
   * Adds Costbenefit properties and items into the content array.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);
    $boxes = array();
    // Loop through the boxes.
    for ($i = 1; $i <= 4; $i++) {
      $vars = array(
        'cb_id' => $entity->cb_id,
        'box' => $i,
        'items' => $entity->getBoxItems($i),
        'link' => l('Add Item', 'cb/' . $entity->cb_id . '/' . $i . '/add'),
      );
      $boxes[$i] = theme('costbenefit_box', array('vars' => $vars));
    }
    $build['doing'] = array(
      '#prefix' => '<h2 class="text-center">Doing or using</h2>',
      '#markup' => '
        <div class="admin clearfix">
          <div class="left clearfix">' . $boxes[1] . '</div>
          <div class="right clearfix">' . $boxes[2] . '</div>
        </div>',
    );
    return $build;
  }

  /**
   * Overrides save() method.
   *
   * Populates created and uid automatically.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    global $user;
    $now = REQUEST_TIME;
    if (isset($entity->is_new)) {
      $entity->created = $now;
      $entity->uid = $user->uid;
    }
    $entity->updated = $now;
    parent::save($entity, $transaction);
  }
}


/**
 * Our Costbenefit Item entity class.
 */
class CostbenefitItemEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'cb-item/' . $this->identifier());
  }
}

/**
 * Our custom controller for the Costbenefit entity.
 */
class CostbenefitItemEntityController extends EntityAPIController {

  /**
   * Overrides save() method.
   *
   * Sets parent costbenefit updated property.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
    // Load the parent costbenefit.
    $costbenefit = costbenefit_load($entity->cb_id);
    // Save to update the timestamp.
    $costbenefit->save();
  }
}

