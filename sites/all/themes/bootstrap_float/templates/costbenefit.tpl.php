<?php print l('Edit', 'cb/' . arg(1) . '/edit'); ?>

<h2 class="text-center">Doing</h2>
<div class="row">
  <div class="col-xs-6"><?php print render($content['boxes'][1]); ?></div>
  <div class="col-xs-6"><?php print render($content['boxes'][2]); ?></div>
</div>

<h2 class="text-center">Not doing</h2>
<div class="row">
  <div class="col-xs-6"><?php print render($content['boxes'][3]); ?></div>
  <div class="col-xs-6"><?php print render($content['boxes'][4]); ?></div>
</div>

