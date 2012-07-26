<?php

/**
 * Method: javascript
 */
function ga_push_method_javascript($push, $type) {

  //TODO: switch

  $push_info = array(
    'push' => $push,
    'type' => $type,
  );
  $_SESSION['ga_push'][] = $push_info;
  
}