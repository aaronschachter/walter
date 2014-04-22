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

  public function getBoxItems($box) {
    $items = array();
    $query = db_select($this->item_table, 'cbi')
      ->fields('cbi', array('cb_item_id', 'title'))
      ->condition('cb_id', $this->cb_id)
      ->condition('box', $box);
    $results = $query->execute();
    foreach($results as $seq => $result) {
      $items[$seq]['cb_item_id'] = $result->cb_item_id;
      $items[$seq]['title'] = $result->title;
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
    $box_items = array();
    // Loop through the boxes.
    for ($i = 1; $i <= 4; $i++) {
      $vars = array(
        'box' => $i,
        'items' => $entity->getBoxItems($i),
        'link' => l('Add Item', 'cb/' . $entity->cb_id . '/' . $i . '/add'),
      );
      $build['box_' . $i] = array(
        '#markup' => theme('costbenefit_box', array('vars' => $vars))
      );
    }
    /*
    $build['doing_header'] = array(
      '#prefix' => '<h2 class="text-center">',
      '#markup' => t('Doing or using'),
      '#suffix' => '</h2>',
    );
    $build['not_doing_header'] = array(
      '#prefix' => '<h2 class="text-center">',
      '#markup' => t('NOT doing or NOT using'),
      '#suffix' => '</h2>',
    );
    */
    return $build;
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

}

