<?php

	include("common.inc");
	check_session();
/*
	echo "<pre>"; print_r($_GET); echo "</pre>";
	echo "<pre>"; print_r($_SESSION); echo "</pre>";
 */

	print_header();
	init_sql();

	echo "<center>\n";
	display_update_match( $_GET);
	echo "</center>\n";

?>

</body>
</html>
