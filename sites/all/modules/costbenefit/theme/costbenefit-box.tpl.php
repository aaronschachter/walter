<?php
/*
@todo: Add total counts.  Also breakdown by short term long term.
*/
?>
<div>
  <table class="table table-striped table-bordered">
    <thead>
      <tr>
      <th colspan="2">
        <?php print _costbenefit_get_box_type($vars['box']) ?>
        <span class="badge"><?php print count($vars['items']); ?></span>
        <?php print l('+', $vars['link'], array('attributes' => array('class' => array('btn btn-default pull-right')))); ?>
      </tr>
    </thead>
    <tbody>
    <?php foreach ($vars['items'] as $item): ?>
      <tr>
        <td><?php print l($item->title, 'cb/' . $vars['cb_id'] . '/' . $item->cb_item_id); ?></td>
        <td><?php print $item->type_desc; ?></td>
      </tr>
    <?php endforeach; ?>
    </tbody>
  </table>
</div>
