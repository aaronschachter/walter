<?php 
/*
@todo: Add total counts.  Also breakdown by short term long term.
*/
?>
<div>
<h3>Box <?php print $vars['box']; ?>
  <table>
  <?php foreach ($vars['items'] as $item): ?>
    <tr>
    <td><?php print l($item['title'], 'cb/' . $vars['cb_id'] . '/' . $item['cb_item_id']); ?></td>
    </tr>
  <?php endforeach; ?>
  </table>
  <?php print $vars['link']; ?>
</div>
