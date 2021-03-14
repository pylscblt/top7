<?php


	include("common.inc");
	check_session();

	init_admin_sql();
	update_forum( $_POST, $_SESSION);
	send_email_forum( $_POST, $_SESSION);

	header( 'location: display');
?>
