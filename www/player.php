<?php

	include("common.inc");
   	check_session();

   	print_header();
	init_sql();

	printr_log(basename(__FILE__),"POST",$_POST);

	if( isset( $_POST['pseudo'])) {
		$pseudo	= $_POST['pseudo'];

		$errors = array();
		$min = c_min_pseudo; $max = c_max_pseudo;
		if( strlen( $pseudo) < $min) 	$errors[] = "Le pseudo doit avoir au minimum $min caractères";
		if( strlen( $pseudo) > $max) 	$errors[] = "Le pseudo doit avoir au maximum $max caractères";

        if( check_new_pseudo( $pseudo)) {
                $errors[] = "Le pseudo <span class=\"warning\">$pseudo</span> est déjà pris."; 
        }

	if( count( $errors)) {
		register_message( $errors);
	}
	else {
           	$player = 0;
	        if( isset( $_POST['player'])) $player = $_POST['player'];
			init_admin_sql();
			update_pseudo_player( $pseudo, $player);
			$player = $_SESSION['player'];
		}
	}

	if( isset( $_POST['email'])) {
       	$player = 0;
		if( isset( $_POST['player'])) $player = $_POST['player'];
		$email	= $_POST['email'];
		init_admin_sql();
		$errors = array();
        	if( check_syntax_email( $email)) {
        		if( check_new_email( $email)) $errors[] = "L'adresse email est déjà prise !";
        	}
        	else $errors[] = "L'adresse email est invalide";

		if( count( $errors)) {
			register_message( $errors);
		}
		else {
			$key            = insert_password_player( $player);
        	$captain        = false;
        	$team           = $_SESSION['top7team'];
        	$pseudo         = get_pseudo_from_player( $player);
			update_email_player( $email, $player);
			send_email_register( $pseudo, $email, $team, $captain, $key);
        	}
    	}


	$player = $_SESSION['player'];
	if( isset( $_POST['player'])) $player = $_POST['player'];



    $old_season = false;
	if( isset( $_POST['season'])) { 
		$season = $_POST['season'];
		if( $season != $_SESSION['top7_season']) {

            $old_season = true;
			$_SESSION['game']    = c_season_over;
			$_SESSION['status']    = c_no_more_selected;
			$_SESSION['display'] = c_top_final;
			$_SESSION['mode']    = c_player;
			$_SESSION['status']  = c_cannot_play;
			$_SESSION['day']     = c_finale_day;
			$_SESSION['season']  = $season;
			$info = get_player_season( $player, $season);
			$_SESSION['player']  	= $info['player_idx'];
			$_SESSION['top7team'] 	= $info['team'];
			$_SESSION['pseudo'] 	= $info['pseudo'];
			$_SESSION['captain'] 	= $info['captain'];
			echo "<script>document.location.replace('display'); </script>";
    			#header( 'location: display');
		}
		else {
			$_SESSION['season']  	= $season;
       		init_time_session();
			$info = get_player_season( $player, $season);
			$_SESSION['player']  	= $info['player_idx'];
			$_SESSION['display'] 	= c_info_player;
		}
	}

    // renvoie email d'inscription
	if( isset( $_POST['status'])) { 
        $player = $_POST['_player'];
        $pseudo = $_POST['_pseudo'];
        $email = $_POST['_email'];
        $team = $_POST['team'];
        $captain = "";
        $key = insert_password_player( $player);
        send_email_register( $pseudo, $email, $team, $captain, $key);
    }




	$info = get_player( $player);
	$_SESSION['player']  	= $info['player_idx'];
	$_SESSION['top7team'] 	= $info['team'];
	$_SESSION['pseudo'] 	= $info['pseudo'];
	$_SESSION['captain'] 	= $info['captain'];
	
	#$_SESSION['display'] = c_info_player;

	// ticket 54
	$game = c_disable;
	$status = check_status_player( $_SESSION);
	if( $status['team'] == c_team_waiting) $game = c_not_opened;
	if( $status['team'] == c_team_enable and $status['player'] == c_player_enable) $game = check_date_player( $_SESSION);
	$_SESSION['game'] 	= $game;
	if( $game == c_enable)	{
		$_SESSION['mode']    = c_player;
		$_SESSION['display'] = c_top7_player;
	}

	if( $_SESSION['season'] != $_SESSION['top7_season']) {
		$_SESSION['status']  = c_cannot_play;
		$_SESSION['game']    = c_season_over;
	}


	init_time_session();

	echo "<center>\n";
	put_player_link( $_SESSION);
	#put_status( $_SESSION);
	put_nav( $_SESSION);
	display_info_player( $player, $_SESSION);
	put_bottom_info( $_SESSION);
	echo "</center>\n";

?>
</body>
</html>
