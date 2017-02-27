<?php

/**
 * @file
 * Rules module integration for the smsframework.
 */

/**
 * Implements hook_rules_event_info().
 */
function sms_ejtone_rules_event_info() {
  return array(
    'sms_ejtone_balance_alert' => array(
      'label' => t('The account balance threadhold reached.'),
      'access callback' => 'sms_ejtone_rules_access_callback',
      'module' => 'sms_ejtone',
      'group' => t('SMS'),
      'variables' => array(
        'balance_count' => array(
          'label' => t('Remaining balance count.'),
          'description' => t('The SMS account balance count for now.'),
          'type' => 'integer',
        ),
      ),
    ),
    'sms_ejtone_balance_check_failed' => array(
        'label' => t('The account balance check request failed.'),
        'access callback' => 'sms_ejtone_rules_access_callback',
        'module' => 'sms_ejtone',
        'group' => t('SMS'),
        'variables' => array(
            'response_str' => array(
                'label' => t('The balance check response string.'),
                'description' => t('The balance check response string.'),
                'type' => 'string',
            ),
        ),
    ),
  );
}

/**
 * Access callback for the SMS Rules integration.
 *
 * @param string $type
 *  The access type.
 *
 * @return bool
 *  true if the user has access, false if not.
 */
function sms_ejtone_rules_access_callback($type) {
  return user_access('administer smsframework');
}