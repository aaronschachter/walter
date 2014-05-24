<div class="cb-box well">

  <div>
    <h4><?php print _costbenefit_get_box_label($vars['box'], TRUE, $vars['title']) ?>
    <span class="badge"><?php print count($vars['items']); ?></span>
    <button class="btn btn-tertiary pull-right" data-toggle="modal" data-target=".add-item-modal-<?php print $vars['box']; ?>">
      <span class="glyphicon glyphicon-plus"></span>
    </button>
    </h4>
  </div>

  <?php foreach ($vars['items'] as $item): ?>

     <div class="box-item">
      <a class="edit-cb_item-link" data-toggle="modal" data-target=".edit-item-modal-<?php print $item->cb_item_id; ?>">
        <span class="small pull-right"><?php print $item->type_desc; ?></span> <?php print $item->title; ?>
      </a>
      <!-- Edit item modal -->
      <div class="modal fade edit-item-modal-<?php print $item->cb_item_id; ?>" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
        <div class="modal-dialog modal-lg">
          <div class="modal-content">
            <div class="modal-header">
              <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
              <h4 class="modal-title"><?php print $vars['title'];; ?></h4>
            </div>
            <div class="modal-body">
              <p><?php print render($item->form); ?></p>
            </div>
          </div>
        </div>
      </div>
    </div>
  <?php endforeach; ?>



  <!-- Add item modal -->
  <div class="modal fade add-item-modal-<?php print $vars['box']; ?>" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    <div class="modal-dialog modal-lg">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
          <h4 class="modal-title"><?php print $vars['title']; ?></h4>
        </div>
        <div class="modal-body">
          <p><?php print render($add_form); ?></p>
        </div>
      </div>
    </div>
  </div>

</div>
