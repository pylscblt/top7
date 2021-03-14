#!/usr/local/bin/php
cd /home/topsevenyu/www
<?php

// called by crontab
// mn hh jj MMM JJJ
// 54  *  *   * 5-7
// Every Friday, Saturday and Sunday



    include("common.inc");
    
    
//    $date="24-09-16";
//    $team1="castres";
//    $team2="racing-92";
    
    init_sql();
    date_default_timezone_set('Europe/Paris');
    
echo "<pre>";
      $logfile =("/homez.208/topsevenyu/tmp/lnr.log");
    
    $top7_season = get_top7_season();
    $season = $top7_season['Id'];
    $now = now();
    $day = get_last_day_from_date( $now, $season);
    echo "day=$day, season=$season \n";
    $matchs = get_matchs_by_date( $day, $season);

      file_put_contents($logfile,"\nday=$day, season=$season \n",FILE_APPEND);
      file_put_contents($logfile,date(DATE_RFC2822)."\n",FILE_APPEND);

    foreach($matchs as $match) {
	$team1 = str_replace(" ", "-", strtolower($match['local']));
	$team2 = str_replace(" ", "-", strtolower($match['visiteur']));
	$dates = explode("-",$match['date']);
	$date = $dates[2] . "-" . $dates[1] . "-" . substr($dates[0],-2);
    	echo $date . "-" . $team1 . "-" . $team2 . "\n";

	$res = get_score_from_LNR($date, $team1, $team2);
	print_r($res);
    	file_put_contents($logfile,print_r($res,true),FILE_APPEND);
    	
    }
    
echo "</pre>";
    //print_r($matchs);

    
//    $res = get_score_from_LNR($date, $team1, $team2);
//    print_r($res);

?>
