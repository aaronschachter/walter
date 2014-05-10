<div class="row">
  <div class="col-xs-6">
    <header role="banner" id="page-header">
      <p class="lead">Walter is an app for building motivation to change.</p>
    </header>
    <div class="jumbotron">
    <ul>
      <li>Enter a substance or habit you want to stop.</li>
      <li>List the pros and cons of DOING and NOT DOING it.</li>
      <li>Keep them in your pocket (because they're on your phone).</li>
    </ul>
  </div>
    <p>
    <p>The Cost-Benefit Analysis is a tool used in <a href="http://smartrecovery.org" target="_blank">SMART Recovery</a>.  It is a method for exploring the short-term vs. long-term benefits associated with 
continuing or discontinuing the behavior.<sup>1</sup></p>
  </div>
  <div class="col-xs-6">
    <div class="">
      <h3>Sound useful? <small>Try it out, it's free.</small></h3>
      <?php print render($register_form); ?>
      <hr>
      <p class="lead text-center">Already have an account?
        <button class="btn" data-toggle="modal" data-target=".login-form-modal">
          Sign in
        </button>
      </p>
    </div>
  </div>
</div>
<div class="front-footer">
  <p class="small"><sup>1</sup>http://www.smartrecovery.org/resources/library/Tools_and_Homework/Facilitators_Handout/CBA.pdf</p>
</div>

<!-- Login form modal -->
<div class="modal fade login-form-modal" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h4 class="modal-title">Sign In</h4>
      </div>
      <div class="modal-body">
        <p><?php print render($login_form); ?></p>
      </div>
    </div>
  </div>
</div>

