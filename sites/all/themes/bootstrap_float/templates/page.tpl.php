<?php
/**
 * @file
 * page.tpl.php.
 *
 */
global $user;
?>

<nav class="navbar navbar-default" role="navigation" class="<?php print $navbar_classes; ?>">
  <div class="container">
    <!-- Brand and toggle get grouped for better mobile display -->
    <div class="navbar-header">
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
      <a class="navbar-brand" href="<?php print $front_page; ?>">Walter</a>
    </div>

    <!-- Collect the nav links, forms, and other content for toggling -->
    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">

      <?php if (user_is_logged_in()): ?>
      <ul class="nav navbar-nav navbar-right">
        <li class="dropdown">
          <a href="#" class="dropdown-toggle" data-toggle="dropdown"><?php print $user->mail; ?> <b class="caret"></b></a>
          <ul class="dropdown-menu">
            <?php foreach ($costbenefit_list as $item): ?>
              <li><?php print $item; ?></li>
            <?php endforeach; ?>
            <li><?php print l(' + New CBA', 'cb/add', array('html' => TRUE)); ?></li>
            <li class="divider"></li>
            <li role="presentation" class="dropdown-header">My account</li>
            <li><?php print l('Settings', 'user/' . $user->uid . '/edit'); ?></li>
            <li><?php print l('Log out', 'user/logout'); ?></li>
          </ul>
        </li>
      </ul>
      <?php else: ?>
      <div class="navbar-right">
        <?php print render($login_form); ?>
      </div>
      <?php endif; ?>
    </div><!-- /.navbar-collapse -->
  </div><!-- /.container-fluid -->
</nav>

<div class="main-container container">

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <a id="main-content"></a>
      <?php if (!empty($title) && $show_title): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print $messages; ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
<footer class="footer container">
  <nav role="navigation">
    <ul class="menu nav navbar-nav navbar-right">
      <li><?php print l('About', 'about'); ?></li>
      <li><?php print l('Terms', 'terms'); ?></li>
      <li><?php print l('Privacy', 'privacy'); ?></li>
    </ul>
  </nav>
</footer>
