<?php

	include("common.inc");
	check_session();
	print_header_register();
	init_sql();
#echo "<pre>"; print_r( $_SESSION); echo "</pre>";

	if( isset($_SESSION['top7team'])) {
		$top7team = $_SESSION['top7team'];

		$errors = array();
		$infos = get_email_team( $top7team);
		$emails = array();
		$pseudos = array();
		foreach( $infos as  $p) {
			$emails[]  = $p['email'];
			$pseudos[] = $p['pseudo'];
		}
		$team = get_top7team_name( $top7team);
		put_register_form( $team, $pseudos, $emails, $errors);
	}

?>

</body>
</html>

