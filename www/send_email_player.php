<?php
// called by crontab
// mn hh jj MMM JJJ
// 7 0,12  *  *  *
// Every at day at 00h07 and 12h07
//
echo "<pre>send_email_player</pre>";
include("common.inc");
init_sql();
session_start();
init_time_session();
$day    = $_SESSION['day'];
$today  = $_SESSION['today'];
$monday = $_SESSION['monday'];
$deadline = $monday + c_time_game_closed;
$season = $_SESSION['top7_season'];

/*
$format = "%Y-%m-%d %H:%M (%A)";
$t=$deadline;
echo "<pre>deadline=" . utf8_encode( strftime( $format, $t))  . "</pre>";
$t=now();
echo "<pre>now=" . utf8_encode( strftime( $format, $t))  . "</pre>";

echo "<pre>day=$day</pre>";
echo "<pre>today=$today</pre>";
echo "\n";
	 */

$format = "%Y-%m-%d %H:%M (%A)";
$t = time();
$r = explode("-", date("Y-m-d-H", $t));
$today_00 = mktime($r[3], 0, 0, $r[1], $r[2], $r[0]);
echo "<pre>monday=" . utf8_encode(strftime($format, $monday))  . "</pre>";
echo "<pre>t=" . utf8_encode(strftime($format, $t))  . "</pre>";
echo "<pre>deadline=" . utf8_encode(strftime($format, $deadline))  . "</pre>";

if ($t < $deadline) {
	$players = get_all_players($season);
	#echo "<pre>";print_r($players); echo "</pre>";
	foreach ($players as $player) {
		echo "<pre>player=" . $player['pseudo'] . "</pre>";
		$_SESSION['top7team'] 	= $player['top7team'];
		$_SESSION['player'] 	= $player['player'];
		$_SESSION['pseudo'] 	= $player['pseudo'];
		$game = check_date_player($_SESSION);
		$status = $_SESSION['status'];
		#echo "<pre>";print_r($_SESSION); echo "</pre>";
		if ($game == c_enable and $status == c_can_play) {
			echo "<h3>send email to " . $player['pseudo'] . "</h3>";
			send_email_next_player($_SESSION, $_SESSION['player']);
		}
		if ($day == $today and $today_00 == $monday) {
			echo "<h3>send email to " . $player['pseudo'] . "</h3>";
			send_email_game_is_opened($_SESSION, $_SESSION['player']);
		}
		sleep(1);
	}
}

session_unset();
session_destroy();
