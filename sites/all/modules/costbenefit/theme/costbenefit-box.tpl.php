<?php 
/*
@todo: Add total counts.  Also breakdown by short term long term.
*/
?>
<div>
  <table class="views-table">
    <thead>
      <tr>
      <th><?php print _costbenefit_get_box_type($vars['box']) ?> <?php print $vars['link']; ?></th>
      <th>Type</th>
      </tr>
    </thead>
    <tbody>
    <?php foreach ($vars['items'] as $item): ?>
      <tr>
        <td><?php print l($item->title, 'cb/' . $vars['cb_id'] . '/' . $item->cb_item_id); ?></td>
        <td><?php print $item->type_desc; ?></td>
      </tr>
    <?php endforeach; ?>
    <tr><td></td><td>  </td></tr>
    </tbody>
  </table>
</div>
