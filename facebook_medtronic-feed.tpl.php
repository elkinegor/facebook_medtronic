<ul class="facebook-feed">
	<?php 
  $i=0;
  foreach ($items as $item): 
		$i++;
		?>
    <li class="item">
    <a href="<?php print $item->picture; ?>" rel="prettyPhoto[gallery1]" title="<br /> <a target=&quot;_blank&quot; href=&quot;<?php print $item->link; ?>&quot;>See post </a>"><i style="background-image: url(<?php print $item->picture; ?>);"></i></a>
    </li>
		<?php if ($i == variable_get('facebook_medtronic_limit', 9)) { break; }
  endforeach; ?>
</ul>
<?php echo l(t('See more'), 'https://www.facebook.com/'.$feed_id.'/photos/', array('html' => true, 'attributes' => array('target' => '_blank','class' => 'see_more'))); ?>