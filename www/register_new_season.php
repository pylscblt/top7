<?php

	include("common.inc");
	check_session();
	print_header_register();
	init_sql();
	printr_log("register_new_season.php", "_POST", $_POST);
	printr_log("register_new_season.php", "_SESSION", $_SESSION);
	

	if( isset($_SESSION['register_new_season'])) {
		$register_new_season = $_SESSION['register_new_season'];
		if( $register_new_season) {

			if( isset($_POST['team'])) {  # process the form
				$top7team = register_same_top7team($_SESSION, $_POST['team']);
				$_SESSION['register_new_season'] = false;
				$_SESSION['top7team'] = $top7team;
				echo "<script>document.location.replace('team'); </script>";

			} else {  # display the form fully filled

				$top7team = $_SESSION['top7team_to_register'];
				$errors = array();
				$infos = get_email_team($top7team);
				$emails = array();
				$pseudos = array();
				foreach( $infos as  $p) {
					$emails[]  = $p['email'];
					$pseudos[] = $p['pseudo'];
				}
				$team = get_top7team_name( $top7team);
				put_register_form( $team, $pseudos, $emails, $errors, basename(__FILE__, '.php'));
			}
		}
	}
?>
</body>
</html>

