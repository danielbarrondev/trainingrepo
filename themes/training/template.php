<?php

/**
 * Sobreescribe o inserta vaiables en un template tipo html
 */
function training_preprocess_html(&$variables) {
  drupal_add_css(path_to_theme() . '/css/ie6.css', array('group' => CSS_THEME, 
      'browsers' => array('IE' => 'IE 6', '!IE' => FALSE), 
      'preprocess' => FALSE));
}

/**
 * Sobreescribe o inserta vaiables en un template page
 */
function training_preprocess_page(&$variables) {
  if (isset($variables['node']) && $variables['node']->type == 'news') {
  	$variables['my_variable_en_page'] = t('Mi variable personalizada');
    $variables['theme_hook_suggestions'][] = 'page__news';
  } // end if
}

/**
 * Sobreescribe o inserta vaiables en un template tipo nodo
 */
function training_preprocess_node(&$variables) {
}