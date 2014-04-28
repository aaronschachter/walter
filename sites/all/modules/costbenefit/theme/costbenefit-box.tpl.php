<?php 
/*
@todo: Add total counts.  Also breakdown by short term long term.
*/
?>
<div>
  <table class="table table-striped table-bordered">
    <thead>
      <tr>
      <th colspan="2"><?php print _costbenefit_get_box_type($vars['box']) ?> 
        <a href="/<?php print $vars['link']; ?>" role="button" class="btn btn-default pull-right">+</a></th>
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
