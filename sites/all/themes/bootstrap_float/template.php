<?php

/**
 * @file
 * template.php
 */
function bootstrap_float_preprocess_page(&$variables) {
  $variables['show_title'] = TRUE;
  if (arg(0) == 'cb') {
    $variables['show_title'] = FALSE;
  }
}
