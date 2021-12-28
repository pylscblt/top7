<?php

/* project	: top7
 * author 	: pyl
 * creation : Jan 2015
 *
 */

$db_admin = array(
	"user"		=> "topseven",
	"password"	=> "topseven");
$db_player = array(
	"user"		=> "topseven",
	"password"	=> "topseven");
$top7_db = array(
	"server"	=> "XXXX",
	"database"	=> "topseven");

define("c_prod", "");

define("c_admin_login", "XXXX");
define("c_admin_password", "XXXX");
 
define( "c_recaptcha_public_key", "XXXX");
define( "c_recaptcha_secret_key", "XXXX");

define("c_recaptcha_score", 0.8);
define("c_google_gtag", "conf/google_gtag.html");

define( "c_logo_file", 	"logo.png");

define( "c_display_blog", 	true);
define( "c_url_blog", 		"http://www.lesbrevesdovalie.com/rss.xml");
define( "c_file_blog", 		"rss.xml");
define( "c_nb_news",		5);
define( "c_url_github", 	"https://github.com/pylscblt/top7");
define( "c_url_lnr_match",  "http://www.lnr.fr/rugby-top-14/matchs/");
define( "c_url_lnr_req",    "http://www.lnr.fr/fdmi?nid=");

define( "c_records_limit", 3);
define( "c_records_remove_duplicate", true);
define( "c_canceled_season", 5); # season 2019-2020

define( "c_min_password", 	6);
define( "c_max_password", 	30);
define( "c_min_pseudo", 	8);
define( "c_max_pseudo", 	40);
define( "c_min_team", 		8);
define( "c_max_team", 		50);


// PasswordForm, RegisterForm, LoginForm
define( "c_pseudo_size", 		30);
define( "c_email_size", 		30);
define( "c_password_size", 		25);
define( "c_team7_size", 		30);

$debug 		    = true;
$debug_session 	= false;
$debug_email 	= false;
$debug_mysql 	= false;

define( "c_email_pyl",						"XXXX");
define( "c_email_subject_reinit_password",  "Reinitialisation mot de passe");
define( "c_email_subject_init_team",        "Nouvelle équipe");
define( "c_email_subject_register",         "Inscription");

define( "c_delay_reset_password", 	345600); //4*24*3600=345600 sec
define( "c_session_activity", 		1800); // 30 mn

define( "c_email_admin",		"XXXX");
define( "c_url_top7",			"http://www.topseven.fr/");
define( "c_manual_file",		"manual.html");
define( "c_rules_file",			"rules.html");
define( "c_legend7_file",		"legend7.html");
define( "c_pointsFun_file",		"pointsFun.html");
define( "c_legend14_file",		"legend14.html");
define( "c_register_rule_file",	"register.html");
define( "c_intro_file",	    	"intro.html");
define( "c_contact_file",		"contact.html");
define( "c_version",        	"2.0");
define( "c_copyright",      	"2014");
define( "c_stats_legend_file",	"stats_legend");
define( "c_favicons_file",		"favicons.html");
define( "c_palmares_file",      "palmares.html");

define( "c_time_deadline", 		43200);	//12*3600=43200 sec
define( "c_time_game_closed", 	345600);//thurday = monday+4*24*3600=345600 sec

$meta_names = array(
	array( "Author", 		"PYL"),
	array( "Description", 	"Top 7 petit jeu entre amis"),
	array( "Name", 			"Top 7"),
	array( "Version", 		c_version),
	array( "Copyright", 	c_copyright)
);

// put_status()
define( "c_msg_game_closed", 	    "Les jeux sont faits !");
define( "c_msg_game_not_opened", 	"Les jeux ne sont pas encore ouverts !");
define( "c_msg_game_in_progress", 	"Les jeux sont en cours ...");

define( "c_msg_home_legend1",       "Mot de passe oublié !");
define( "c_msg_home_legend2",       "Tu souhaites créer ton équipe !");
define( "c_msg_home_legend3",       "C'est ici");
define( "c_msg_home_legend4",       "C'est quoi ce jeu ?");

define( "c_msg_password_title1",     "Réinitialise ton mot de passe");
define( "c_msg_password_title2",     "Initialise ton mot de passe");
define( "c_msg_password_legend1",    "Saisis ton email pour recevoir les instructions.");
define( "c_msg_password_legend2",    "Désolé mais j'ai pas trouvé l'adresse !#?@@$??!");

// print_alert()
define( "c_msg_alert_1", 1);
$alert_msgs = array (
    0 => "?",
    c_msg_alert_1 => "             Trop tard ! \\nL'équipe sélectionnée n'est plus disponible.",
);


function now() {
    global $TOP7_DATE;  // used for DEBUG
	$now = time();
	return $now;
}

?>
