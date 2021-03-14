<?php

	include("common.inc");
	print_header_password();


	init_sql();
	$key	= 0;
	if( isset( $_GET['key'])) 	$key = $_GET['key'];
	if( $key) {
#printr( $_GET); 
		$player = key_is_valid( $key);
		if( $player) new_password( $player, $key);
	}

?>

</body>
</html>
