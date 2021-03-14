<?php
// $php -f script.php
//
// update point fun for season 0,1,2
//
    include("common.inc");
    init_sql();


    $format  = "%Y-%m-%d %H:%M";
    $date    = strftime($format, now());
    $TOP7_DATE = "2017-05-06 16:00";

    $top7days = array(
        "2015-05-23 20:00",
        "2016-06-05 23:00",
        "2017-05-06 23:00",
    );

    foreach ($top7days as $top7day) 
    {
        $TOP7_DATE = $top7day;
        $date    = strftime($format, now());
        print "top7day : $top7day - $date\n";
        init_time_session();
        #print_r($_SESSION);
        $day = $_SESSION['today'];
        $season = $_SESSION['top7_season'];
        print "day : $day - season : $season\n";
        update_player_phase_reguliere($day, $season);
        update_point_fun($day, $season);
        /*
        $day += 1;
        print "day : $day - season : $season\n";
        update_player_phase_finale($day, $season);
        $day += 1;
        print "day : $day - season : $season\n";
        update_player_phase_finale($day, $season);
        $day += 1;
        print "day : $day - season : $season\n";
        update_player_phase_finale($day, $season);
         */
    }


?>
