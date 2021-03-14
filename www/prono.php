<html>
<body>
<?php

	include("common.inc");
	init_sql();


	$day = $_GET['day'];
	if( isset( $_GET['next'])) $day=$day+1;
	if( isset( $_GET['prev'])) $day=$day-1;
	$min_day	= 1;
	$max_day	= 26;
	if( $day > $max_day) $day = $max_day;
	if( $day < $min_day) $day = $min_day;

	display( $day, c_top7);

	put_admin_nav();

?>
</body>
</html>
