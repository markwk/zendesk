<?php
/**
 * Zendesk configuration form
 */ 
function zendesk_configuration_form() {
 $form['zendesk']['zendesk_conf'] = array(
  '#type' => 'fieldset',
  '#title' => 'general configuration'
 
 );
  $form['zendesk']['zendesk_conf']['zendesk_url'] =  array (
    '#type' => 'textfield',
    '#required' => TRUE,
    '#description' => 'Give the url of your zendesk support page (e.g. http://yourdomain.zendesk.com)',
    '#default_value' => variable_get('zendesk_url', 'http://yourdomain.zendesk.com'),
  );
  $form['zendesk']['zendesk_conf']['zendesk_secret_key'] = array (
    '#type' => 'textfield',
    '#required' => TRUE,
    '#description' => 'insert the zendesk secret key',
    '#default_value' => variable_get('zendesk_secret_key', 'Zendesk secret key'),
    '#suffix' => t('Use the http://www.yourdomain.com/services/zendesk page in your zendesk configuration page. (Go to Account -> Security')
  );
  
  $form['zendesk']['zendesk_api'] = array(
    '#type' => 'fieldset',
    '#required' => TRUE,
    '#title' => 'Zendesk API configuration',
    '#description' => t('Give the credentials of the administrator in order to use api calls. 
    These api calls will be used to synchronize users'),
  );
  
  $form['zendesk']['zendesk_api']['zendesk_api_enable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Synchronize the Drupal users with Zendesk'),
    '#default_value'=> variable_get('zendesk_api_enable', 0),
    '#description' => t('When accounts are created in your drupal site, updated and delete, push these changes to Zendesk'),
  );
      
  $form['zendesk']['zendesk_api']['zendesk_api_group'] = array(
    '#type' => 'textfield',
    '#title' => t('API group'),
    '#default_value' => variable_get('zendesk_api_group', ''),
    '#description' => t('this is simple the subdomain of your zendesk page: if your zendesk is http://subdomain.zendesk.com, then you have to fil in "subdomain"'),
  );
  
  $form['zendesk']['zendesk_api']['zendesk_api_mail'] = array(
    '#type' => 'textfield',
    '#title' => t('mail address of the API user '),
    '#default_value' => variable_get('zendesk_api_mail', ''),
    '#description' => t('This is typically the mail address of the zendesk admin account'),
  );
  
  $form['zendesk']['zendesk_api']['zendesk_api_pass'] = array(
    '#type' => 'password',
    '#title' => t('API password'),
    '#default_value' => variable_get('zendesk_api_pass', ''),
    '#description' => t('This is main zendesk user password'),
  );
    // Role-based visibility settings
  $result = db_query('SELECT rid, name FROM {role} WHERE rid != 1 ORDER BY name');
  $role_options = array();
  foreach ($result as $role) {
    $role_options[$role->rid] = $role->name;
  }
  $form['zendesk']['zendesk_permissions'] = array(
    '#type' => 'fieldset',
    '#description' => t('Restrict access to zendesk based on user roles. These rules will apply for both user synchronization as remote authentication.'),
  );
  $form['zendesk']['zendesk_permissions']['zendesk_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Authenticate only for specific roles'),
    '#default_value' => variable_get('zendesk_roles', array()),
    '#options' => $role_options,
    '#description' => t('Select which roles may be authenticated for zendesk. If you select no roles, all authenticated drupal users will be authenticated for Zendesk.'),
  );
  $form['zendesk']['zendesk_permissions']['zendesk_no_permission_page'] = array(
    '#type' => 'textfield',
    '#title' => t('No permission page'),
    '#default_value' => variable_get('zendesk_no_permission_page', ''),
    '#description' => t('To what pages do you want to redirect user that have no permission to access Zendesk.'),
  );
  
  return system_settings_form($form);
}