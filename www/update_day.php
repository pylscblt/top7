<?php


	include("common.inc");
	check_session();


	print_header();
	init_sql();


    $display = 0;
	if( isset( $_SESSION['display'])) $display = $_SESSION['display'];
	if( isset( $_POST['display'])) 	$display = $_POST['display'];

    $day = 0;
	if( isset( $_SESSION['day'])) 	$day = $_SESSION['day'];
	if( isset( $_POST['day'])) 	$day = $_POST['day'];
	if( $day == 0) $day = get_day_from_date();

	$player = 0;
	if( isset( $_SESSION['player'])) $player=$_SESSION['player'];
	if( isset( $_POST['player'])) 	 $player = $_POST['player'];

	$top7team = 0;
	if( isset( $_SESSION['top7team'])) 	$top7team=$_SESSION['top7team'];
	if( isset( $_POST['top7team'])) 	$top7team = $_POST['top7team'];


	$_SESSION['display'] 	= $display;
	$_SESSION['day'] 	= $day;
	$_SESSION['player'] 	= $player;
	$_SESSION['top7team'] 	= $top7team;
	$_SESSION['top14team'] 	= 0;

	$_SESSION['game'] 	= c_enable;


	echo "<center>\n";
	put_player_link( $_SESSION);
	put_status( $_SESSION);
	put_nav( $_SESSION);
	display( $_SESSION);
	echo "<br>\n";

	echo "</center>\n";
?>

</body>
</html>
