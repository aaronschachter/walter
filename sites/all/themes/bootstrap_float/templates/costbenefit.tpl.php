
<span data-toggle="modal" data-target=".edit-title-modal">
   <h1 class="page-header pointer"><?php print $title; ?></h1>
</span>



<div class="row">
  <div class="col-md-6"><?php print render($content['boxes'][1]); ?></div>
  <div class="col-md-6"><?php print render($content['boxes'][2]); ?></div>
</div>

<div class="row">
  <div class="col-md-6"><?php print render($content['boxes'][3]); ?></div>
  <div class="col-md-6"><?php print render($content['boxes'][4]); ?></div>
</div>
<div>



<!-- Edit title modal -->
<div class="modal fade edit-title-modal" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h4 class="modal-title">Edit Costbenefit</h4>
      </div>
      <div class="modal-body">
        <p><?php print render($content['edit_form']); ?></p>
      </div>
    </div>
  </div>
</div>
