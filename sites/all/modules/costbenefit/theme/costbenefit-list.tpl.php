<div>

  <button class="btn btn-tertiary pull-right" data-toggle="modal" data-target=".add-cb-modal">
    <span class="glyphicon glyphicon-plus"></span>
  </button>

  <?php print $list; ?>

</div>

<!-- Add costbenefit modal -->
<div class="modal fade add-cb-modal" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h4 class="modal-title">Add new Costbenefit</h4>
      </div>
      <div class="modal-body">
        <p><?php print render($add_form); ?></p>
      </div>
    </div>
  </div>
</div>
