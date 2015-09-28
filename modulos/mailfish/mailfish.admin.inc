<?php
/**
* @file 
* Este archivo contiene la logica de administracion
*/

/**
* Formulario de administracion
*/
function mailfish_admin_settings_form() {
  $form = array();
  $form['mailfish_check_form_api'] = array(
  	'#title' => t('El tipo de contenido para habilitar subscripciones'),
  	'#description' => t('En los tipos de nodos especificados una subscripcion de mailfish estara disponible'),
  	'#type' => 'checkboxes',
  	'#options' => node_type_get_names(),
  	'#default_value' => variable_get('mailfish_check_form_api', array())
  );

  return system_settings_form($form);
}

/**
* Reportes de mailfish
*/
function mailfish_signups() {
    $query = db_select('mailfish', 'm');
    $query->innerJoin('node', 'n', 'n.nid = m.nid');
    $query->fields('m', array('uid', 'nid', 'mail', 'created'));
    $query->fields('n', array('title'));
    $query->orderBy('m.created', 'ASC');
    $results = $query->execute()->fetchAll();
    watchdog('mailfish_signups', '%query', 
   	array('%query' => print_r($results, TRUE)), WATCHDOG_DEBUG);                        
    
    $rows = array();
    $header = array('Account', 'Title', 'Mail', 'Date');
    foreach($results as $value) {
      $account = $value->uid ? user_load($value->uid) : '';
      $rows[] = array(
      	$value->uid ? $account->name : '',
      	$value->nid ? l($value->title, 'node/' . $value->nid) : '',
      	$value->mail,
      	date('F j, Y g:i A', $value->created),
      );
    } // end foreach
    $output = array(
		  'introduction' 	=> array(
			   '#type' 	=> 'markup',
			   '#markup'	=> '<p>La tabla muestra la informacion de los usuarios suscritos usando el formulario de Mailfish.</p>'
		    ),
		       'table'  => array(
			   '#theme'	=>	'table',
			   '#header'=> $header,
			   '#rows'	=>	$rows,
			   '#attributes' => array( 'id' => 'permissions' )
		    )
	  );
    return $output;
    //return theme('table', array('header' => $header, 'rows' => $rows));
}