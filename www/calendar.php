<?php


	include("common.inc");
	check_session();
	init_sql();


	if( isset( $_SESSION['display'])) 	$display = $_SESSION['display'];
	if( isset( $_POST['display'])) 		$display = $_POST['display'];
	$_SESSION['display'] 	= $display;

	if( $_SERVER['REQUEST_METHOD'] == 'POST') {
		$day 	= $_SESSION['day'];
		$season = $_SESSION['season'];
		$team = $id = $team_nb = 0;
		if( isset( $_POST['team'])) 	$team = $_POST['team'];
		if( isset( $_POST['id'])) 	$id = $_POST['id'];
		if( isset( $_POST['team_nb'])) 	$team_nb = $_POST['team_nb'];
		if( $team>0 and $id>0 and ($team_nb==1 or $team_nb==2)) update_calendar_matchs( $id, $team, $team_nb, $day, $season);
	}

	init_deadline();
	echo "<center>\n";
	put_player_link( $_SESSION);
	put_status( $_SESSION);
	put_nav( $_SESSION);
	if( $day > c_last_day) display_calendar_matchs( $_SESSION);
	put_bottom_info( $_SESSION);
	echo "</center>\n";

?>

</body>
</html>
