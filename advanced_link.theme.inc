<?php

function theme_advanced_link($vars){
	$url = ltrim($vars['url'], '/');
	$label = $vars['label'];
	$is_html = $vars['html'];
	$target = $vars['target'];
	$type = $vars['type'];
	$privacy = $vars['privacy'];

	$attributes = array();

	switch($type){
		case ADVANCED_LINK_TYPE_LOCAL_LINK:
			$class = 'local-link';
			break;

		case ADVANCED_LINK_TYPE_EXTERNAL_LINK:
			$class = 'external-link';
			break;

		case ADVANCED_LINK_TYPE_PDF_DOC:
			$class = 'pdf-link';
			break;

		case ADVANCED_LINK_TYPE_WORD_DOC:
			$class = 'word-link';
			break;

		case ADVANCED_LINK_TYPE_EXCEL_DOC:
			$class = 'excel-link';
			break;

		case ADVANCED_LINK_TYPE_PPT_DOC:
			$class = 'ppt-link';
			break;

		default:
			$class = 'link';
	}
	if($class){
		$attributes['class'][] = $class.($is_html ? '-html' : '');
	}

	switch($target){
		case ADVANCED_LINK_TARGET_SELF:
		default:
			$target = '';
			break;

		case ADVANCED_LINK_TARGET_BLANK:
			$target = '_blank';
			break;
	}
	if($target){
		$attributes['target'] = $target;
	}

	return l($label, $url, array('attributes' => $attributes, 'html' => $is_html));
}

function theme_advanced_link_blocked($vars){
	$label = $vars['label'];
	$is_html = $vars['html'];
	$type = $vars['type'];

	$title = $type & ADVANCED_LINK_TYPE_LINK ? t('Private link') : t('Private document');

	return $is_html ? $label : '<span class="blocked-link" title="'.$title.'">'.$label.'</span>';
}