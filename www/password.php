<?php

	include("common.inc");

	init_sql();
	$email 	= 0;
	if( isset( $_POST['email'])) 	$email = $_POST['email'];
	if( $email) {
#printr( $_POST);
		check_session();
		print_header_password();
		if( $player = get_player_from_email( $email)) {
			init_admin_sql();
			if( init_password_pending( $player)) password_in_progress();
			else password_instruction( $email);

		}
		else {
			password_email_not_found();
		}

	}
	else {
		session_start();
		print_header_password();
		$action = "password";
		put_password_form( $action);
		$_SESSION['login'] 	= "?";
	}

?>
