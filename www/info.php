<?php

	include("common.inc");
	check_session();

	print_header_login();

    	if( isset( $_SESSION['register'])) 	print_info_register( $_SESSION);

	session_unset();
	session_destroy();


?>

</body>
</html>
