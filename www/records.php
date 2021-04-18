<?php

	include("common.inc");
	check_session();

	print_header();
	init_sql();


	if( isset( $_POST['display_stats'])) 	$_SESSION['display_stats'] = $_POST['display_stats'];
	$_SESSION['display'] = c_top7;


	echo "<center>\n";
	put_player_link( $_SESSION);
	put_nav_records( $_SESSION);
	records( $_SESSION);

	echo "<br><br>\n";
	palmares( $_SESSION);

	echo "</center>\n";
?>

</body>
</html>
