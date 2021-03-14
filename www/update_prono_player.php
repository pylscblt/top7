<?php


	include("common.inc");
	check_session();

#printr($_GET); 
#printr($_POST); 
#printr($_SESSION); 

	init_admin_sql();
	$_SESSION['team'] = $_SESSION['selected_team'];
	if( update_prono( $_SESSION)) {
		$day = $_SESSION['day'];
		if( $day > c_last_day) {
			send_email_alert_player( $_SESSION);
		}
		else {
		
			$game = check_date_player( $_SESSION);
			$player = $_SESSION['next_player_to_play'];
			if( $player) send_email_next_player( $_SESSION, $player);
			else send_email_game_is_closed( $_SESSION);
		}
		$_SESSION['display'] = c_top7;
		$_SESSION['mode'] = c_guest;
		$_SESSION['game'] = c_validated;

	}
	unset( $_SESSION['selected_team']);
	header( 'location: display');

?>
