<?php
/**
 * @file
 * walter_costbenefit.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function walter_costbenefit_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'drupalapi';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api/v1';
  $endpoint->authentication = array(
    'services' => 'services',
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'xml' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/xml' => TRUE,
      'multipart/form-data' => TRUE,
      'text/xml' => TRUE,
      'application/vnd.php.serialized' => FALSE,
      'application/x-www-form-urlencoded' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'entity_costbenefit' => array(
      'alias' => 'costbenefit',
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'entity_costbenefit_item' => array(
      'alias' => 'costbenefit_item',
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'node' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'system' => array(
      'actions' => array(
        'connect' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
        'logout' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['drupalapi'] = $endpoint;

  return $export;
}
