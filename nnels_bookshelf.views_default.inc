<?php
       
/**
* Implements hook_views_default_views().
**/

function nnels_bookshelf_views_default_views() {
  //Finds all files that match a given mask in a given directory
  //In our case, looks for any files named *.view in the /views directory
  $files = file_scan_directory(drupal_get_path('module', 'nnels_bookshelf'). '/views', '/\.view/');
  
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  
  //Check that there are views in the directory
  //This keeps the site from throwing errors if there are no views to return
  if ($views) {
    return $views;
  }
}

function nnels_bookshelf_views_default_views_alter( &$views ) {
    
    /*if (array_key_exists('nnels_bookshelf_user_dashboard', $views)) {
      dpm($views['nnels_bookshelf_user_dashboard']);
    }*/

    if (array_key_exists('field_collection_view_repo_files_admin_report', $views)) {
      //dpm($views['field_collection_view_repo_files_admin_report']);

      /* Display: Embed - Detail - Bookshelf */
      $view = $views['field_collection_view_repo_files_admin_report'];
      dpm($view);

      $handler = $view->new_display('embed', 'Embed - Detail - Bookshelf', 'embed_7');
      $handler->display->display_options['defaults']['css_class'] = FALSE;
      $handler->display->display_options['css_class'] = 'repo-item available-formats';
      $handler->display->display_options['defaults']['access'] = FALSE;
      $handler->display->display_options['access']['type'] = 'role';
      $handler->display->display_options['access']['role'] = array(
        2 => '2',
      );
      $handler->display->display_options['defaults']['style_plugin'] = FALSE;
      $handler->display->display_options['style_plugin'] = 'list';
      $handler->display->display_options['style_options']['class'] = 'view-list-ul';
      $handler->display->display_options['style_options']['wrapper_class'] = 'view-list';
      $handler->display->display_options['defaults']['style_options'] = FALSE;
      $handler->display->display_options['defaults']['row_plugin'] = FALSE;
      $handler->display->display_options['row_plugin'] = 'fields';
      $handler->display->display_options['row_options']['inline'] = array(
        'field_file_format' => 'field_file_format',
      );
      $handler->display->display_options['defaults']['row_options'] = FALSE;
      $handler->display->display_options['defaults']['header'] = FALSE;
      $handler->display->display_options['defaults']['footer'] = FALSE;
      $handler->display->display_options['defaults']['empty'] = FALSE;
      $handler->display->display_options['defaults']['fields'] = FALSE;
      /* Field: Field: S3 Path */
      $handler->display->display_options['fields']['field_s3_path']['id'] = 'field_s3_path';
      $handler->display->display_options['fields']['field_s3_path']['table'] = 'field_data_field_s3_path';
      $handler->display->display_options['fields']['field_s3_path']['field'] = 'field_s3_path';
      $handler->display->display_options['fields']['field_s3_path']['label'] = '';
      $handler->display->display_options['fields']['field_s3_path']['exclude'] = TRUE;
      $handler->display->display_options['fields']['field_s3_path']['element_label_colon'] = FALSE;
      $handler->display->display_options['fields']['field_s3_path']['type'] = 'text_plain';
      /* Field: Field: File Format */
      $handler->display->display_options['fields']['field_file_format']['id'] = 'field_file_format';
      $handler->display->display_options['fields']['field_file_format']['table'] = 'field_data_field_file_format';
      $handler->display->display_options['fields']['field_file_format']['field'] = 'field_file_format';
      $handler->display->display_options['fields']['field_file_format']['label'] = '';
      $handler->display->display_options['fields']['field_file_format']['alter']['trim_whitespace'] = TRUE;
      $handler->display->display_options['fields']['field_file_format']['alter']['strip_tags'] = TRUE;
      $handler->display->display_options['fields']['field_file_format']['element_label_colon'] = FALSE;
      $handler->display->display_options['fields']['field_file_format']['element_default_classes'] = FALSE;
      $handler->display->display_options['fields']['field_file_format']['delta_offset'] = '0';
      /* Field: Content: Access Restrictions */
      $handler->display->display_options['fields']['field_access_restrictions']['id'] = 'field_access_restrictions';
      $handler->display->display_options['fields']['field_access_restrictions']['table'] = 'field_data_field_access_restrictions';
      $handler->display->display_options['fields']['field_access_restrictions']['field'] = 'field_access_restrictions';
      $handler->display->display_options['fields']['field_access_restrictions']['relationship'] = 'field_file_resource_node';
      $handler->display->display_options['fields']['field_access_restrictions']['label'] = 'ACCESS';
      $handler->display->display_options['fields']['field_access_restrictions']['exclude'] = TRUE;
      $handler->display->display_options['fields']['field_access_restrictions']['element_label_colon'] = FALSE;
      $handler->display->display_options['fields']['field_access_restrictions']['type'] = 'list_key';
      /* Field: Field collection item: Field collection item ID */
      $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
      $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
      $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
      $handler->display->display_options['fields']['item_id']['label'] = 'TMP';
      $handler->display->display_options['fields']['item_id']['exclude'] = TRUE;
      $handler->display->display_options['fields']['item_id']['hide_alter_empty'] = FALSE;
      $handler->display->display_options['fields']['item_id']['separator'] = '';
      /* Field: Field collection item: Field path */
      $handler->display->display_options['fields']['field_path']['id'] = 'field_path';
      $handler->display->display_options['fields']['field_path']['table'] = 'field_collection_item';
      $handler->display->display_options['fields']['field_path']['field'] = 'field_path';
      $handler->display->display_options['fields']['field_path']['label'] = '';
      $handler->display->display_options['fields']['field_path']['exclude'] = TRUE;
      $handler->display->display_options['fields']['field_path']['element_label_colon'] = FALSE;
      $handler->display->display_options['fields']['field_path']['hide_alter_empty'] = FALSE;
      /* Field: Field collection item: Host Entity ID */
      $handler->display->display_options['fields']['host_entity_id']['id'] = 'host_entity_id';
      $handler->display->display_options['fields']['host_entity_id']['table'] = 'field_collection_item';
      $handler->display->display_options['fields']['host_entity_id']['field'] = 'host_entity_id';
      $handler->display->display_options['fields']['host_entity_id']['label'] = '';
      $handler->display->display_options['fields']['host_entity_id']['exclude'] = TRUE;
      $handler->display->display_options['fields']['host_entity_id']['element_label_colon'] = FALSE;
      $handler->display->display_options['fields']['host_entity_id']['hide_alter_empty'] = FALSE;
      /* Field: File: File ID */
      $handler->display->display_options['fields']['fid']['id'] = 'fid';
      $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
      $handler->display->display_options['fields']['fid']['field'] = 'fid';
      $handler->display->display_options['fields']['fid']['relationship'] = 'field_s3_file_upload_fid';
      $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
      /* Field: Field collection item: Host Entity Path */
      $handler->display->display_options['fields']['host_entity_path']['id'] = 'host_entity_path';
      $handler->display->display_options['fields']['host_entity_path']['table'] = 'field_collection_item';
      $handler->display->display_options['fields']['host_entity_path']['field'] = 'host_entity_path';
      $handler->display->display_options['fields']['host_entity_path']['label'] = '';
      $handler->display->display_options['fields']['host_entity_path']['exclude'] = TRUE;
      $handler->display->display_options['fields']['host_entity_path']['element_label_colon'] = FALSE;
      $handler->display->display_options['fields']['host_entity_path']['hide_alter_empty'] = FALSE;
      /* Field: Field collection item: Host Entity Type */
      $handler->display->display_options['fields']['host_entity_type']['id'] = 'host_entity_type';
      $handler->display->display_options['fields']['host_entity_type']['table'] = 'field_collection_item';
      $handler->display->display_options['fields']['host_entity_type']['field'] = 'host_entity_type';
      $handler->display->display_options['fields']['host_entity_type']['label'] = '';
      $handler->display->display_options['fields']['host_entity_type']['exclude'] = TRUE;
      $handler->display->display_options['fields']['host_entity_type']['element_label_colon'] = FALSE;
      $handler->display->display_options['fields']['host_entity_type']['hide_alter_empty'] = FALSE;
      $handler->display->display_options['defaults']['arguments'] = FALSE;
      /* Contextual filter: Content: Nid */
      $handler->display->display_options['arguments']['nid']['id'] = 'nid';
      $handler->display->display_options['arguments']['nid']['table'] = 'node';
      $handler->display->display_options['arguments']['nid']['field'] = 'nid';
      $handler->display->display_options['arguments']['nid']['relationship'] = 'field_file_resource_node';
      $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
      $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
      $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
      $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
      $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
      $handler->display->display_options['defaults']['filter_groups'] = FALSE;
      $handler->display->display_options['defaults']['filters'] = FALSE;
      /* Filter criterion: Field collection item: Field collection item ID */
      $handler->display->display_options['filters']['item_id']['id'] = 'item_id';
      $handler->display->display_options['filters']['item_id']['table'] = 'field_collection_item';
      $handler->display->display_options['filters']['item_id']['field'] = 'item_id';
      $handler->display->display_options['filters']['item_id']['operator'] = 'not empty';
      /* Filter criterion: Field collection item: Availability / Status (field_availability_status) */
      $handler->display->display_options['filters']['field_availability_status_value']['id'] = 'field_availability_status_value';
      $handler->display->display_options['filters']['field_availability_status_value']['table'] = 'field_data_field_availability_status';
      $handler->display->display_options['filters']['field_availability_status_value']['field'] = 'field_availability_status_value';
      $handler->display->display_options['filters']['field_availability_status_value']['operator'] = 'and';
      $handler->display->display_options['filters']['field_availability_status_value']['value'] = array(
        1 => '1',
      );
    }
}
