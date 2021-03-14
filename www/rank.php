<?php


	include("common.inc");
	check_session();
	init_sql();


	if( isset( $_SESSION['display'])) 	$display = $_SESSION['display'];
	if( isset( $_POST['display'])) 		$display = $_POST['display'];
	$_SESSION['display'] 	= $display;

	$top14team = 0;
	if( isset( $_POST['top14team'])) 	$top14team = $_POST['top14team'];
	$_SESSION['top14team'] 	= $top14team;

	if( isset( $_SESSION['day'])) 	$day = $_SESSION['day'];
	else $day = get_day_from_date();

	if( isset( $_POST['next'])) $day=$day+1;
	if( isset( $_POST['prev'])) $day=$day-1;
	$season = $_SESSION['season'];
	$min_day	= 1;
	$max_day	= get_last_day( $season);
	if( $day > $max_day) $day = $max_day;
	if( $day < $min_day) $day = $min_day;

	$_SESSION['day'] 	= $day;


	init_deadline();
	echo "<center>\n";
	put_player_link( $_SESSION);
	put_status( $_SESSION);
	put_nav( $_SESSION);
	if( $display == c_rank14) display_rank( $_SESSION);
	if( $display == c_team14) display( $_SESSION);
	put_bottom_info( $_SESSION);
	echo "</center>\n";

?>

</body>
</html>
