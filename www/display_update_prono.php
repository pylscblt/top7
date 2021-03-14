<?php

	include("common.inc");
	check_session();

	#echo "<pre>"; print_r($_POST); echo "</pre>";
	#echo "<pre>"; print_r($_SESSION); echo "</pre>";

	print_header();

	$what = 0;
	if( isset( $_POST['team'])) $_SESSION['selected_team'] = $_POST['team'];

	header( 'location: player');

?>
</body>
</html>
