<?php

/**
 * @file
 * Provides classes for the Costbenefit Entity.
 */

/**
 * Our Costbenefit entity class.
 */
class CostbenefitEntity extends Entity {

  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'cb/' . $this->identifier());
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
    $build['doing_header'] = array(
      '#prefix' => '<h2 class="text-center">',
      '#markup' => t('Doing or using'),
      '#suffix' => '</h2>',
    );
    $build['doing_matrix'] = array(
      '#markup' => '
<div class="row">
  <div class="col-xs-6 well"><h3 class="text-center">Advantages</h3>
  <ul>
    <li>Stuff</li>
    <li>More stuff</li>
  </ul>
  </div>
  <div class="col-xs-6 well"><h3 class="text-center">Disadvantages</h3></div>
</div>',
    );
    $build['not_doing_header'] = array(
      '#prefix' => '<h2 class="text-center">',
      '#markup' => t('NOT doing or NOT using'),
      '#suffix' => '</h2>',
    );
    $build['not_doing_matrix'] = array(
      '#markup' => '
<div class="row">
  <div class="col-xs-6 well"><h3 class="text-center">Advantages</h3></div>
  <div class="col-xs-6 well"><h3 class="text-center">Disadvantages</h3></div>
</div>',
    );
    return $build;
  }
}
