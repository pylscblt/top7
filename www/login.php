<?php

	include("common.inc");


	session_start();
	if( isset( $_POST['token']) and isset( $_SESSION['token']) 
		and !empty($_POST['token']) and !empty($_SESSION['token'])  
		and $_POST['token'] == $_SESSION['token']) { 

		if( isset( $_POST['login']) and isset( $_POST['password'])) {


			if( $_POST['login'] == c_admin_login and $_POST['password'] == c_admin_password) {

				session_start();
				init_sql();
				init_time_session();
				$_SESSION['login'] 		= $_POST['login'];
				$_SESSION['pseudo'] 	= "";
				$_SESSION['mode'] 		= c_admin;
				$_SESSION['display'] 	= c_top14;
				$_SESSION['captain'] 	= "";

				header( 'location: update_day');
			}

			if( $player = check_player( $_POST)) {

				session_start();
				init_time_session();
				$_SESSION['login'] 	= $player['email'];
				$_SESSION['pseudo'] 	= $player['pseudo'];
				$_SESSION['player'] 	= $player['player'];
				$_SESSION['captain'] 	= $player['captain'];
				$_SESSION['top7team'] 	= $player['team'];
				$_SESSION['display'] 	= c_top7;
				$_SESSION['mode'] 		= c_guest;
				$_SESSION['game']       = c_disable;
				$_SESSION['register_new_season'] = 0;

				$status = check_status_player( $_SESSION);
				if( $status['team'] == c_team_waiting) {
					$_SESSION['game']   = c_not_opened;
					header( 'location: team');
				}
				else {

					if( $status['team'] == c_team_enable and $status['player'] == c_player_enable) $game = check_date_player( $_SESSION);

					if( $player['captain'] and $player['season']<$_SESSION['top7_season']) $_SESSION['register_new_season'] = 1;

					$_SESSION['game'] = $game;

					if( $game == c_enable)	{
						$_SESSION['display'] = c_top7_player;
						$_SESSION['mode']    = c_player;
					}
					if( $game == c_season_over)	{
						$_SESSION['display'] = c_top_final;
						$_SESSION['mode']    = c_player;
						$_SESSION['status']  = c_cannot_play;
					}
	#header( 'location: display');
					echo "<script>document.location.replace('display'); </script>";
				}

			}
			else {
				$msg = $_POST['login'] . " est inconnu au bataillon !"; 
	#echo "<script>alert(\"$msg\");</script>\n";
			}

		}
	}

	echo '<meta http-equiv="refresh" content="0;URL=index">';

?>
