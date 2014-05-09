<header role="banner" id="page-header">
  <p class="lead">Walter is an app for creating and storing a Cost Benefit Analysis.</p>
</header> <!-- /#page-header -->

<?php 
/*
<div class="highlighted jumbotron">
  <p class="lead">Lorem ipsum</p>
  <div>Lorem ipsum dolor and things and then what else.</div>
</div>
*/
?>

<div class="row">
  <div class="col-xs-6">
    <div class="well">
      <ul>
        <li>Enter a substance or habit you want to stop.</li>
        <li>List the pros and cons of DOING and NOT DOING it.</li>
        <li>Keep them in your pocket.</li>
      </ul>
    </div>
  </div>
  <div class="col-xs-6">
    <h3>Login</h3>
    <?php print render(drupal_get_form('user_login_block')); ?>
  </div>
</div>
