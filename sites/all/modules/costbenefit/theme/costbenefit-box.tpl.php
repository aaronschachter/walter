<div>
<h3>Box <?php print $vars['box']; ?>
  <ul>
  <?php foreach ($vars['items'] as $item): ?>
    <li><?php print $item['title']; ?></li>
  <?php endforeach; ?>
  </ul>
  <?php print $vars['link']; ?>
</div>
