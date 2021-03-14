<?php

	include("common.inc");
	print_header_login();

	$message = file_get_contents( c_intro_file);
        $message = mb_convert_encoding( $message, 'HTML-ENTITIES', "UTF-8");
    	print_message( $message, c_home);


?>

</body>
</html>
