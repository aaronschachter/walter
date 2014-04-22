<div>
<h3>Box <?php print $vars['box']; ?>
  <ul>
  <?php foreach ($vars['items'] as $item): ?>
    <li><?php print l($item['title'], 'cb/' . $vars['cb_id'] . '/' . $item['cb_item_id']); ?></li>
  <?php endforeach; ?>
  </ul>
  <?php print $vars['link']; ?>
</div>
