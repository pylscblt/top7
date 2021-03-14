<?php


	include("common.inc");
	check_session();

	#echo "<pre>"; print_r($_GET); echo "</pre>";
	#echo "<pre>"; print_r($_POST); echo "</pre>";
	#echo "<pre>"; print_r($_SESSION); echo "</pre>";

	#print_header();

	init_admin_sql();
	update_prono( $_GET);

	header( 'location: update_day');
?>
