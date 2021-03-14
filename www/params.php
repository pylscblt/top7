<?php


	include("common.inc");
	check_session();


	print_header();
	init_sql();

#echo "<pre>";print_r($_POST);echo "</pre>";
	if( isset( $_POST['update'])) {
		if( $_POST['update'] == c_phase_finale) update_rank_phase_finale( $_SESSION);
	}
	if( isset( $_POST['section'])) {
		$section = $_POST['section'];
		$name 	 = $_POST['name'];
		$date    = $_POST['date'];
		if( $section == "dates") update_season_dates( $_SESSION, $name, $date); 
	}


	echo "<center>\n";
	params( $_SESSION);
	echo "<br>\n";
?>
</body>
</html>

