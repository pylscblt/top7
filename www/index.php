<?php

include("common.inc");

if (version_compare(PHP_VERSION, '7.0.0') >= 0) $token = bin2hex(random_bytes(32));
else $token = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));
session_start();
$_SESSION['token'] = $token;

print_header_login();
put_login_form($token);
print_version();

?>

</body>

</html>