<h1 class="page-header"><?php print $title ; ?></h1>
<div class="pull-right"><?php print l('Edit', 'cb/' . arg(1) . '/edit'); ?></div>

<div class="row">
  <div class="col-xs-6"><?php print render($content['boxes'][1]); ?></div>
  <div class="col-xs-6"><?php print render($content['boxes'][2]); ?></div>
</div>

<div class="row">
  <div class="col-xs-6"><?php print render($content['boxes'][3]); ?></div>
  <div class="col-xs-6"><?php print render($content['boxes'][4]); ?></div>
</div>

