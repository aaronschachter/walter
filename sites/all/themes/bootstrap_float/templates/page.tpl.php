<?php
/**
 * @file
 * page.tpl.php.
 *
 */
global $user;
?>
<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
  <div class="container">
    <div class="navbar-header">
      <?php if ($logo): ?>
      <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>
      <?php endif; ?>

      <?php if (!empty($site_name)): ?>
      <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
      <?php endif; ?>

    </div>


    <?php if (user_is_logged_in()): ?>
      <nav role="navigation">
        <div class="dropdown pull-right">
          <button class="btn dropdown-toggle" type="button" id="user-nav" data-toggle="dropdown">
            <?php print $user->mail; ?>
            <span class="caret"></span>
          </button>
          <ul class="dropdown-menu dropdown-menu-right" role="menu" aria-labelledby="user-nav">
            <li role="presentation"><?php print l('Settings', 'user/' . $user->uid . '/edit'); ?></li>
            <li role="presentation" class="divider"></li>
            <li role="presentation"><?php print l('Log out', 'user/logout'); ?></li>
          </ul>
        </div>
      </nav>

    <?php else: ?>
      <div class="pull-right login-block">
      <?php print render($login_form); ?>
      </div>
    <?php endif; ?>

  </div>
</header>

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
  <div class="navbar-collapse collapse pull-right">
    <nav role="navigation">
      <ul class="menu nav navbar-nav">
        <li><?php print l('About', 'about'); ?></li>
        <li><?php print l('Terms', 'terms'); ?></li>
        <li><?php print l('Privacy', 'privacy'); ?></li>
        <li><?php print l('Contact', 'contact'); ?></li>
      </ul>
    </nav>
  </div>
</footer>
