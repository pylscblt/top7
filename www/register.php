<?php

include("common.inc");


#printr( $_SERVER);
#echo "<pre>"; print_r( $_POST); echo "</pre>";
#echo "<pre>"; print_r( $pseudos); echo "</pre>";
init_sql();
printr_log("register.php", "_POST", $_POST);

$pseudos = array();
if (isset($_POST['pseudos'])) {
    foreach ($_POST['pseudos'] as $k => $pseudo) {
        $pseudos[$k] = $pseudo;
    }
}

$emails = array();
if (isset($_POST['emails'])) {
    foreach ($_POST['emails'] as $k => $email) {
        $emails[$k]	= $email;
    }
}
$team = "";
if (isset($_POST['team'])) {
    $team = $_POST['team'];
}


if (isset($_POST['g-recaptcha-response'])) {
    $captcha = $_POST['g-recaptcha-response'];
    print_log("register.php", "captcha", $captcha);
    print_log("register.php", "request", "https://www.google.com/recaptcha/api/siteverify?secret=" . c_recaptcha_secret_key . "&response=" . $captcha . "&remoteip=" . $_SERVER['REMOTE_ADDR']);
    $response = file_get_contents("https://www.google.com/recaptcha/api/siteverify?secret=" . c_recaptcha_secret_key . "&response=" . $captcha . "&remoteip=" . $_SERVER['REMOTE_ADDR']);
    $captcha_response = json_decode($response, true);
    printr_log("register.php", "captcha_response", $captcha_response);
} else {
    $captcha = false;
}

$errors = array();

if (count($pseudos) and count($emails) and $team) {
    $i=0;
    $min = c_min_team;
    $max = c_max_team;
    if (strlen($team) < $min) {
        $errors["msg"][1] = "Le nom de l'équipe doit avoir au minimum $min caractères.";
        $errors["team"][$i] = true;
    }
    if (strlen($team) > $max) {
        $errors["msg"][2] = "Le nom de l'équipe doit avoir au maximun $max caractères.";
        $errors["team"][$i] = true;
    }
    if (check_new_team($team)) {
        $errors["msg"][3] = "Le nom d'équipe <span class=\"warning\">$team</span> est déjà pris.";
        $errors["team"][$i] = true;
    }

    $j=6;
    $i=0;
    $min = c_min_pseudo;
    $max = c_max_pseudo;
    foreach ($pseudos as $pseudo) {
        if (strlen($pseudo) < $min) {
            $errors["msg"][4] = "Le pseudo doit avoir au minimum $min caractères.";
            $errors["pseudo"][$i] = true;
        }
        if (strlen($pseudo) > $max) {
            $errors["msg"][5] = "Le pseudo doit avoir au maximum $max caractères.";
            $errors["pseudo"][$i] = true;
        }
        if (check_new_pseudo($pseudo)) {
            $errors["msg"][$j++] = "Le pseudo <span class=\"warning\">$pseudo</span> est déjà pris.";
            $errors["pseudo"][$i] = true;
        }
        $i++;
    }
    $sames = check_same_inputs($pseudos);
    if (count($sames)) {
        $errors["msg"][$j++] = "Il faut des pseudos différents !";
        foreach ($sames as $key => $i) {
            $errors["pseudo"][$i] = true;
        }
    }

    $i=0;
    foreach ($emails as $email) {
        if (strlen($email)) {
            if (check_syntax_email($email)) {
                if (check_new_email($email)) {
                    $errors["msg"][$j++] = "L'adresse <span class=\"warning\">$email</span> est déjà utilisée !";
                    $errors["email"][$i] = true;
                }
            } else {
                $errors["msg"][$j++] = "L'adresse <span class=\"warning\">$email</span> est invalide !";
                $errors["email"][$i] = true;
            }
        } else {
            $errors["msg"][$j] = "L'adresse email ne doit pas être vide !";
            $errors["email"][$i] = true;
        }
        $i++;
    }
    $sames = check_same_inputs($emails);
    if (count($sames)) {
        $errors["msg"][$j++] = "Il faut des adresses email différentes !";
        foreach ($sames as $key => $i) {
            $errors["email"][$i] = true;
        }
    }

    #$errors = array();

    if (count($errors)) {
        print_header_register();
        put_register_form($team, $pseudos, $emails, $errors);
    //register_message( $errors);
    } else {
        if ($captcha) {
            if ($captcha_response["success"] == true && $captcha_response["score"] >= c_recaptcha_score) {
            	print_log("register.php", "insertion team", $team);
 
                foreach ($pseudos as $k => $pseudo) {
                    $captain = false;
                    if ($k == 0) {
                        $team_idx = insert_new_team($team);
                        $captain = true;
                        $captain_pseudo = $pseudo;
                    }
                    $email = $emails[ $k];
                    $player = insert_new_player($pseudo, $email, $team_idx, $captain);
                    if ($k == 0) {
                        $captain_player = $player;
                        $captain = true;
                    }
                    $key = insert_password_player($player);
                    send_email_register($pseudo, $email, $team_idx, $captain, $key);
                }

                session_start();
                $_SESSION['player'] 	= $captain_player;
                $_SESSION['login'] 	    = $email;
                $_SESSION['password'] 	= $password;
                $_SESSION['pseudo'] 	= $captain_pseudo;
                $_SESSION['mode'] 	    = c_guest;
                $_SESSION['display'] 	= c_top7;
                $_SESSION['team'] 	    = $team;
                $_SESSION['register'] 	= "";
    
                header('location: info');
            }
        }
    }
} else {
    print_header_register();
    // register( $_SERVER['PHP_SELF']);
    put_register_form($team, $pseudos, $emails, $errors);
}
?>
</body>
</html>
