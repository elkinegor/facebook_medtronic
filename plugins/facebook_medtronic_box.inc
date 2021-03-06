<?php

/**
 * Boxes plugin for the Facebook Pull module.
 */
class facebook_medtronic_box extends boxes_box {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return array(
      'app_id' => variable_get('facebook_medtronic_app_id', ''),
      'app_secret' => variable_get('facebook_medtronic_app_secret', ''),
      'graph_id_en' => variable_get('facebook_medtronic_graph_id_en', ''),
			'graph_id_th' => variable_get('facebook_medtronic_graph_id_th', ''),
      'object_type' => variable_get('facebook_medtronic_object_type', ''),
      'limit' => variable_get('facebook_medtronic_limit', ''),
    );
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state) {
    $form = array();

    $application_id = l(t('Application ID'), 'https://developers.facebook.com/apps');
    $form['app_id'] = array(
      '#type' => 'textfield',
      '#title' => t('App ID'),
      '#default_value' => $this->options['app_id'],
      '#description' => t('Unique !application_id for your facebook app.', array('!application_id' => $application_id)),
    );

    $form['app_secret'] = array(
      '#type' => 'textfield',
      '#title' => t('App Secret'),
      '#default_value' => $this->options['app_secret'],
      '#description' => t('Your sites app secret.'),
    );

    $graph_link = l(t('Graph ID'), 'http://developers.facebook.com/docs/reference/api/');
    $form['graph_id_en'] = array(
      '#type' => 'textfield',
      '#title' => t('Graph ID'),
      '#default_value' => $this->options['graph_id_en'],
      '#description' => t('The !graph_id for EN', array('!graph_id' => $graph_link)),
    );
		 $form['graph_id_th'] = array(
      '#type' => 'textfield',
      '#title' => t('Graph ID'),
      '#default_value' => $this->options['graph_id_th'],
      '#description' => t('The !graph_id for TH', array('!graph_id' => $graph_link)),
    );

    $form['object_type'] = array(
      '#type' => 'textfield',
      '#title' => t('Object type'),
      '#default_value' => $this->options['object_type'],
      '#description' => t('The object type to pull, e.g. friends, feed, photos.'),
    );

    $form['limit'] = array(
      '#type' => 'textfield',
      '#title' => t('Limit'),
      '#size' => 5,
      '#default_value' => $this->options['limit'],
      '#description' => t('How many posts to show in the box by default. If you have not entered a default limit here then it will default to 10.'),
    );

    return $form;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function render() {
    $content = facebook_medtronic_render($this->options['graph_id'],
      $this->options['object_type'],
      $this->options['app_id'],
      $this->options['app_secret'],
      array('limit' => $this->options['limit']));

    $title = isset($this->title) ? check_plain($this->title) : NULL;

    return array(
      'delta' => $this->delta,
      'title' => $title,
      'subject' => $title,
      'content' => $content,
    );
  }
}
