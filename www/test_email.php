<html>
<head>
</head>
<body>
<?php

	$MyEmail = "postmaster@topseven.fr";

	if( isset( $_POST['dest'])) {
		$p = $_POST;
		echo "<pre>"; print_r( $_POST); echo "</pre>";

		$headers = "From: $MyEmail"."\n";
		$headers .= "Reply-To: $MyEmail"."\n";
#$headers .= 'Content-Type: text/plain; charset="iso-8859-1"'."\n";
       	$headers .= 'Content-Type: text/plain; charset="utf-8"'."\n";
       	$headers .= 'Content-Transfer-Encoding: 8bit';

		$dest =  	$p['dest'];
		$msg = 		$p['msg'];
		$subject = 	$p['subject'];
#$subject = 	"Test OVH"; 
		$msg  .= 	"\n" . date('l jS \of F Y h:i:s A');
		echo "<pre>$headers</pre>";
		echo "<pre>Dest: $dest</pre>";
		echo "<pre>Subject: $subject</pre>";
		echo "<pre>Msg: $msg</pre>";
		$subject = utf8_encode( $subject);
		$msg    = utf8_encode( $msg);
       	mail( $dest, $subject, $msg, $headers); 
	}

	echo "<h2>Test Email OVH</h2>\n";
	$action = "test_email.php";
	echo "<form id=\"test\" action=\"$action\" method=\"post\">\n";
	echo "Destinataire : ";
	echo "<input type=\"email\" size=\"20\" name=\"dest\">\n";
	echo "<br>Sujet : ";
	echo "<input type=\"text\" size=\"40\" name=\"subject\">\n";
	echo "<br>";
	echo "<textarea rows=\"4\" cols=\"60\" name=\"msg\">\n";
	echo "Entrer le texte ...";
	echo "</textarea>\n";
	echo "<br>";
	echo "<input type=\"submit\" name=\"button\" value=\"envoyer\">\n";
	echo "</form>\n";


?>

</body>
</html>
