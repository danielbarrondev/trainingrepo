<?php
// Site taxanalysts, environment dev
$aliases['local'] = array(
  'site' => '',
  'env' => '',
  'root' => '/var/www/html/taxanalysts.dev/docroot',
  'remote-host' => 'staging-7614.prod.hosting.acquia.com',
  'os' => 'Linux',
  'remote-user' => 'taxanalysts',
  'path-aliases' => array(
      '%dump-dir' => '/mnt/files/taxanalystsdev/import',
      '%files' => 'sites/default/files',
    ),
);