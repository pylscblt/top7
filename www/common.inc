<?php

/* project    : top7
 * author     : pyl
 * creation     : Oct 2014, v1.0
 * update       : Sep 2017, v2.0, PHP5.4 -> PHP7.1 + PDO
 */

#require( dirname( __DIR__) . "/dev/conf/conf.php");
#require( dirname( __DIR__) . "/www/conf/conf.php");
#require( "/var/www/html/conf/conf.php");

$ovh_path    = dirname(__DIR__) . "/www/conf/conf.php";
$docker_path = "/var/www/html/conf/conf.php";

if (file_exists($ovh_path)) {
    require $ovh_path;
    $log_path = __DIR__ . "/../tmp";
} elseif (file_exists($docker_path)) {
    require $docker_path;
    $log_path = "/tmp";
} else {
    exit;
}
// blank page is displayed if file not found

// PDO SQL : pdo_fetch()
define("c_none", 0);
define("c_one", 1);
define("c_all", 2);

// player status
define("c_player_waiting", 1);
define("c_player_enable", 2);
define("c_player_disable", 3);

// status
define("c_can_play", 1);
define("c_cannot_play", 2);
define("c_not_selected", 3);
define("c_no_more_selected", 4);

// prono
define("c_not_played", 1);
define("c_played", 2);

// game : check_date_player()
define("c_enable", 1);
define("c_disable", 2);
define("c_validated", 3);
define("c_not_opened", 4);
define("c_game_over", 5);
define("c_season_over", 6);

$player_status = array(
    0                => "?",
    c_player_waiting => "Inscription en attente",
    c_player_enable  => "Inscrit",
    c_player_disable => "Non sélectionné",
);

// team status
define("c_team_waiting", 1);
define("c_team_enable", 2);
define("c_team_disable", 3);

$team_status = array(
    0              => "?",
    c_team_waiting => "Inscriptions en cours",
    c_team_enable  => "Validée",
    c_team_disable => "Non sélectionné",
);

// mode
define("c_admin", 1);
define("c_guest", 2);
define("c_player", 3);

// admin mode
define("c_score", 1);
define("c_match", 2);

// display
define("c_top7", 1);
define("c_top14", 2);
define("c_rank7", 3);
define("c_rank14", 4);
define("c_team7", 5);
define("c_team14", 6);
define("c_top7_player", 7);
define("c_top7_match", 8);
define("c_info_player", 9);
define("c_info_team", 10);
define("c_top_final", 11);
define("c_top14_match", 12);

define("c_last_day", 26); // dernière journée phase régulière
define("c_barrage_day", 27); // barrages
define("c_demifinales_day", 28); // demi finales
define("c_finale_day", 29); // finale

// stats
define("c_stats_by_team", 1);
define("c_stats_by_player", 2);
define("c_stats_fun", 3);
define("c_stats_exterieur", 4);
define("c_stats_coiffeur", 5);
define("c_stats_BOff", 6);
define("c_stats_14", 7);
define("c_stats_average", 8);

define("c_phase_reguliere", 1);
define("c_phase_finale", 2);

$opponent_player = array(
#    c_barrage_day     => array(0 => 1, 1 => 0, 2 => 5, 3 => 4, 4 => 3, 5 => 2),
    c_barrage_day     => array(0 => 1, 1 => 0, 2 => 5, 3 => 4, 4 => 3, 5 => 2),
    c_demifinales_day => array(0 => 3, 1 => 2, 2 => 1, 3 => 0),
    c_finale_day      => array(0 => 1, 1 => 0),
);

$phase_finale_player = array(
    c_barrage_day     => array(
        array(0 => c_not_selected, 1 => c_not_selected, 2 => c_can_play, 3 => c_can_play, 4 => c_cannot_play, 5 => c_cannot_play),
        array(0 => c_not_selected, 1 => c_not_selected, 2 => c_cannot_play, 3 => c_cannot_play, 4 => c_can_play, 5 => c_can_play),
    ),
    c_demifinales_day => array(
        array(0 => c_can_play, 1 => c_can_play, 2 => c_cannot_play, 3 => c_cannot_play),
        array(0 => c_cannot_play, 1 => c_cannot_play, 2 => c_can_play, 3 => c_can_play),
    ),
    c_finale_day      => array(
        array(0 => c_can_play, 1 => c_cannot_play),
        array(0 => c_cannot_play, 1 => c_can_play),
    ),
);

$season_dates = array(
    array(
        "name" => "start",
        "title"      => "Date début saison", "comment" => "Date à partir de laquelle la nouvelle saison s'affiche."
    ),
    array(
        "name" => "start_register",
        "title"      => "Date début inscription", "comment" => "Date à partir de laquelle le lien pour s'inscrire est activé."
    ),
    array(
        "name" => "stop_register",
        "title"      => "Date fin inscription", "comment" => "Date à partir de laquelle le lien pour s'inscrire est désactivé."
    ),
    array(
        "name" => "close_forum",
        "title"      => "Date fin forum", "comment" => "Date à partir de laquelle le forum pour la saison en cours est désactivé."
    ),
);

$title_phase_finale = array(
    "Vainqueur",
    "Finaliste",
    "1er demi-finaliste",
    "2ème demi-finaliste",
    "1er barragiste",
    "2ème barragiste",
    "Relégué",
);

// print_message( $message, $action)
define("c_home", 1);
define("c_previous", 2);

// insert_password_player( $player)
define("c_password_pending", 1);

// display_info_team(), display_info_player()
// put_line_info(), put_line_edit(), put_line_button()
define("c_line_info", 0);
define("c_line_edit", 1);
define("c_line_button", 2);

define("c_winner", 1);
define("c_loser", 2);

$tr_class   = array("even", "odd");
$evol_chars = array("-1" => "&darr;", "0" => "&harr;", "1" => "&uarr;");
$evol_img   = array("-1" => "down.gif", "0" => "", "1" => "up.gif");

define("c_icon_coiffeur", "<img src=\"coiffeur.png\">");
define("c_icon_rugby", "<img src=\"rugby.png\">");

$f_debugs = array(
    "error", // don't remove
    "put_nav", // don't remove
    "player.php",
    #    "check_session",
    "key_is_valid",
    "init_time_session",
    #    "init_password_pending",
    "put_player_link",
    "put_status",
    "check_player", // don't remove
    "check_status_player",
    #    "check_date_player",
    "check_player_phase_finale",
    #    "check_player_phase_reguliere",
    #    "check_prono_not_taken",
    #    "get_day_from_date",
    #    "get_time_game_closed",
    #    "get_last_day_from_date",
    #    "get_last_day_season",
    "get_first_day_season",
    #    "get_monday_from_day",
    "get_matchs_by_rank",
    #    "get_rss",
    #    "get_pronos",
    #    "get_score_players",
    #    "get_final_results",
    "get_top7_day_selection",
    #    "get_top7_matchs",
    #    "get_random_rank7",
    "get_rank7",
    "get_rank7_finales",
    #    "get_nb_different_team",
    #    "get_last_day",
    "get_player_from_email",
    "display",
    #    "display_final",
    #    "display_update_match",
    #    "update_match",
    #    "update_prono",
    #    "update_match_prono",
    "update_season_dates",
    #    "send_email_next_player",
    #    "send_email_forum",
    "LNR_rank",
    "update_player_phase_reguliere",
    "update_rank_phase_reguliere",
    "update_rank_phase_finale",
    "update_register",
    #    "check_game_closed",
    "register.php",
    "register_new_season.php",
    "recaptcha",
    "palmares",
    "stats",
    "register_same_top7team");

function print_version()
{

    echo "<div id=\"footer\">\n";
    echo "&copy; " . c_copyright . " - <a href=\"" . c_url_github . "\">PYL-AP" . "</a> - " . c_version . " - " . date("Ymd.Hi", filemtime("common.inc")) . "&nbsp;&nbsp;";
    echo "</div>\n";
}

function print_log($function, $name, $msg)
{
    global $debug, $f_debugs, $log_path;
    //if( $debug and in_array($function, $f_debugs)) {
    if (in_array($function, $f_debugs)) {
        $log = date("Ymd G:i:s ") . $function . ' [' . $name . '] ' . $msg . PHP_EOL;
        file_put_contents($log_path . '/log_' . date("Ymd") . '.txt', $log, FILE_APPEND);
    }
}

function printr_log($function, $name, $var)
{
    # ex: print_log( __FUNCTION__, "test", var_export($p, TRUE));
    print_log($function, $name, var_export($var, true));
}

function print_header_head($class, $utf8, $js)
{
    global $meta_names;

    echo "<!DOCTYPE html>\n";
    if (strlen($class)) {
        echo "<html class=\"$class\">\n";
    } else {
        echo "<html>\n";
    }

    echo "<head>\n";


    if (c_prod == "ovh") {
        # Google Analytics
        readfile(c_google_gtag);
    }

    echo "<title>Top7</title>\n";
    foreach ($meta_names as $meta_name) {
        echo "<meta name=\"$meta_name[0]\" content=\"$meta_name[1]\">\n";
    }
    echo "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n";
    #echo "<meta charset=\"ISO-8859-1\">\n";
    #echo "<meta charset=\"UTF-8\">\n";

    # header for mobile device
    echo "<meta name=viewport content=\"width=device-width, initial-scale=1\">\n";

    #echo "<link rel=\"shortcut icon\" href=\"top7.ico\" type=\"image/x-icon\">\n";

    // http://realfavicongenerator.net/
    readfile(c_favicons_file);

    echo "<link rel=\"stylesheet\" href=\"common.css\" type=\"text/css\">\n";

    echo "<script src=\"common.js\"></script>\n";
    if ($class == "register" && c_prod == "ovh") {
        echo "<script src=\"https://www.google.com/recaptcha/api.js?render=" . c_recaptcha_public_key . "\"></script>\n";
        echo "<script>
    grecaptcha.ready(function() {
    // do request for recaptcha token
    // response is promise with passed token
        grecaptcha.execute('" . c_recaptcha_public_key . "', {action:'validate_captcha'}).then(function(token) {
        // add token value to form
            // console.log('token : ' + token);
            document.getElementById('g-recaptcha-response').value = token;
        });
    });
</script>\n";
    }

    //
    //    $js = true;
    //    if ($js) {
    //        echo "<script src=\"common.js\"></script>\n";
    //    } else {
    //        echo "<script type=\"text/javascript\">
    //function unhide(divID) {
    //    var item = document.getElementById(divID);
    //    if (item) {
    //      item.className=(item.className=='hidden')?'unhidden':'hidden';
    //    }
    //}
    //</script>\n";
    //    }
    //
    echo "</head>\n\n";
}

function print_header_password()
{
    print_header_head("password", false, true);
    echo "<body>\n";
}
function print_header_login()
{
    print_header_head("login", false, true);
    echo "<body>\n";
}
function print_header_register()
{
    print_header_head("register", false, true);
    echo "<body>\n";
}
function print_header()
{
    echo "<html>\n";
    print_header_head("", false, false);
    echo "<body class=\"top7\">\n";
}

function print_header_display($t)
{
    echo "<html>\n";
    print_header_head("", false, true);
    echo "<body class=\"top7\" onLoad=\"display_c( $t);\">\n";
}

function error($function, $line)
{
    print_log(__FUNCTION__, $function, $line);
    $d = date("Ymd G:i:s ");
    die("<pre>TOP7 - Error - See log at $d !</pre>");
}

function init_sql()
{
    global $db_player;
    sql($db_player);
    #error_reporting(E_ALL);
    #ini_set('display_errors', 1);
}

function init_admin_sql()
{
    global $db_admin;
    sql($db_admin);
}

function sql($login)
{
    global $strDate;
    setlocale(LC_TIME, 'fr_FR', 'fra');
    $strDate = mb_convert_encoding('%a %d %b %Y %H:%M', 'ISO-8859-9', 'UTF-8');

    global $top7_db;
    $server   = $top7_db['server'];
    $database = $top7_db['database'];
    $user     = $login['user'];
    $password = $login['password'];
    $charset  = "utf8mb4";

    global $pdo;
    try {
        $pdo = new PDO("mysql:dbname=$database;host=$server;charset=$charset", $user, $password);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    } catch (Exception $e) {
        print_log("error", "sql", "db init");
        error(__FUNCTION__, "(db init)" . $e->getMessage());
    }
}

function pdo_fetch_param($function, $mode, $query, $param)
{
    global $pdo, $debug_mysql;
    if ($debug_mysql) {
        echo "<pre>$query</pre>";
    }

    print_log($function, "sql", $query);
    $r = NULL;
    try {
        $select = $pdo->prepare($query);
        $select->setFetchMode(PDO::FETCH_ASSOC);
        $select->execute($param);
        if ($mode == c_one) {
            $r = $select->fetch();
        }

        if ($mode == c_all) {
            $r = $select->fetchAll();
        }
    } catch (Exception $e) {
        print_log("error", $function, $query);
        error(__FUNCTION__, "(" . $function . ") " . $e->getMessage());
    }
    printr_log($function, "sql", $r);
    return $r;
}

function pdo_fetch($function, $mode, $query)
{
    return pdo_fetch_param($function, $mode, $query, null);
}

function pdo_exec($function, $query)
{
    global $pdo, $debug_mysql;
    if ($debug_mysql) {
        echo "<pre>$query</pre>";
    }

    print_log($function, "sql", $query);
    try {
        $select = $pdo->prepare($query);
        $select->execute();
    } catch (Exception $e) {
        print_log("error", $function, $query);
        error(__FUNCTION__, "(" . $function . ") " . $e->getMessage());
    }
}

function pdo_insert($function, $query, $data)
{
    global $pdo, $debug_mysql;
    if ($debug_mysql) {
        echo "<pre>$query</pre>";
    }

    print_log($function, "sql", $query);
    try {
        $insert = $pdo->prepare($query);
        $insert->execute($data);
        $r = $pdo->lastInsertId();
    } catch (Exception $e) {
        print_log("error", $function, $query);
        error(__FUNCTION__, "(" . $function . ") " . $e->getMessage());
    }
    return $r;
}

function display_select_player($top7team, $selected_player)
{

    $action  = "update_day";
    $display = c_top7_player;

    $table   = "`player`";
    $query   = "SELECT pseudo, player_idx FROM `player` where team='$top7team' order by player_idx";
    $rows    = pdo_fetch(__FUNCTION__, c_all, $query);
    $players = array();
    foreach ($rows as $row) {
        $players[] = $row;
    }

    echo "<form name=\"form_player\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "<select name=\"player\" id=\"AdminSelect\" onChange=\"if(this.value!='none') this.form.submit();\">\n";
    if ($selected_player == 0) {
        echo "<option selected=\"selected\" value=\"none\">Choisir un joueur</option>\n";
    }

    foreach ($players as $player) {
        $idx  = $player['player_idx'];
        $name = $player['pseudo'];
        if ($selected_player == $idx) {
            $selected = " selected=\"selected\"";
        } else {
            $selected = "";
        }

        echo "<option $selected value=$idx>$name</option>\n";
    }
    echo "</select>\n";
    echo "</form>\n";
}

function display_select_day($selected_day)
{

    $action  = "update_day";
    $display = c_top14;

    $query = "SELECT DISTINCT day FROM `match`";
    $rows  = pdo_fetch(__FUNCTION__, c_all, $query);
    $days  = array();
    foreach ($rows as $row) {
        $days[] = $row['day'];
    }

    echo "<form name=\"form_day\" action=\"$action\" method=\"post\">\n";
    echo "<select name=\"day\" id=\"AdminSelect\" onChange=\"if(this.value!='none') this.form.submit();\">\n";
    if ($selected_day == 0) {
        echo "<option selected=\"selected\" value=\"none\">Choisir une journée</option>\n";
    }

    foreach ($days as $day) {
        if ($selected_day == $day) {
            $selected = " selected=\"selected\"";
        } else {
            $selected = "";
        }

        $title = get_day_title($day);
        echo "<option $selected value=$day>$title</option>\n";
    }
    echo "</select>\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "</form>\n";
}

function get_last_day($season)
{

    $query = "select day from `score` where J=1 order by day desc limit 1";
    $row   = pdo_fetch(__FUNCTION__, c_one, $query);
    $day   = $row['day'];
    if ($day > c_last_day) {
        $day = c_last_day;
    }

    return $day;
}

function get_top7team_captain($team)
{
    $query = "select pseudo from player where team=$team and captain=1";
    $row   = pdo_fetch(__FUNCTION__, c_one, $query);
    return $row['pseudo'];
}

function get_top7team_players($team)
{
    $query = "select * from player where team=$team order by captain desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_top7team_name($team)
{
    $query = "select name from team_player where team_idx=$team";
    $name  = pdo_fetch(__FUNCTION__, c_one, $query);
    return $name['name'];
}

function get_top7_players($team)
{
    $query   = "select player_idx, pseudo from player where team=$team ";
    $rows    = pdo_fetch(__FUNCTION__, c_all, $query);
    $players = array();
    foreach ($rows as $row) {
        $players[$row['player_idx']] = $row['pseudo'];
    }

    printr_log(__FUNCTION__, "players", $players);
    return $players;
}

function get_top7_title($day)
{
    return "TOP7 - " . get_day_title($day);
}

function get_top14_title($day)
{
    return "TOP14 - " . get_day_title($day);
}

function get_day_title($day)
{

    $title = "?";
    if ($day <= c_last_day) {
        $title = "Journée $day";
    }

    if ($day == c_barrage_day) {
        $title = "Barrages";
    }

    if ($day == c_demifinales_day) {
        $title = "Demi-Finales";
    }

    if ($day == c_finale_day) {
        $title = "Finale";
    }

    return $title;
}

function get_top14_teams($season)
{

    $query = "select * from team where season=$season";
    $rows  = pdo_fetch(__FUNCTION__, c_all, $query);
    $teams = array();
    foreach ($rows as $row) {
        $teams[$row['team_idx']] = $row['team_long'];
    }

    printr_log(__FUNCTION__, "teams", $teams);
    return $teams;
}

function get_pseudo_from_player($player)
{

    $query = "select pseudo ";
    $query .= "from player ";
    $query .= "where player_idx=$player";
    $row = pdo_fetch(__FUNCTION__, c_one, $query);
    return $row['pseudo'];
}

function get_player_season($player, $season)
{

    $query = "select * ";
    $query .= "from player ";
    $query .= "where email =";
    $query .= "( select email from player where player_idx=$player) ";
    $query .= " and season=$season";
    return pdo_fetch(__FUNCTION__, c_one, $query);
}

function get_player($player)
{

    $query = "select * from player where player_idx=$player";
    return pdo_fetch(__FUNCTION__, c_one, $query);
}

function get_pronos($day, $top7team)
{

    $query = "select t1.pseudo as pl, ";
    $query .= "tp.team as tm, ";
    $query .= "player ";
    $query .= "from prono as tp ";
    $query .= "left join `player` as t1 on t1.player_idx=tp.player ";
    $query .= "where tp.day=$day and t1.team=$top7team";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function update_calendar_matchs($id, $team, $team_nb, $day, $season)
{

    global $pdo;
    $field  = "team" . $team_nb;
    $query  = "update `match` set $field=$team where `id`='$id'";
    $update = $pdo->prepare($query);

    $query        = "select * from `match` where season=$season and day=$day order by id";
    $select_match = $pdo->prepare($query);
    $query        = "select id, season, day, team from `score` where season=$season and day=$day order by id";
    $select_score = $pdo->prepare($query);

    try {
        $update->execute();
        $select_match->execute();
        $select_score->execute();
        $select_match->setFetchMode(PDO::FETCH_ASSOC);
        $select_score->setFetchMode(PDO::FETCH_ASSOC);
        $matchs = $select_match->fetchAll();
        $scores = $select_score->fetchAll();
    } catch (Exception $e) {
        error(__FUNCTION__, "(" . $e->getCode() . ") " . $e->getMessage());
    }

    printr_log(__FUNCTION__, "matchs", $matchs);
    $table = "score";
    $i     = $j     = 0;
    foreach ($matchs as $match) {

        $team1 = $match['team1'];
        $team2 = $match['team2'];

        $id = $scores[$i]['id'];
        $i++;
        $query = "update `$table` set `team`=$team1, `rank`=$j where `id`='$id'";
        pdo_exec(__FUNCTION__, $query);

        $id = $scores[$i]['id'];
        $i++;
        $query = "update `$table` set `team`=$team2, `rank`=$j where `id`='$id'";
        pdo_exec(__FUNCTION__, $query);
        $j++;
    }
}

function get_calendar_matchs($day, $season)
{

    $query = "select * ";
    $query .= "from `match`  ";
    $query .= "where  match.day=$day and  match.season=$season ";
    $query .= "order by  id";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_matchs_by_date($day, $season)
{

    $query = "select t1.team_long as local, t2.team_long as visiteur, ";
    $query .= "s1.pm as score1, s2.pm as score2, ";
    $query .= "s1.V as v1, s2.V as v2, ";
    $query .= "s1.em as try1, s2.em as try2, ";
    $query .= "s1.bo as bo1, s2.bo as bo2, ";
    $query .= "s1.bd as bd1, s2.bd as bd2, ";
    $query .= "team1, team2, date, time, tm.day, s1.rank ";
    $query .= "from `match` as tm ";
    $query .= "left join `team` as t1 on t1.team_idx=tm.team1 and t1.season=$season ";
    $query .= "left join `team` as t2 on t2.team_idx=tm.team2 and t2.season=$season ";
    $query .= "left join `score` as s1 on s1.team=tm.team1 and s1.season=$season ";
    $query .= "left join `score` as s2 on s2.team=tm.team2 and s2.season=$season ";
    $query .= "where tm.day=$day and s1.day=$day and s2.day=$day ";
    $query .= "and tm.season=$season and t1.season=$season and t2.season=$season ";
    $query .= "order by date, time, team1";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_matchs_by_rank($day, $season)
{

    $query = "select t1.team_long as local, t2.team_long as visiteur, ";
    $query .= "s1.pm as score1, s2.pm as score2, ";
    $query .= "s1.V as v1, s2.V as v2, ";
    $query .= "s1.em as try1, s2.em as try2, ";
    $query .= "s1.bo as bo1, s2.bo as bo2, ";
    $query .= "s1.bd as bd1, s2.bd as bd2, ";
    $query .= "team1, team2, date, time, tm.day ";
    $query .= "from `match` as tm ";
    $query .= "left join `team` as t1 on t1.team_idx=tm.team1 and t1.season=$season ";
    $query .= "left join `team` as t2 on t2.team_idx=tm.team2 and t1.season=$season ";
    $query .= "left join `score` as s1 on s1.team=tm.team1 and s1.season=$season ";
    $query .= "left join `score` as s2 on s2.team=tm.team2 and s2.season=$season ";
    $query .= "where tm.day=$day and s1.day=$day and s2.day=$day ";
    $query .= "and tm.season=$season and t1.season=$season and t2.season=$season ";
    $query .= "order by s1.rank";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_score_details_nobonus($score)
{
    $detail = "";
    if ($score['try'] > 0) {
        $detail = "(" . $score['try'] . "E)";
    }

    return $detail;
}

function get_score_details($score)
{

    $detail = "";
    if ($score['try'] > 0) {
        $detail .= $score['try'] . "E,";
    }

    if ($score['bo']) {
        $detail .= "bo,";
    }

    if ($score['bd']) {
        $detail .= "bd,";
    }

    if (strlen($detail)) {
        $detail = "(" . substr($detail, 0, -1) . ")";
    }

    return $detail;
}

function get_top7_teams($season)
{

    $query = "select distinct team ";
    $query .= "from `player` where season=$season ";
    $rows  = pdo_fetch(__FUNCTION__, c_all, $query);
    $teams = array();
    foreach ($rows as $row) {
        $teams[] = $row['team'];
    }

    return $teams;
}

function insert_new_team($name, $status=c_team_waiting)
{

    $top7_season = get_top7_season();
    $season      = $top7_season['Id'];
    $query       = "insert into team_player(name, status,season) value (:name, :status, :season)";
    $data        = array(
        "name"      => $name,
        "status"    => $status,
        "season"    => $season
    );
    return pdo_insert(__FUNCTION__, $query, $data);
}

function display_team_choice($p)
{

    global $tr_class;

    $player   = $p['player'];
    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    $teams = get_top7_teams();

    $class  = "top7";
    $classt = "teamtop7";
    $span   = 3;
    $title  = "Equipe Top7";
    echo "<table class=\"day\">\n";
    echo "<tr>\n";
    echo "<th class=\"$class\" colspan=\"$span\">$title</th>\n";
    echo "</tr>\n";
    echo "<tr>\n";
    echo "<th class=\"$classt\">Equipe</th>\n";
    echo "<th class=\"$classt\">Joueurs</th>\n";
    echo "<th class=\"$classt\">#/7</th>\n";
    echo "</tr>\n";

    $idx                   = 1;
    $team                  = $teams[0]['team_idx'];
    $player_list           = "";
    $player_linked_to_team = false;
    $nb_player             = 0;

    $action = $_SERVER['PHP_SELF'];

    foreach ($teams as $k => $data) {
        $class = $tr_class[$idx % 2];
        if ($team == $data['team_idx']) {
            $player_list .= $data['pseudo'] . ", ";
            $name = $data['name'];
            $nb_player++;
        } else {
            $player_list = substr($player_list, 0, -2);
            echo "<tr class=\"$class\">";
            if ($top7team == 0 and $nb_player < 7) {
                echo "<td class=\"$classt\">";
                echo "<form id=\"form_team\" action=\"$action\" method=\"post\">\n";
                echo "<input type=\"submit\" id=\"Team7Button\" value=\"$name\">";
                echo "<input type=\"hidden\" name=\"team\" value=\"$team\">";
                echo "</form>";
                echo "</td>\n";
            } else {
                echo "<td>$name</td>";
            }

            echo "<td class=\"$classt\">$player_list</td>";
            echo "<td class=\"$classt\">$nb_player/7</td>";
            echo "</tr>\n";
            $idx++;
            $player_list = $data['pseudo'] . ", ";
            $name        = $data['name'];
            $team        = $data['team_idx'];
            $nb_player   = 1;
        }
    }
    $class = $tr_class[$idx % 2];

    $player_list = substr($player_list, 0, -2);
    echo "<tr class=\"$class\">";
    if ($top7team == 0 and $nb_player < 7) {
        echo "<td class=\"$classt\">";
        echo "<form id=\"form_team\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\" id=\"Team7Button\" value=\"$name\">";
        echo "<input type=\"hidden\" name=\"team\" value=\"$team\">";
        echo "</form>";
        echo "</td>\n";
    } else {
        echo "<td class=\"$classt\">$name</td>";
    }

    echo "<td class=\"$classt\">$player_list</td>";
    echo "<td class=\"$classt\">$nb_player/7</td>";
    echo "</tr>\n";

    if ($top7team == 0) {
        $idx++;
        $class = $tr_class[$idx % 2];

        $size = 30;
        echo "<form id=\"form_team\" action=\"$action\" method=\"post\">\n";
        $placeholder = "Nouvelle équipe";
        echo "<tr class=\"$class\">";
        echo "<td><input class=\"login\" type=\"text\" size=\"$size\" name=\"new_team\" placeholder=\"$placeholder\"></td>";
        echo "<td class=\"$classt\"></td>";
        echo "<td class=\"$classt\"></td>";
        echo "</tr>\n";
        echo "</form>\n";
    }
    echo "</table>\n";
}

function init_deadline()
{

    if (isset($_SESSION['deadline'])) {
        $deadline = $_SESSION['deadline'];
        $t        = $deadline - now();
        if ($t > 0) {
            print_header_display($t);
        } else {
            print_header();
        }
    } else {
        print_header();
    }
}

function get_info_status_player($p)
{

    $today  = $p['today'];
    $pseudo = $p['pseudo'];
    $game   = $p['game'];
    $player = $p['player'];

    if ($today <= c_last_day) {

        if ($game == c_enable) {
            $info = "c'est à toi de jouer.";
        }

        if ($game == c_disable) {
            $info       = "c'est à toi de jouer dans <span id=\"ct\"></span>";
            $selections = get_top7_day_selection($today, $p);
            $previous   = array();
            foreach ($selections as $selection) {
                if ($selection['registered'] == $player) {
                    break;
                }

                if ($selection['prono'] == c_not_played) {
                    $previous[] = $selection['pseudo'];
                }
            }
            if ($i = count($previous)) {
                $info .= " ou après ";
                switch ($i) {
                    case 1:
                        $info .= $previous[0];
                        break;
                    case 2:
                        $info .= $previous[0] . " et " . $previous[1];
                        break;
                    default:
                        $info .= $previous[0] . ", " . $previous[1] . ", ..";
                        break;
                }
                $info .= ".";
            }
        }
    } else {

        $phase = 0;
        if (isset($p['phase'])) {
            $phase = $p['phase'];
        }

        $status = 0;
        if (isset($p['status'])) {
            $status = $p['status'];
        }

        $info = "pas de jeu pour toi tu es qualifié directement en 1/2 finale.";
        if ($phase == 0 and $status == c_can_play) {
            $info = "c'est à toi de jouer, tu as la main jusqu'à mercredi minuit.";
        }

        if ($phase == 0 and $status == c_cannot_play) {
            $info = "tu n'as pas la main jusqu'à mercredi minuit.";
        }

        if ($phase == 1 and $status == c_can_play) {
            $info = "tu reprends la main, à toi de jouer.";
        }

        if ($phase == 1 and $status == c_cannot_play) {
            $info = "tu n'as plus la main.";
        }

        if ($status == c_no_more_selected) {
            $info = "la saison est finie.";
        }
    }
    $info = "$pseudo, $info";
    return $info;
}

function get_selection_order($p)
{

    $today = $p['today'];

    $title  = get_day_title($today);
    $status = c_msg_game_in_progress;
    $class  = "opened";
    $ret    = "";

    // table.status
    $style = "font-family: Verdana, sans-serif; font-size: small; border-collapse: collapse; background-color: #FAFAE0; width: 90%;";
    $ret .= "<table style=\"$style\">\n";

    // th.opened
    $style = "background-color: #FAFAE0; color: green; text-align: center;";
    $ret .= "<tr><th colspan=\"2\" style=\"$style\">$title - $status</th></tr>\n";
    $format   = "%A %d %b %H:%M";
    $end_game = "(Jusqu'à " . utf8_encode(strftime($format, $p['time_game_closed'])) . ")";

    // td.status
    $style1 = "background-color: #FAFAE0; color: black; text-align: center; font-weight: bold;";
    $style2 = "background-color: #FAFAE0; color: black; text-align: center; font-style: italic;";
    $ret .= "<tr><td style=\"$style1\">Ordre des sélections</a></td><td style=\"$style2\">$end_game</td></tr>\n";

    $selections = get_top7_day_selection($today, $p);
    $i          = 0;
    $style2     = "padding-left: 10px;";
    foreach ($selections as $selection) {

        // tr.odd tr.even
        if ($i % 2) {
            $style1 = "background-color: #FAFAE0;";
        } else {
            $style1 = "background-color: #D8D8D8;";
        }

        if ($selection['status'] == c_not_selected) {
            continue;
        }

        $info = $selection['info'];
        if ($selection['deadline'] == 0) {
            $info = "(à partir de maintenant)";
        }

        if ($i == 0) {
            $info = "(à partir de maintenant)";
        } else {
            if ($today <= c_last_day) {
                $info = substr($info, 0, -1) . "*)";
            }
        }
        $i++;
        $ret .= "<tr style=\"$style1\">\n";
        $ret .= "<td colspan=\"2\" style=\"$style2\">$i - " . $selection['pseudo'] . " $info</td>\n";
        $ret .= "</tr>\n";
    }
    $ret .= "</table>\n";

    if ($today <= c_last_day) {
        $ret .= " (*) ou dès que tous ses prédécesseurs ont déjà joué.";
    }

    return $ret;
}

function get_prono_player($p)
{

    global $tr_class;

    $today    = $p['today'];
    $day      = $p['day'];
    $top7team = $p['top7team'];
    $season   = $p['season'];

    $title  = get_day_title($today);
    $status = c_msg_game_closed;
    $class  = "closed";

    // table.status
    $style = "font-family: Verdana, sans-serif; font-size: small; border-collapse: collapse; background-color: #FAFAE0; width: 90%;";
    $ret   = "<table style=\"$style\">\n";

    // th.closed
    $style = "background-color: #FAFAE0; color: #ff4500; text-align: center;";
    $ret .= "<tr><th colspan=\"3\" style=\"$style\">$title - $status</th></tr>\n";

    $score_players = get_score_players($day, $season, $top7team);
    $matchs        = get_matchs_by_date($day, $season);

    $playerclass = "padding-left: 10px;";
    $idx         = 0;
    foreach ($matchs as $match) {
        $localclass = $visiteurclass = "team";
        $localclass = $visiteurclass = "text-align: center;";
        foreach ($score_players as $score_player) {
            if ($score_player['team'] == $match['team1']) {
                $localselected = true;
                $localclass    = "top7selected";
                $localclass    = "color: #ff6600; text-align: center; font-weight: bold;";
                $sc_player     = $score_player;
            }
            if ($score_player['team'] == $match['team2']) {
                $visiteurselected = true;
                $visiteurclass    = "top7selected";
                $visiteurclass    = "color: #ff6600; text-align: center; font-weight: bold;";
                $sc_player        = $score_player;
            }
        }
        $pseudo   = $sc_player['pseudo'];
        $local    = $match['local'];
        $visiteur = $match['visiteur'];

        // tr.odd tr.even
        if ($idx % 2) {
            $style = "background-color: #FAFAE0;";
        } else {
            $style = "background-color: #D8D8D8;";
        }

        $ret .= "<tr style=\"$style\">\n";
        $ret .= "<td style=\"$playerclass\">&nbsp;$pseudo</td>\n";
        $ret .= "<td style=\"$localclass\">$local</td>";
        $ret .= "<td style=\"$visiteurclass\">$visiteur</td>";
        $ret .= "</tr>";
        $idx++;
    }
    $ret .= "</table>";

    return $ret;
}

function put_status($p)
{

    printr_log(__FUNCTION__, "SESSION", $p);

    $player = 0;
    if (isset($p['player'])) {
        $player = $p['player'];
    }

    $display = 0;
    if (isset($p['display'])) {
        $display = $p['display'];
    }

    $pseudo = "?";
    if (isset($p['pseudo'])) {
        $pseudo = $p['pseudo'];
    }

    $game = 0;
    if (isset($p['game'])) {
        $game = $p['game'];
    }

    $deadline = 0;
    if (isset($p['deadline'])) {
        $deadline = $p['deadline'];
    }

    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    $today = 0;
    if (isset($p['today'])) {
        $today = $p['today'];
    }

    $season = 0;
    if (isset($p['season'])) {
        $season = $p['season'];
    }

    $status  = "";
    $status1 = "";
    if ($game == c_validated) {
        $status  = c_msg_game_in_progress;
        $class   = "opened";
        $status1 = "$pseudo les jeux sont faits pour toi !";
    }

    if ($game == c_enable) {
        $status  = c_msg_game_in_progress;
        $class   = "opened";
        $status1 = get_info_status_player($p);
        if (isset($p['selected_team']) and $display == c_top7_player) {
            $status1 = "Ne pas oublier de valider le prono !";
        }
    }

    if ($game == c_disable) {
        $status = c_msg_game_not_opened;
        $class  = "notopened";
        $now    = now();
        $diff   = $deadline - $now;
        if ($diff > 0) {
            $status  = c_msg_game_in_progress;
            $class   = "opened";
            $status1 = get_info_status_player($p);
        }
    }

    if ($game == c_game_over) {
        $status  = "Les jeux sont terminés.";
        $class   = "notopened";
        $status1 = get_info_status_player($p);
    }

    if ($game_closed = check_game_closed($top7team, $today)) {
        $status  = c_msg_game_closed;
        $class   = "closed";
        $status1 = "";
    }

    if ($game == c_not_opened) {
        $status = c_msg_game_not_opened;
        $class  = "notopened";
    }

    if ($game == c_season_over) {
        $top7_season = get_top7_season_by_id($p['season']);
        $status      = "La " . strtolower($top7_season['title']) . " est terminée";
        $class       = "notopened";
        $status1     = "";
    }

    print_log(__FUNCTION__, "game", $game);
    print_log(__FUNCTION__, "status", $status);

    if (strlen($status)) {

        $title = get_day_title($today);
        echo "<table class=\"status\">\n";
        if ($game == c_season_over) {
            echo "<tr><th class=\"$class\">$status</th></tr>\n";
        } else {
            echo "<tr><th class=\"$class\">$title - $status</th></tr>\n";
        }

        if (strlen($status1)) {
            echo "<tr><td class=\"status\"><i>$status1</i></td></tr>\n";
        }

        echo "</table>\n";

        if ($status == c_msg_game_in_progress) {
            $format   = "%A %d %b %H:%M";
            $end_game = "(Jusqu'à " . utf8_encode(strftime($format, $p['time_game_closed'])) . ")";
        } else {
            $end_game = "";
        }

        if ($game != c_season_over) {

            echo "<table class=\"status\">\n";
            echo "<tr><td></td><td class=\"status\"><a class=\"status\" href=\"javascript:unhide('status');\">Ordre des sélections</a></td><td class=$class><i>$end_game</i></td></tr>\n";
            echo "</table>\n";

            #$selections = get_top7_day_selection( $today, $p);
            # ticket #110
            $day = $p['day'];
            if ($day == 1) {
                $selections = get_top7_day_selection($day, $p);
                printr_log(__FUNCTION__, "selection 1st day", $selections);
            }
            # TODO A revoir
            elseif ($day < $today) {
                $selections = get_top7_day_selection($day - 1, $p);
            } elseif ($day == $today) {
                $selections = get_top7_day_selection($today, $p);
            } elseif ($day > $today) {
                $selections = array();
            }

            $i = 0;
            echo "<div id=\"status\" class=\"hidden\">\n";
            echo "<table class=\"status\">\n";
            foreach ($selections as $selection) {
                if ($selection['status'] == c_not_selected) {
                    continue;
                }

                $i++;
                echo "<tr>\n";
                if ($selection['prono'] == c_played) {
                    echo "<td class=\"alreadyplayed\">$i - " . $selection['pseudo'] . "</td>\n";
                } elseif ($selection['status'] == c_cannot_play) {
                    echo "<td class=\"cannotplay\">$i - " . $selection['pseudo'] . " " . $selection['info'] . "</td>\n";
                } elseif ($selection['status'] == c_can_play) {
                    echo "<td class=\"canplay\">$i - " . $selection['pseudo'] . "</td>\n";
                } else {
                    echo "<td class=\"status\">$i - " . $selection['pseudo'] . "</td>\n";
                }

                echo "</tr>\n";
            }
            echo "</table>\n";
            echo "</div>\n";
        }
    }
    //echo "<br>\n";

}

function display($p)
{
    $f = "display";

    printr_log(__FUNCTION__, "display(p)", $p);

    $day = 0;
    if (isset($p['day'])) {
        $day = $p['day'];
    }

    $season = 0;
    if (isset($p['season'])) {
        $season = $p['season'];
    }

    $player = 0;
    if (isset($p['player'])) {
        $player = $p['player'];
    }

    $pseudo = "?";
    if (isset($p['pseudo'])) {
        $pseudo = $p['pseudo'];
    }

    $display = 0;
    if (isset($p['display'])) {
        $display = $p['display'];
    }

    $mode = 0;
    if (isset($p['mode'])) {
        $mode = $p['mode'];
    }

    $game = 0;
    if (isset($p['game'])) {
        $game = $p['game'];
    }

    $status = 0;
    if (isset($p['status'])) {
        $status = $p['status'];
    }

    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    $selected_team = 0;
    if (isset($p['selected_team'])) {
        $selected_team = $p['selected_team'];
    }

    $top14team = 0;
    if (isset($p['top14team'])) {
        $top14team = $p['top14team'];
    }

    $top7_player = 0;
    if (isset($p['top7_player'])) {
        $top7_player = $p['top7_player'];
    }

    $player_idx = 0;
    if (isset($p['player_idx'])) {
        $player_idx = $p['player_idx'];
    }

    $player1 = 0;
    if (isset($p['player1'])) {
        $player1 = $p['player1'];
    }

    $player2 = 0;
    if (isset($p['player2'])) {
        $player2 = $p['player2'];
    }

    global $tr_class;
    global $strDate;

    $matchs = get_matchs_by_date($day, $season);


    if ($display == c_top7) {
        $pronos        = get_pronos($day, $top7team);
        $score_players = get_score_players($day, $season, $top7team);
        if ($day > c_last_day) {
            $barrage_players = get_top7_day_selection($day, $p);
            printr_log(__FUNCTION__, "barrage_players", $barrage_players);
            $matchs          = get_matchs_by_rank($day, $season);
            $reverses = array_reverse($matchs);
            $matchs = $reverses;
        }
    }

    if ($display == c_top7_player) {
        if ($day > c_last_day) {
            $matchs          = get_matchs_by_rank($day, $season);
            $reverses = array_reverse($matchs);
            $matchs = $reverses;
            $barrage_players = get_top7_day_selection($day, $p);
            $score_players   = get_score_players($day, $season, $top7team);
            if ($status != c_can_play) {
                $display = c_top7;
            }
        } else {
            $nbteams_team1 = get_nb_different_teams($day, $season, $player, 1);
            $nbteams_team2 = get_nb_different_teams($day, $season, $player, 2);
        }
        $pronos = get_pronos($day, $top7team);
    }

    if ($display == c_team14) {
        $matchs = get_team14_matchs($top14team, $season);
    }

    if ($display == c_top7_match) {
        $matchs       = get_top7_matchs($top7_player, $season);
        $pronos       = get_top7_pronos($top7_player);
        $score_player = get_score_player($top7_player);
    }

    $player_name = "";
    if ($display == c_top7) {
        $name = "Joueur";
    }

    if ($display == c_top7_player) {
        $player_name = get_pseudo_from_player($player);
    }

    if ($game == c_enable) {
        $name = $pseudo;
    }

    $next = 0;
    if ($display == c_top14) {
        $next = c_top7;
    }

    if ($display == c_top7) {
        $next = c_top14;
    }

    $_SESSION['next'] = $next;

    $title  = "";
    $left   = $right   = "";
    $action = "display";

    if ($display == c_top14) {
        $class    = "top14";
        $idbutton = "Rank14Button";
        $title    = "TOP14 - " . get_day_title($day);
        $left     = "<form id=\"form_nav_L\" action=\"$action\" method=\"post\">\n";
        $left .= "<input type=\"submit\" id=\"$idbutton\" name=\"prev\" value=\"<<\">\n";
        $left .= "</form>\n";
        $right = "<form id=\"form_nav_R\" action=\"$action\" method=\"post\">\n";
        $right .= "<input type=\"submit\" id=\"$idbutton\" name=\"next\" value=\">>\">\n";
        $right .= "</form>\n";
    }

    if ($display == c_team14) {
        $class = "top14";
        $title = get_team14_name($top14team, $season);
    }

    if ($display == c_top7_match) {
        $class = "top7";
        $title = get_pseudo_from_player($top7_player);
    }

    if ($display == c_top7) {
        $class    = "top7";
        $idbutton = "Rank7Button";
        $left     = "<form id=\"form_nav_L\" action=\"$action\" method=\"post\">\n";
        $left .= "<input type=\"submit\" id=\"$idbutton\" name=\"prev\" value=\"<<\">\n";
        $left .= "</form>\n";
        $right = "<form id=\"form_nav_R\" action=\"$action\" method=\"post\">\n";
        $right .= "<input type=\"submit\" id=\"$idbutton\" name=\"next\" value=\">>\">\n";
        $right .= "</form>\n";
        $title = get_top7_title($day);
    }

    if ($display == c_top7_player) {
        $class    = "top7";
        $idbutton = "Rank7Button";
        $title    = get_top7_title($day);
    }

    // Line 1 :   <<     $title      >>
    // -----------------------------------------------
    echo "<table class=\"day\">\n";
    echo "<tr>\n";
    echo "<th class=\"$class\">$left</th>\n";
    echo "<th class=\"$class\">$title</th>\n";
    echo "<th class=\"$class\">$right</th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    if ($display == c_top14) {
        $class1 = $class2 = $class3 = "top14";
        $title  = "score";
        $span   = 3;
        $class0 = "top14";
    }
    if ($display == c_team14) {
        $class2 = "top14";
        $class1 = $class3 = "top14team";
        $title  = "score";
        $span   = 3;
        $class0 = "top14";
    }
    if ($display == c_top7_match) {
        $class1 = $class3 = "top7team";
        $class2 = "top7";
        $title  = "score";
        $span   = 3;
        $class0 = "top7";
    }
    if ($display == c_top7) {
        $class = $class1 = $class2 = $class3 = "top7";
        $title = "score";
        $span  = 3;
        if ($day > c_last_day) {
            $class = $class1 = $class3 = "top7player";
        }

        $class0 = "top7";
    }
    if ($display == c_top7_player) {
        $class1 = $class3 = "top7";
        $class2 = "update";
        $title  = $player_name;
        $span   = 1;
        if ($day > c_last_day) {
            $class = $class1 = $class3 = "top7player";
        }

        $class0 = "top7";
    }

    // Line 2 :   Joueur PTS Domicile      score       Exterieur
    // Line 2 :   Joueur     Domicile      score       Exterieur   Joueur
    // ------------------------------------------------------------------
    echo "<table class=\"day\" border=0>\n";
    echo "<tr>\n";

    if ($display == c_top7_player) {
        if ($day > c_last_day) {
            echo "<th class=\"$class\">Joueur</th>\n";
        }
    }

    if ($display == c_top7) {
        if ($day > c_last_day) {
            echo "<th class=\"$class\">Joueur</th>\n";
        } else {
            echo "<th class=\"playertop7\">&nbsp;Joueur</th>\n";
            echo "<th class=\"$class\">PTS</th>\n"; // PTS
            echo "<th class=\"$class\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</th>\n"; // icons
            echo "<th class=\"$class\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</th>\n"; // Nb Eq
        }
    }
    echo "<th class=\"$class1\">" . str_repeat("&nbsp;", 6) . "Domicile" . str_repeat("&nbsp;", 5) . "</th>\n";
    if ($display == c_top7 or $display == c_top14 or $display == c_team14 or $display == c_top7_match) {
        echo "<th class=\"$class0\">&nbsp;</th>";
    }

    echo "<th class=\"$class2\">$title</th>";
    if ($display == c_top7 or $display == c_top14 or $display == c_team14 or $display == c_top7_match) {
        echo "<th class=\"$class0\">&nbsp;</th>";
    }

    echo "<th class=\"$class3\">" . str_repeat("&nbsp;", 5) . "Extérieur" . str_repeat("&nbsp;", 5) . "</th>\n";

    if ($display == c_top7_player) {
        if ($day > c_last_day) {
            echo "<th class=\"$class\">Joueur</th>\n";
        }
    }

    if ($display == c_top7) {
        if ($day > c_last_day) {
            echo "<th class=\"$class\">Joueur</th>\n";
        } else {
            echo "<th class=\"$class\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</th>\n"; // Nb Eq
        }
    }

    if ($display == c_top7_match) {
        echo "<th class=\"$class0\">PTS</th>\n"; // PTS
        echo "<th class=\"$class0\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</th>\n"; // icons
        echo "<th class=\"$class0\">Eq</th>\n"; // Nb Eq
    }
    echo "</tr>\n";

    $idx           = 1;
    $prev_datetime = "";

    foreach ($matchs as $match) {

        $localselected = $visiteurselected = false;
        $localwinner   = $visiteurwinner   = false;
        $localclass    = $visiteurclass    = "team";
        $top7icon      = "";
        $playerclass   = "playerselected";
        $playerclass1  = $playerclass2  = "top7selected";

        $score1  = $match['score1'];
        $score2  = $match['score2'];
        $v1      = $match['v1'];
        $v2      = $match['v2'];
        $team1   = $match['team1'];
        $team2   = $match['team2'];
        $detail1 = array("try" => $match['try1'], "bo" => $match['bo1'], "bd" => $match['bd1']);
        $detail2 = array("try" => $match['try2'], "bo" => $match['bo2'], "bd" => $match['bd2']);

        if ($display == c_top14 or $display == c_team14 or $display == c_top7_match) {
            $datetime = utf8_encode(strftime($strDate, strtotime($match['date'] . " " . $match['time'])));
            $top_day  = "";
            if ($display == c_team14 or $display == c_top7_match) {
                if ($match['day'] > c_last_day) {
                    $top_day = get_day_title($match['day']) . " - ";
                } else {
                    $top_day = "J" . $match['day'] . " - ";
                }
            }
            if ($datetime != $prev_datetime) {
                #echo "<tr><td class=\"date\" colspan=\"5\">$top_day $datetime</td></tr>\n";
                $prev_datetime = $datetime;
            }
            echo "<tr><td class=\"date\" colspan=\"5\">$top_day $datetime</td></tr>\n";
        }

        if ($display == c_top14 and $mode == c_admin) {
            $action = "display_update_match";
            $url    = $action . "?season=$season&day=$day&team1=$team1&team2=$team2";
        }

        if ($display == c_top14 or $display == c_team14 or $display == c_top7_match or $display == c_top7) {

            if ($score1 > $score2 or $v1) {
                $localwinner = true;
            }

            if ($score1 < $score2 or $v2) {
                $visiteurwinner = true;
            }

            if ($display == c_top14 or $display == c_team14) {
                if ($score1 > $score2 or $v1) {
                    $localclass = "top14winner";
                }

                if ($score1 < $score2 or $v2) {
                    $visiteurclass = "top14winner";
                }
            }

            if ($day > c_last_day) {
                $d1 = get_score_details_nobonus($detail1);
                $d2 = get_score_details_nobonus($detail2);
            } else {
                $d1 = get_score_details($detail1);
                $d2 = get_score_details($detail2);
            }
            $score = $match['score1'];
            $score .= " - ";
            $score .= $match['score2'];
        }

        if ($display == c_top7_match) {
            if ($pronos[$match['day']]['team'] == $match['team1']) {
                $localselected = true;
                $localclass    = "top7selected";
                if ($match['bo1']) {
                    $top7icon = c_icon_rugby;
                }

                if ($match['bo2']) {
                    $top7icon   = c_icon_coiffeur;
                    $localclass = "top7loser";
                }
            } else {
                $visiteurselected = true;
                $visiteurclass    = "top7selected";
                if ($match['bo2']) {
                    $top7icon = c_icon_rugby;
                }

                if ($match['bo1']) {
                    $top7icon      = c_icon_coiffeur;
                    $visiteurclass = "top7loser";
                }
            }
            $player_point = $score_player[$match['day']]['pt'];
            if ($player_point == 0 and ($score1 > 0 or $score2 > 0)) {
                $playerclass = "playerloser";
                if ($localselected) {
                    $localclass = "top7loser";
                }

                if ($visiteurselected) {
                    $visiteurclass = "top7loser";
                }
            }
            $player_eq = $score_player[$match['day']]['ne'];
            if ($match['score1'] == 0 and $match['score2'] == 0) {
                $player_point = "";
            }
        }

        if ($display == c_top7_player) {
            if ($day > c_last_day) {
                $pseudo1 = $pseudo2 = "";
                foreach ($barrage_players as $default_player) {
                    $i = $default_player['idx']; // see idx_barrage_day, idx_demifinales_day, idx_finale_day
                    if ($pseudo1 == "" and $i == $idx) {
                        $pseudo1 = $default_player['pseudo'];
                    } elseif ($pseudo2 == "" and $i == $idx) {
                        $pseudo2 = $default_player['pseudo'];
                    }
                    printr_log(__FUNCTION__, "default_player", $default_player);
                    print_log(__FUNCTION__, "pseudo1", $pseudo1);
                    print_log(__FUNCTION__, "pseudo2", $pseudo2);
                }
                $playerclass1 = $playerclass2 = "top7player_default";
                if ($day == c_finale_day) {
                    $pseudo1 = $barrage_players[0]['pseudo'];
                    $pseudo2 = $barrage_players[1]['pseudo'];
                }

                $action         = "update_prono";
                $url            = $action . "?season=$season&day=$day&player=$player";
                $name           = "";
                $selected_prono = array();
                printr_log(__FUNCTION__, "pronos", $pronos);
                // TODO 
                foreach ($pronos as $prono) {
                    if ($match['team1'] == $prono['tm']) {
                        $pseudo1 = $prono['pl'];
                    }
                    if ($match['team2'] == $prono['tm']) {
                        $pseudo2 = $prono['pl'];
                    }
                    if ($player == $prono['player']) {
                        $selected_prono = $prono;
                    }
                }
                print_log(__FUNCTION__, "- pseudo1", $pseudo1);
                print_log(__FUNCTION__, "- pseudo2", $pseudo2);
                if ($match['team1'] == $selected_team) {
                    $pseudo1 = $pseudo;
                    $pseudo2 = get_pseudo_from_player($player2);
                }
                if ($match['team2'] == $selected_team) {
                    $pseudo2 = $pseudo;
                    $pseudo1 = get_pseudo_from_player($player2);
                }
                print_log(__FUNCTION__, "-- pseudo1", $pseudo1);
                print_log(__FUNCTION__, "-- pseudo2", $pseudo2);
                if (count($selected_prono) and (
                    ($match['team1'] == $selected_prono['tm'] or
                        $match['team2'] == $selected_prono['tm']))) {
                    $name = $selected_prono['pl'];
                }

                if (count($pronos)) {
                    $playerclass1 = $playerclass2 = "top7selected";
                }
            } else {
                $action = "update_prono";
                $url    = $action . "?season=$season&day=$day&player=$player";
                $name   = "";
                foreach ($pronos as $prono) {
                    if ($match['team1'] == $prono['tm']) {
                        $name .= $prono['pl'];
                        $name .= ",";
                        $localselected = true;
                        $localclass    = "top14winner";
                        #$localwinner = true;
                    }
                    if ($match['team2'] == $prono['tm']) {
                        $name .= $prono['pl'];
                        $name .= ",";
                        $visiteurselected = true;
                        $visiteurclass    = "top14winner";
                        #$visiteurwinner = true;
                    }
                }
                $name          = substr($name, 0, -1);
                $nb_team_team1 = $nbteams_team1[$match['team1']];
                $nb_team_team2 = $nbteams_team2[$match['team2']];
            }
        }

        if ($display == c_top7) {
            if ($day > c_last_day) {
                $pseudo1 = $pseudo2 = "";
                foreach ($barrage_players as $default_player) {
                    $i = $default_player['idx']; // see idx_barrage_day, idx_demifinales_day, idx_finale_day
                    if ($pseudo1 == "" and $i == $idx) {
                        $pseudo1 = $default_player['pseudo'];
                    } elseif ($pseudo2 == "" and $i == $idx) {
                        $pseudo2 = $default_player['pseudo'];
                    }
                }
                if ($day == c_finale_day) {
                    $pseudo1 = $barrage_players[0]['pseudo'];
                    $pseudo2 = $barrage_players[1]['pseudo'];
                }
                $playerclass1 = $playerclass2 = "top7player_default";
                foreach ($score_players as $score_player) {
                    if ($score_player['team'] == $match['team1']) {
                        $localselected = true;
                        $playerclass1  = $localclass  = "top7selected";
                        $pseudo1       = $score_player['pseudo'];
                    }
                    if ($score_player['team'] == $match['team2']) {
                        $visiteurselected = true;
                        $playerclass2     = $visiteurclass     = "top7selected";
                        $pseudo2          = $score_player['pseudo'];
                    }
                }
                if ($score1 > 0 or $score2 > 0) {
                    if ($localwinner) {
                        $playerclass1 = $localclass = "top7winner";
                        $playerclass2 = $visiteurclass = "top7loser";
                    } else {
                        $playerclass1 = $localclass = "top7loser";
                        $playerclass2 = $visiteurclass = "top7winner";
                    }
                }
            } else {
                $sc_player['pseudo'] = "";
                $sc_player['pt']     = "";
                $sc_player['ne']     = 0;
                foreach ($score_players as $score_player) {
                    if ($score_player['team'] == $match['team1']) {
                        $localselected = true;
                        $localclass    = "top7selected";
                        $sc_player     = $score_player;
                        if ($match['bo1']) {
                            $top7icon = c_icon_rugby;
                        }

                        if ($match['bo2']) {
                            $top7icon    = c_icon_coiffeur;
                            $localclass  = "top7loser";
                            $playerclass = "playercoiffeur";
                        }
                    }
                    if ($score_player['team'] == $match['team2']) {
                        $visiteurselected = true;
                        $visiteurclass    = "top7selected";
                        $sc_player        = $score_player;
                        if ($match['bo2']) {
                            $top7icon = c_icon_rugby;
                        }

                        if ($match['bo1']) {
                            $top7icon      = c_icon_coiffeur;
                            $visiteurclass = "top7loser";
                            $playerclass   = "playercoiffeur";
                        }
                    }
                }
                $pseudo     = $sc_player['pseudo'];
                $player_eq1 = "";
                $player_eq2 = "";
                if ($sc_player['ne'] and $localselected) {
                    $player_eq1 = "(" . $sc_player['ne'] . ")";
                }

                if ($sc_player['ne'] and $visiteurselected) {
                    $player_eq2 = "(" . $sc_player['ne'] . ")";
                }

                $player_point = $sc_player['pt'];
                if ($player_point == 0 and ($score1 > 0 or $score2 > 0)) {
                    $playerclass = "playerloser";
                    if ($localselected) {
                        $localclass = "top7loser";
                    }

                    if ($visiteurselected) {
                        $visiteurclass = "top7loser";
                    }
                }
                if ($match['score1'] == 0 and $match['score2'] == 0) {
                    $player_point = "";
                }
            }
        }

        if ($localselected and $localwinner) {
            $playerclass = "playerwinner";
        }

        if ($visiteurselected and $visiteurwinner) {
            $playerclass = "playerwinner";
        }

        $local = $match['local'];

        if ($score1 or $score2) {
            if ($score1 > $score2 and $localselected) {
                $localclass = "top7winner";
            }

            if ($score1 < $score2 and $visiteurselected) {
                $visiteurclass = "top7winner";
            }
        }

        if ($display == c_top7_player and $mode == c_admin) {
            $url1  = $url . "&team=$team1";
            $local = "<a href=\"$url1\">$local</a>";
        }

        if ($display == c_top7_player and strlen($name) == 0 and $game == c_enable and $status == c_can_play) {
            $action = "display";
            if ($day > c_last_day and $player_idx == $idx) {
                $playerclass1 = $playerclass2 = "top7selected";
            }

            if ($selected_team == $team1) {
                $local = "<b>$local</b>";
            } else {
                if ($day <= c_last_day or ($day > c_last_day and $player_idx == $idx)) {
                    $local = get_button("l_button$idx", $match['local'], $action, array("selected_team" => $team1, "contested_team" => $team2), $nb_team_team1);
                }
            }
        }
        print_log(__FUNCTION__, "** pseudo1", $pseudo1);
        print_log(__FUNCTION__, "** pseudo2", $pseudo2);

        $class = $tr_class[$idx % 2];

        // Line 3 :   Joueur PTS Domicile      score       Exterieur
        // Line 3 :   Joueur     Domicile      score       Exterieur   Joueur
        // ------------------------------------------------------------------
        echo "<tr class=\"$class\">\n";

        // Line 3... : Column 0
        if ($display == c_top7_player) {
            if ($day > c_last_day) {
                echo "<td class=\"$playerclass1\">&nbsp;$pseudo1</td>\n";
            }
        }

        if ($display == c_top7) {
            if ($day > c_last_day) {
                echo "<td class=\"$playerclass1\">&nbsp;$pseudo1</td>\n";
            } else {
                echo "<td class=\"$playerclass\">&nbsp;$pseudo</td>\n";
                echo "<td class=\"$playerclass\" align=\"center\">$player_point</td>\n";
                echo "<td class=\"top7icon\">$top7icon</td>\n";
                echo "<td class=\"top7player_eq\">$player_eq1</td>\n";
            }
        }

        // Line 3... : Column 1
        echo "<td class=\"$localclass\">$local</td>";

        // Line 3... : Column 2
        if ($display == c_top14 or $display == c_team14 or $display == c_top7_match or $display == c_top7) {
            echo "<td class=\"top14scoredetail\">$d1</td>";
        }

        if ($display == c_top14 or $display == c_team14) {
            echo "<td class=\"top14score\">";
        } elseif ($display == c_top7) {
            echo "<td class=\"top7score\">";
        } else {
            echo "<td class=\"top7score\">";
        }

        if ($mode != c_admin) {
            if ($match['score1'] == 0 and $match['score2'] == 0) {
                $score = "";
            }
        }

        if ($mode == c_admin) {
            if ($display == c_top14) {
                echo "<a href=\"$url\">$score</a>";
            }

            if ($display == c_team14) {
                echo "$score";
            }

            if ($display == c_top7_match) {
                echo "$score";
            }

            if ($display == c_top7) {
                echo "$score";
            }

            if ($display == c_top7_player) {
                if ($name == $player_name) {
                    echo "<a href=\"$url&team=0\">$name</a>";
                } else {
                    echo "$name";
                }
            }
        }

        if ($mode == c_guest) {
            if ($display == c_top14 or $display == c_team14 or $display == c_top7_match or $display == c_top7) {
                echo "$score";
            }
        }

        if ($mode == c_player) {
            if ($game == c_disable or $game == c_season_over) {
                if ($display == c_top14 or $display == c_team14 or $display == c_top7_match or $display == c_top7) {
                    echo "$score";
                }
            }
            if ($game == c_enable) {
                if ($display == c_top7_player) {
                    if ($selected_team == $team1 or $selected_team == $team2) {
                        echo "$pseudo";
                    } else {
                        echo "$name";
                    }
                }
                if ($display == c_top14 or $display == c_team14 or $display == c_top7_match or $display == c_top7) {
                    echo "$score";
                }
            }
        }

        echo "</td>\n";

        if ($display == c_top14 or $display == c_team14 or $display == c_top7_match or $display == c_top7) {
            echo "<td class=\"top14scoredetail\">$d2</td>";
        }

        $visiteur = $match['visiteur'];

        if ($display == c_top7_player and $mode == c_admin) {
            $url2     = $url . "&team=$team2";
            $visiteur = "<a href=\"$url2\">$visiteur</a>";
        }

        if ($display == c_top7_player and strlen($name) == 0 and $game == c_enable and $status == c_can_play) {
            $action = "display";
            if ($selected_team == $team2) {
                $visiteur = "<b>$visiteur</b>";
            } else {
                if ($day <= c_last_day or ($day > c_last_day and $player_idx == $idx)) {
                    $visiteur = get_button("v_button$idx", $match['visiteur'], $action, array("selected_team" => $team2, "contested_team" => $team1), $nb_team_team2);
                }
            }
        }
        // Line 3... : Column 3
        echo "<td class=\"$visiteurclass\">$visiteur</td>";

        if ($display == c_top7_player) {
            if ($day > c_last_day) {
                echo "<td class=\"$playerclass2\">$pseudo2&nbsp;</td>\n";
            }
        }

        if ($display == c_top7) {
            if ($day > c_last_day) {
                echo "<td class=\"$playerclass2\">$pseudo2&nbsp;</td>\n";
            } else {
                echo "<td class=\"top7player_eq\">$player_eq2</td>\n";
            }
        }

        if ($display == c_top7_match) {
            echo "<td class=\"$playerclass\" align=\"center\">$player_point</td>\n";
            echo "<td class=\"top7icon\">$top7icon</td>\n";
            echo "<td class=\"top7player_eq\">$player_eq</td>\n";
        }

        echo "</tr>\n";

        $idx++;
    }
    echo "</table>\n";

    if (isset($p['selected_team']) and $display == c_top7_player) {
        echo "<table class=\"day\">\n";
        echo "<tr><td class=\"nav\">\n";
        $action = "update_prono_player";
        echo "<form id=\"form_play\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\"  id=\"ValidPronoButton\" value=\"Valider le prono\">\n";
        echo "</form>\n";
        echo "</td></tr>\n";
    }

    echo "</table>\n";
}

function display_select_calendar($teams, $team_idx, $team_nb, $id)
{

    $action = "calendar";
    echo "<form name=\"form_calendar\" id=\"AdminSelect\" action=\"$action\" method=\"post\">\n";
    echo "<select name=\"team\" id=\"AdminSelect\" onChange=\"if(this.value!='none') this.form.submit();\">\n";

    if ($team_idx) {
        foreach ($teams as $idx => $name) {
            $select = "";
            if ($team_idx == $idx) {
                $select = "selected=\"$selected\"";
            }

            echo "<option $select value=\"$idx\">$name</option>\n";
        }
    } else {
        echo "<option selected=\"selected\" value=\"none\">Select the team</option>\n";
        foreach ($teams as $idx => $name) {
            echo "<option value=\"$idx\">$name</option>\n";
        }
    }
    echo "<input type=\"hidden\" name=\"id\" value=\"$id\">\n";
    echo "<input type=\"hidden\" name=\"team_nb\" value=\"$team_nb\">\n";
    echo "</select>\n";
    echo "</form>\n";
}

function display_calendar_matchs($p)
{

    $day    = $p['day'];
    $season = $p['season'];

    $class    = "top14";
    $idbutton = "Rank14Button";
    $title    = "TOP14 - " . get_day_title($day);

    $teams = get_top14_teams($season);

    // Line 1 :        $title
    // -----------------------------------------------
    echo "<table class=\"day\">\n";
    echo "<tr>\n";
    echo "<th class=\"$class\">$title</th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    $title = "Date";
    $span  = 3;
    $class = "top14";

    // Line 2 :   Joueur PTS Domicile      score       Exterieur
    // Line 2 :   Joueur     Domicile      score       Exterieur   Joueur
    echo "<table class=\"day\" border=0>\n";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Domicile</th>";
    echo "<th class=\"$class\">$title</th>";
    echo "<th class=\"$class\">Extérieur</th>\n";
    echo "</tr>\n";

    $matchs = get_calendar_matchs($day, $season);
    //    echo "<pre>"; print_r($matchs); echo "</pre>";
    $idx = 1;
    foreach ($matchs as $match) {

        echo "<tr>\n";
        $local     = $match['local'];
        $visiteur  = $match['visiteur'];
        $date_time = $match['date'] . " " . $match['time'];
        $team1     = $match['team1'];
        $team2     = $match['team2'];
        $id        = $match['id'];

        // Line 3 :   Joueur PTS Domicile      score       Exterieur
        // Line 3 :   Joueur     Domicile      score       Exterieur   Joueur
        // ------------------------------------------------------------------

        echo "<td class=\"point\">$idx</td>\n";

        $class = "top14score";
        // Line 3... : Column 1
        echo "<td class=\"$class\">";
        display_select_calendar($teams, $team1, 1, $id);
        echo "</td>\n";
        // Line 3... : Column 2
        echo "<td class=\"$class\">$date_time</td>";
        // Line 3... : Column 3
        echo "<td class=\"$class\">";
        display_select_calendar($teams, $team2, 2, $id);
        echo "</td>\n";

        echo "</tr>\n";
        $idx++;
    }

    echo "</table>\n";
}

function display_update_match($p)
{

    $day    = $p['day'];
    $season = $p['season'];
    $team1  = $p['team1'];
    $team2  = $p['team2'];
    $query  = "select t1.team_long as local, t2.team_long as visiteur, ";
    $query .= "s1.pm as score1, s2.pm as score2, ";
    $query .= "s1.V as v1, s2.V as v2, ";
    $query .= "s1.em as try1, s2.em as try2, ";
    $query .= "s1.bo as bo1, s2.bo as bo2, ";
    $query .= "s1.bd as bd1, s2.bd as bd2, ";
    $query .= "team1, team2, date, time ";
    $query .= "from `match` as tm ";
    $query .= "left join `team` as t1 on t1.team_idx=tm.team1 and t1.season=$season ";
    $query .= "left join `team` as t2 on t2.team_idx=tm.team2 and t2.season=$season ";
    $query .= "left join `score` as s1 on s1.team=tm.team1 and s1.season=$season ";
    $query .= "left join `score` as s2 on s2.team=tm.team2 and s2.season=$season ";
    $query .= "where tm.day=$day and s1.day=$day and s2.day=$day ";
    $query .= "and tm.season=$season and t1.season=$season and t2.season=$season ";
    $query .= "and team1=$team1 and team2=$team2";
    $match = pdo_fetch(__FUNCTION__, c_one, $query);

    $score1   = $match['score1'];
    $score2   = $match['score2'];
    $v1       = $match['v1'];
    $v2       = $match['v2'];
    $try1     = $match['try1'];
    $try2     = $match['try2'];
    $date     = $match['date'];
    $time     = $match['time'];
    $local    = $match['local'];
    $visiteur = $match['visiteur'];

    $name   = "update_match";
    $action = "update_match";
    $title  = get_day_title($day);

    echo "<table class=\"update\">\n";
    echo "<tr>\n";
    echo "<td align=\"left\">";
    echo "<img src=" . c_logo_file . ">\n";
    echo "</td>\n";
    echo "</tr>\n";
    echo "<form id=\"$name\" name=\"$name\" method=\"post\" action=\"$action\">\n";
    echo "<input type=\"hidden\" name=\"season\" value=\"$season\">\n";
    echo "<input type=\"hidden\" name=\"day\" value=\"$day\">\n";
    echo "<input type=\"hidden\" name=\"team1\" value=\"$team1\">\n";
    echo "<input type=\"hidden\" name=\"team2\" value=\"$team2\">\n";
    echo "<tr><th class=\"top14\" colspan=\"8\">$title</th></tr>\n";
    echo "<tr><th class=\"top14\" rowspan=\"2\">Domicile</th><th class=\"update\" colspan=\"4\">Score</th><th class=\"top14\" rowspan=\"2\">Extérieur</th><th class=\"update\" rowspan=\"2\">Date</th><th class=\"update\" rowspan=\"2\">Time</th></tr>\n";
    echo "<tr><th class=\"update\">Essais</th><th class=\"update\">Points</th><th class=\"update\">Points</th><th class=\"update\">Essais</th></tr>\n";
    echo "<tr class=\"even\">\n";
    if ($day > c_last_day) {
        $checked = "";
        if ($v1) {
            $checked = "checked";
        }

        echo "<td class=\"team\"><input type=\"checkbox\" name=\"v1\" $checked>$local</td>\n";
    } else {
        echo "<td class=\"team\">$local</td>\n";
    }
    echo "<td align=\"center\"><input type=\"text\" name=\"try1\" size=\"2\" value=\"$try1\"></td>\n";
    echo "<td align=\"center\"><input type=\"text\" name=\"score1\" size=\"4\" value=\"$score1\"></td>\n";
    echo "<td align=\"center\"><input type=\"text\" name=\"score2\" size=\"4\" value=\"$score2\"></td>\n";
    echo "<td align=\"center\"><input type=\"text\" name=\"try2\" size=\"2\" value=\"$try2\"></td>\n";
    if ($day > c_last_day) {
        $checked = "";
        if ($v2) {
            $checked = "checked";
        }

        echo "<td class=\"team\"><input type=\"checkbox\" name=\"v2\" $checked>$visiteur</td>\n";
    } else {
        echo "<td class=\"team\">$visiteur</td>\n";
    }
    echo "<td align=\"center\"><input type=\"text\" name=\"date\" size=\"10\" value=\"$date\"></td>\n";
    echo "<td align=\"center\"><input type=\"text\" name=\"time\" size=\"8\" value=\"$time\"></td>\n";
    echo "</tr>\n";
    echo "<tr>\n";
    if ($day > c_last_day) {
        echo "<td>Cocher l'équipe gagnante en cas d'égalité pour la phase finale.</td>\n";
    }

    echo "</tr>\n";
    echo "</table>\n";
    echo "<input type=\"submit\" id=\"EnterButton\" name=\"button\" value=\"Entrer\">\n";
    echo "<input type=\"submit\" id=\"CancelButton\" value=\"Annuler\">\n";
    echo "</form>\n";
}

function update_point_fun($day, $season)
{

    $query = "select  player_idx as player, point, ve, pc, eq, d14 from player where season=$season";
    $rows  = pdo_fetch(__FUNCTION__, c_all, $query);
    $funs  = array();
    foreach ($rows as $row) {
        // fun : point fun
        $funs[$row['player']] = calcul_point_fun($row);
    }

    foreach ($funs as $player => $fun) {
        $query = "update `player` ";
        $query .= "set `fun`='$fun' ";
        $query .= "where `player_idx`='$player'";
        pdo_exec(__FUNCTION__, $query);
    }
}

function update_player_rank($day, $season)
{

    # TODO : to link to param button1
    $teams = get_top7_teams($season);
    foreach ($teams as $team) {
        $ranks = get_rank7($day, $season);
        $i     = 1;
        foreach ($ranks as $rank) {
            $idx   = $rank['player'];
            $query = "update `player` set rank=$i where `player_idx`=$idx";
            pdo_exec(__FUNCTION__, $query);
            $i++;
        }
    }
}

function update_d14($day, $season, $player)
{

    $query = "select d14 from player where player_idx=$player and season=$season";
    $row   = pdo_fetch(__FUNCTION__, c_one, $query);
    $d14   = $row['d14'];

    // ne : Nbre d'équipes différentes qui ont été sélectionnées
    $query = "select prono.player, count( distinct prono.team) as ne ";
    $query .= "from prono ";
    $query .= "left join player on prono.player=player.player_idx ";
    $query .= "join score on prono.team=score.team and prono.day=score.day ";
    $query .= "where score.j=1 and player.season=$season and prono.team > 0 and prono.day<=$day and player.player_idx=$player ";
    $query .= "group by prono.player ";
    $row = pdo_fetch(__FUNCTION__, c_one, $query);
    $ne  = $row['ne'];

    if (is_null($d14) and $ne == 14) {
        $query = "update `player` set `d14`=$day where `player_idx`=$player and `season`=$season";
        pdo_exec(__FUNCTIon__, $query);
    }

    if ($ne < 14) {
        $query = "update `player` set `d14`=NULL where `player_idx`=$player and `season`=$season";
        pdo_exec(__FUNCTIon__, $query);
    }
}

function update_equipe_differente($day, $season)
{

    // ne : Nbre d'équipes différentes qui ont été sélectionnées
    $query = "select prono.player, count( distinct prono.team) as ne ";
    $query .= "from prono ";
    $query .= "left join player on prono.player=player.player_idx ";
    $query .= "join score on prono.team=score.team and prono.day=score.day ";
    $query .= "where score.j=1 and player.season=$season and prono.team > 0 and prono.day<=$day ";
    $query .= "group by prono.player ";
    $rows = pdo_fetch(__FUNCTION__, c_all, $query);
    $pcs  = array();
    foreach ($rows as $row) {
        $eqs[$row['player']] = $row['ne'];
    }

    foreach ($eqs as $player => $eq) {
        $query = "update `player` ";
        $query .= "set `eq`='$eq' ";
        $query .= "where `player_idx`='$player'";
        pdo_exec(__FUNCTION__, $query);
    }
}

function update_point_coiffeur($day, $season)
{

    // pc : Points Coiffeur = BO de l'équipe non pronostiquée
    $query = "select pseudo, ";
    $query .= "player_idx as player, ";
    $query .= "sum(score.bo) as pc ";
    $query .= "from `player` join ( ";
    $query .= "	select * from ( ";
    $query .= "		select team1 as new_team, prono.day, prono.season, player  ";
    $query .= "		from `match` join `prono` on match.day=prono.day and match.season=prono.season ";
    $query .= "		where prono.team=team2 ";
    $query .= "		union  ";
    $query .= "		select team2 as new_team, prono.day, prono.season, player  ";
    $query .= "		from `match` join `prono` on match.day=prono.day and match.season=prono.season ";
    $query .= "		where prono.team=team1 ";
    $query .= "	) as tt ";
    $query .= "	order by day, player) as new_prono ";
    $query .= "on player_idx=new_prono.player ";
    $query .= "join `score` on new_prono.new_team=score.team and new_prono.day=score.day and new_prono.season=score.season ";
    $query .= "where score.day<=$day and player.season=$season ";
    $query .= "group by player_idx ";
    $rows = pdo_fetch(__FUNCTION__, c_all, $query);
    $pcs  = array();
    foreach ($rows as $row) {
        $pcs[$row['player']] = $row['pc'];
    }

    foreach ($pcs as $player => $pc) {
        $query = "update `player` ";
        $query .= "set `pc`='$pc' ";
        $query .= "where `player_idx`='$player'";
        pdo_exec(__FUNCTION__, $query);
    }
}

function update_evolution_player($day)
{

    $query = "select player, ";
    $query .= "sum(pc) as point, ";
    $query .= "sum(pm) as pm ";
    $query .= "from score left join prono using( day, team) ";
    $query .= "where prono.team > 0 and prono.day < $day ";
    $query .= "group by player ";
    $query .= "order by point desc, pm desc";
    $rank_befores = pdo_fetch(__FUNCTION__, c_all, $query);

    $query = "select player_idx as player, ";
    $query .= "point, pm, ";
    $query .= "team ";
    $query .= "from player ";
    $query .= "order by point desc, pm desc";
    $rank_nows = pdo_fetch(__FUNCTION__, c_all, $query);

    $evols = array();
    foreach ($rank_nows as $i_now => $rank_now) {
        $player = $rank_now['player'];
        foreach ($rank_befores as $i_before => $rank_before) {
            if ($rank_now['player'] == $rank_before['player']) {
                if ($i_now == $i_before) {
                    $evols[$player] = 0;
                }

                if ($i_now > $i_before) {
                    $evols[$player] = -1;
                }

                if ($i_now < $i_before) {
                    $evols[$player] = 1;
                }
            }
        }
    }

    foreach ($evols as $player => $evol) {
        $query = "update `player` ";
        $query .= "set `evo`='$evol' ";
        $query .= "where `player_idx`='$player'";
        pdo_exec(__FUNCTION__, $query);
    }
}

function get_prono_results($day, $season)
{

    $query = "select player, ";
    $query .= "sum(pc) as point, ";
    $query .= "sum(J) as j, ";
    $query .= "sum(V) as g, ";
    $query .= "sum(N) as n, ";
    $query .= "sum(D) as p, ";
    $query .= "sum(ve) as ve, ";
    $query .= "sum(pm) as pm, ";
    $query .= "sum(pe) as pe, ";
    $query .= "sum(bd) as bd, ";
    $query .= "sum(bo) as bo ";
    $query .= "from score left join prono using( day, team, season) ";
    $query .= "where prono.team > 0 ";
    $query .= "and prono.season=$season "; // Attention ce n'est que pour la saison courante
    $query .= "and prono.day<=$day ";
    $query .= "group by player ";
    $pronos = pdo_fetch(__FUNCTION__, c_all, $query);

    printr_log(__FUNCTION__, "pronos", $pronos);
    return $pronos;
}

function update_player_phase_reguliere($day, $season)
{

    $pronos = get_prono_results($day, $season);
    foreach ($pronos as $prono) {
        $point  = $prono["point"];
        $player = $prono["player"];
        $j      = $prono["j"];
        $g      = $prono["g"];
        $n      = $prono["n"];
        $p      = $prono["p"];
        $ve     = $prono["ve"];
        $pm     = $prono["pm"];
        $pe     = $prono["pe"];
        $bd     = $prono["bd"];
        $bo     = $prono["bo"];
        $diff   = $pm - $pe;

        $query = "update `player` ";
        $query .= "set `point`='$point', ";
        $query .= "`J`='$j', `G`='$g', `N`='$n', `P`='$p', `ve`='$ve', `pm`='$pm', `pe`=$pe, `bd`=$bd, `bo`=$bo  ";
        $query .= "where `player_idx`='$player'";
        pdo_exec(__FUNCTION__, $query);
    }
}

function check_prono_not_taken($season, $day, $team, $player)
{

    $query = "select team1, team2 from `match` ";
    $query .= "where day=$day and season=$season and (team1=$team or team2=$team)";
    $row   = pdo_fetch(__FUNCTION__, c_one, $query);
    $team1 = $row['team1'];
    $team2 = $row['team2'];

    $query = "select count(*) as n from prono as pr ";
    $query .= "join ";
    $query .= "(select player_idx from player where team=(select team from player where player_idx=$player)) as pl ";
    $query .= "on pr.player=pl.player_idx ";
    $query .= "where day=$day and season=$season and (team=$team1 or team=$team2)";
    $row = pdo_fetch(__FUNCTION__, c_one, $query);
    printr_log(__FUNCTION__, "row", $row);
    if ($row['n'] > 0) {
        return false;
    }
    // a prono already exists
    else {
        return true;
    }
    // no prono has been found
}

function update_prono($p)
{

    $season = $p['season'];
    $day    = $p['day'];
    $player = $p['player'];
    $team   = $p['team'];

    $team1 = 0;
    if (isset($p['selected_team'])) {
        $team1 = $p['selected_team'];
    }

    $team2 = 0;
    if (isset($p['contested_team'])) {
        $team2 = $p['contested_team'];
    }

    $player1 = 0;
    if (isset($p['player1'])) {
        $player1 = $p['player1'];
    }

    $player2 = 0;
    if (isset($p['player2'])) {
        $player2 = $p['player2'];
    }

    $query = "";
    if ($day > c_last_day) {
        if ($team1 > 0 and $team2 > 0) {
            $query = "insert into `prono` (`team`, `season`, `day`, `player`) values ";
            $query .= "( '$team1', '$season', '$day', '$player1'), ";
            $query .= "( '$team2', '$season', '$day', '$player2')";
        }
    } else {
        if ($team > 0) {
            if (check_prono_not_taken($season, $day, $team, $player)) {
                $query = "insert into `prono` (`team`, `season`, `day`, `player`) ";
                $query .= "values ( '$team', '$season', '$day', '$player')";
            } else {
                $_SESSION['alert'] = c_msg_alert_1;
            }
        }
    }

    if ($team == 0) {
        $query = "delete from `prono` where `season`=$season and `day`=$day and`player`=$player ";
    }

    #echo "<pre>$query</pre>";
    $res = false;
    if (strlen($query)) {
        $res = true;
        pdo_exec(__FUNCTION__, $query);
        update_d14($day, $season, $player);
    }
    return $res;
}

function update_match($p)
{

    $day    = $p['day'];
    $season = $p['season'];
    $team1  = $p['team1'];
    $team2  = $p['team2'];
    $score1 = $p['score1'];
    $score2 = $p['score2'];
    $try1   = $p['try1'];
    $try2   = $p['try2'];
    $date   = $p['date'];
    $time   = $p['time'];

    $bd1    = false;
    $bd2    = false;
    $bo1    = false;
    $bo2    = false;
    $point1 = 2;
    $point2 = 2;
    $n1     = true;
    $n2     = true;
    $v1     = false;
    $v2     = false;
    $d1     = false;
    $d2     = false;
    $ve     = false;
    $played = true;

    if ($score1 == 0 and $score2 == 0) {
        $played = false;
        $point1 = 0;
        $point2 = 0;
        $n1     = false;
        $n2     = false;
    }

    if ($score1 > $score2) {
        $v1     = true;
        $v2     = false;
        $n1     = false;
        $n2     = false;
        $d1     = false;
        $d2     = true;
        $point1 = 4;
        $point2 = 0;
        if (($try1 - $try2) >= 3) {
            $bo1 = true;
            $point1++;
        }
        if (($score1 - $score2) <= 5) {
            $bd2 = true;
            $point2++;
        }
    }
    if ($score2 > $score1) {
        $v1     = false;
        $v2     = true;
        $n1     = false;
        $n2     = false;
        $d1     = true;
        $d2     = false;
        $point1 = 0;
        $point2 = 4;
        $ve     = true;
        if (($try2 - $try1) >= 3) {
            $bo2 = true;
            $point2++;
        }
        if (($try1 - $try2) >= 3) {
            $bo1 = true;
            $point1++;
        }
        if (($score2 - $score1) <= 5) {
            $bd1 = true;
            $point1++;
        }
    }
    // /!\ V flags can be forced by admin
    if (isset($p['v1'])) {
        $v1 = true;
        $d2 = true;
    }

    if (isset($p['v2'])) {
        $v2 = true;
        $d1 = true;
    }

    if ($day > c_last_day) {
        $point1 = $point2 = 0;
        $bo1    = $bo2    = 0;
        $bd1    = $bd2    = 0;
    }

    $query = "update `score` ";
    $query .= "set `pm`='$score1', `pe`='$score2', `em`='$try1', `ee`='$try2', `bo`='$bo1', `bd`='$bd1', `pc`='$point1', ";
    $query .= "`J`='$played', `V`='$v1', `N`='$n1', `D`='$d1'  ";
    $query .= "where `day`='$day' and `season`='$season' and `team`='$team1'";
    pdo_exec(__FUNCTION__, $query);

    $query = "update `score` ";
    $query .= "set `pm`='$score2', `pe`='$score1', `em`='$try2', `ee`='$try1', `bo`='$bo2', `bd`='$bd2', `pc`='$point2', ";
    $query .= "`J`='$played', `V`='$v2', `N`='$n2', `D`='$d2', `ve`='$ve' ";
    $query .= "where `day`='$day' and `season`='$season' and `team`='$team2'";
    pdo_exec(__FUNCTION__, $query);

    $query = "update `match` ";
    $query .= "set `date`='$date', `time`='$time' ";
    $query .= "where `day`='$day' and `season`='$season' and `team1`='$team1' and `team2`='$team2'";
    pdo_exec(__FUNCTION__, $query);

    if ($day > c_last_day) {
        update_rank_phase_finale($day, $season);
    } else {
        update_player_phase_reguliere($day, $season);
        update_evolution_player($day);
        update_point_coiffeur($day, $season);
        update_equipe_differente($day, $season);
        update_point_fun($day, $season);
        update_rank_phase_reguliere($day, $season);
    }
}

function update_rank_phase_reguliere($day, $season)
{
    $teams = get_top7_teams($season);
    foreach ($teams as $top7team) {
        $ranks = get_rank7($day, $top7team);
        $i     = 0;
        foreach ($ranks as $rank) {
            $i++;
            $player = $rank['player'];
            $query  = "update `player` set `rank`='$i' where `player_idx`='$player'";
            pdo_exec(__FUNCTION__, $query);
        }
    }
}

function update_rank_phase_finale($day, $season)
{

    $teams  = get_top7_teams($season);
    foreach ($teams as $top7team) {
        $results    = array();
        $ranks      = get_rank7_finales($season, c_finale_day, $top7team, c_winner);
        $results[1] = $ranks[0];

        $ranks      = get_rank7_finales($season, c_finale_day, $top7team, c_loser);
        $results[2] = $ranks[0];

        $ranks      = get_rank7_finales($season, c_demifinales_day, $top7team, c_loser);
        $results[3] = $ranks[0];
        $results[4] = $ranks[1];

        $ranks      = get_rank7_finales($season, c_barrage_day, $top7team, c_loser);
        $results[5] = $ranks[0];
        $results[6] = $ranks[1];

        $ranks      = get_rank7(c_last_day, $top7team);
        $results[7] = $ranks[6];

        $rank = 0;
        foreach ($results as $result) {
            $player = $result['player'];
            $rank++;
            $query = "update `player` set `rankFinal`='$rank' where `player_idx`='$player'";
            pdo_exec(__FUNCTION__, $query);
            if ($rank == 1) {
                $pseudo = $result['pseudo'] . " &#9733;";
                $query  = "update `player` set `pseudo`='$pseudo' where `player_idx`='$player'";
                pdo_exec(__FUNCTION__, $query);
            }
        }
    }
}

function update_season_dates($p, $name, $value)
{
    #echo "<pre>Phase finale\n";print_r($p);echo "</pre>";

    $season = $p['season'];
    $query  = "update `season` set `$name`='$value' where `Id`=$season";
    pdo_exec(__FUNCTION__, $query);
}

function param_button2()
{
    echo "<td align=\"left\">";
    $action = "params";
    echo "<form name=\"form_param\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"ParamButton\" value=\"Classement saison\">\n";
    echo "<input type=\"hidden\" name=\"update\" value=\"" . c_phase_finale . "\">\n";
    echo "</form>\n";
    echo "</td>\n";
    echo "<td align=\"left\">";
    echo "Clore la saison. Fige le classement après la finale. A faire après la finale";
    echo "</td>\n";
}

function params($p)
{
    global $season_dates;

    $season              = $p['season'];
    $mode                = $p['mode'];
    $register_new_season = $p['register_new_season'];
    #$register_new_season     = true;
    if ($register_new_season) {
        $top7_season = get_top7_season_by_id($p['top7_season']);
        $new_season  = strtolower($top7_season['title']);
    }

    $top7_season = get_top7_season();

    echo "<table class=\"player_link\" border=0>\n";

    echo "<tr>\n";
    echo "<td align=\"left\">";
    echo "<img src=" . c_logo_file . ">\n";
    echo "</td>\n";
    echo "<td class=\"season_title\">";
    echo $top7_season['title'];
    echo "</td>\n";
    echo "<td align=\"right\">";
    if ($mode == c_admin) {
        display_select_back();
    }
    echo "</td>\n";
    echo "</tr>\n";
    echo "</table>\n";

    echo "<table class=\"player_link\" border=0>\n";
    echo "<tr>\n";
    //        param_button2();
    echo "</tr>\n";
    echo "</table>\n";

    $section = "dates";
    $infos   = array();
    foreach ($season_dates as $date) {
        $infos[] = array(
            "line" => c_line_edit, "div"      => "edit1", "section"                     => $section, "name" => $date['name'],
            "title"                 => $date['title'], "value" => $top7_season[$date['name']], "comment" => $date['comment']
        );
    }
    print_table_params("Dates", $infos);
}

function print_table_params($title, $infos)
{

    echo "<table class=\"params\">\n";
    echo "<tr class=\"params\">\n";
    echo "<th class=\"params\" colspan=\"3\">$title</th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    echo "<table class=\"params\" border=0>\n";

    foreach ($infos as $k => $element) {
        if ($element['line'] == c_line_edit) {
            put_param_edit($k, $element);
        }
    }

    echo "</table>\n";
}

function put_param_edit($id, $element)
{

    $title   = $element['title'];
    $value   = $element['value'];
    $comment = $element['comment'];
    $section = $element['section'];
    $name    = $element['name'];
    $action  = $_SERVER['PHP_SELF'];
    $div     = $element['div'];

    $action = substr($action, 0, strrpos($action, "."));

    #echo "<div>\n";
    echo "<tr class=\"params\">\n";
    echo "<td class=\"params_title\">$title</td>\n";
    echo "<td class=\"params_edit\">";
    echo "<form action=\"$action\" id=\"formedit$id\" method=\"post\">\n";
    echo "<input type=\"text\" name=\"date\" value=\"$value\" style=\"width: 100px\" readonly=\"true\" ondblclick=\"this.readOnly='';\" onblur=\"this.readOnly='true';document.getElementById('formedit$id').submit();\"/>\n";
    echo "<input type=\"hidden\" name=\"name\" value=\"$name\">\n";
    echo "<input type=\"hidden\" name=\"section\" value=\"$section\">\n";
    echo "</form>\n";
    echo "</td>\n";
    echo "<td>\n";
    echo "<div class=\"comment\">$comment</div>\n";
    echo "</td>\n";
    echo "</tr>\n";
}

function display_select_back()
{
    $action = "update_day";
    echo "<form name=\"form_params\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"ParamButton\" value=\"Retour\">\n";
    echo "</form>\n";
}

function display_select_params()
{
    $action = "params";
    echo "<form name=\"form_params\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"ParamButton\" value=\"Parametres\">\n";
    echo "</form>\n";
}

function display_select_reset()
{
    $action  = "update_day";
    $display = c_top14;

    echo "<form name=\"form_top7team\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"PronoButton\" value=\"Reset\">\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "<input type=\"hidden\" name=\"top7team\" value=\"0\">\n";
    echo "<input type=\"hidden\" name=\"player\" value=\"0\">\n";
    echo "<input type=\"hidden\" name=\"day\" value=\"0\">\n";
    echo "</form>\n";
}

function display_select_top7team($selected_team)
{

    $action  = "update_day";
    $display = c_top7;
    $season  = $_SESSION['season'];

    $query     = "select name, team_idx from `team_player` where season=$season order by team_idx";
    $rows      = pdo_fetch(__FUNCTION__, c_all, $query);
    $top7teams = array();
    foreach ($rows as $row) {
        $top7teams[] = $row;
    }

    $title = "équipe";

    echo "<form name=\"form_top7team\" action=\"$action\" method=\"post\">\n";
    echo "<select name=\"top7team\" id=\"AdminSelect\" onChange=\"if(this.value!='none') this.form.submit();\">\n";
    if ($selected_team == 0) {
        echo "<option selected=\"selected\" value=\"none\">Choisir une $title</option>\n";
    }

    foreach ($top7teams as $top7team) {
        $idx  = $top7team['team_idx'];
        $name = $top7team['name'];
        if ($selected_team == $idx) {
            $selected = "selected=\"selected\"";
        } else {
            $selected = "";
        }

        echo "<option $selected value=$idx>Equipe : $name</option>\n";
    }
    echo "</select>\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "<input type=\"hidden\" name=\"player\" value=\"0\">\n";
    echo "</form>\n";
}

function display_top7team($p)
{
    // TODO TO REMOVE

    global $tr_class;

    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    $query     = "select name from `team_player` where team_idx='$top7team'";
    $row       = pdo_fetch(__FUNCTION__, c_one, $query);
    $team_name = $row['name'];

    $query = "select name, pseudo, email, password ";
    $query .= "from `player` ";
    $query .= "where team='$top7team' ";
    $query .= "order by player_idx ";
    $players = pdo_fetch(__FUNCTION__, c_all, $query);

    $idx    = 1;
    $class  = "top14";
    $classt = "teamtop14";
    $title  = "Equipe : " . $team_name;
    echo "<table class=\"top7team\">\n";
    echo "<tr><th class=\"$class\" colspan=\"5\">$title</th></tr>\n";
    echo "<tr>\n";
    echo "<th class=\"$classt\">#</th>\n";
    echo "<th class=\"$classt\">Pseudo</th>\n";
    echo "<th class=\"$classt\">Name</th>\n";
    echo "<th class=\"$classt\">Email</th>\n";
    echo "<th class=\"$classt\">Password</th>\n";
    echo "</tr>\n";

    foreach ($players as $player) {
        $class = $tr_class[$idx % 2];
        echo "<tr class=\"$class\">\n";
        echo "<td>$idx</td>\n";
        echo "<td>" . $player['pseudo'] . "</td>\n";
        echo "<td>" . $player['name'] . "</td>\n";
        echo "<td>" . $player['email'] . "</td>\n";
        echo "<td>" . $player['password'] . "</td>\n";
        echo "</tr>\n";
        $idx++;
    }
    echo "</table>\n";
}

function put_evolution($evo)
{
    global $evol_img;
    if ($evo != 0) {
        return "<img src=\"" . $evol_img[$evo] . "\">\n";
    } else {
        return "";
    }
}

function get_rank7_one_day($day, $top7team)
{

    $query = "select pseudo, player, score.J, score.V, score.N, score.D, score.rank, player.rank ";
    $query .= "from player join prono on player_idx=player ";
    $query .= "join score on prono.team=score.team and prono.day=score.day and prono.season=score.season ";
    $query .= "where score.day=$day and player.team=$top7team and score.V=1 ";
    #$query .= "order by score.rank";
    $query .= "order by player.rank";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_rank7_finales($season, $day, $top7team, $type)
{

    #$season=1;

    $score = "score.V=1";
    $order = "date, time";
    if ($type == c_loser) {
        $score = "score.D=1";
        $order = "pt desc";
    }
    $order = "player.rank"; // A GERER A CHAQUE JOURNEE PHASE REGULIERE

    //  scores du classement des phases finales : 1/2 finales, finale
    $query = "select pseudo, ";
    $query .= "point as pt, ";
    $query .= "team.team_long as name, ";
    $query .= "player_idx as player, ";
    $query .= "score.V as g, ";
    $query .= "score.N as n, ";
    $query .= "score.D as p, ";
    $query .= "player.rank ";

    $query .= "from `player` join `prono` on player_idx=player ";
    $query .= "join `score` on prono.team=score.team and prono.day=score.day and prono.season=score.season ";
    $query .= "join `match` on match.day=score.day and match.season=score.season and (match.team1=score.team or match.team2=score.team) ";
    $query .= "left join `team` on team.team_idx=score.team and team.season=score.season ";
    $query .= "where score.day=$day and score.season=$season and player.team=$top7team and $score ";
    $query .= "order by $order";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_nb_different_teams($day, $season, $player, $t)
{
    $team = "team" . $t;

    $query = "select * from ";
    $query .= "(select $team from `match` ";
    $query .= "where match.season=$season and match.day=$day) as t1 ";
    $query .= "left join ";
    $query .= "(select distinct(team), count(team) as ne from `prono` ";
    $query .= "where prono.player=$player ";
    $query .= "group by team) as t2 ";
    $query .= "on t1.$team=t2.team";
    $rows               = pdo_fetch(__FUNCTION__, c_all, $query);
    $different_nb_teams = array();
    foreach ($rows as $row) {
        $n = 0;
        if (strlen($row['ne'])) {
            $n = $row['ne'];
        }

        $different_nb_teams[$row["$team"]] = $n;
    }
    printr_log(__FUNCTION__, "different_nb_teams", $different_nb_teams);
    return $different_nb_teams;
}

function get_rank7($day, $top7team)
{

    $query = "select * from ( ";

    //  scores du classement
    $query .= "select pseudo, date_reg, t0.player, ";
    $query .= "sum(coalesce(score.pc,0)) as pt, ";
    $query .= "sum(coalesce(score.J,0)) as j, ";
    $query .= "sum(coalesce(score.V,0)) as g, ";
    $query .= "sum(coalesce(score.N,0)) as n, ";
    $query .= "sum(coalesce(score.D,0)) as p, ";
    $query .= "sum(coalesce(score.ve,0)) as ve, ";
    $query .= "sum(coalesce(score.pm,0)) as pm, ";
    $query .= "sum(coalesce(score.pe,0)) as pe, ";
    $query .= "sum(coalesce(score.pm,0))-sum(coalesce(score.pe,0)) as diff, ";
    $query .= "sum(coalesce(score.bd,0))+sum(coalesce(score.bo,0)) as pb, ";
    $query .= "sum(coalesce(score.bo,0)) as pbo, ";
    $query .= "sum(coalesce(score.bd,0)) as pbd ";
    $query .= "from `prono` right join ";
    $query .= "(select pseudo, date_reg, player_idx as player from `player` ";
    $query .= "where team=$top7team) as t0 ";
    $query .= "on prono.player=t0.player ";
    $query .= "left join `score` ";
    $query .= "on prono.season=score.season and prono.day=score.day and prono.team=score.team ";
    $query .= "where prono.day<=$day or prono.day is NULL ";
    $query .= "group by t0.player ";
    $query .= ") as t1 ";

    $query .= "left join ( ";

    // ne : Nbre d'équipes différentes qui ont été sélectionnées
    $query .= "select t2.player_idx, count( distinct prono.team) as ne ";
    $query .= "from `prono` right join ";
    $query .= "(select pseudo, player_idx from `player` ";
    $query .= "where team=$top7team) as t2 ";
    $query .= "on prono.player=t2.player_idx ";
    $query .= "left join `score` ";
    $query .= "on prono.team=score.team and prono.day=score.day and prono.season=score.season ";
    $query .= "where score.j=1 and prono.team > 0 and prono.day<=$day or prono.day is NULL ";
    $query .= "group by t2.player_idx ";
    $query .= ") as t3 ";
    $query .= "on t1.player=t3.player_idx ";

    #$query .= "order by pt desc, g desc, ve desc, ne desc ";
    #$query .= "order by pt desc, g desc, ve desc, ne desc, n desc, diff desc, t1.player asc  ";
    $query .= "order by pt desc, g desc, ve desc, ne desc, n desc, diff desc, t1.date_reg asc  ";

    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_random_rank7($top7team)
{

    $query = "select pseudo, player_idx as player, date_reg, captain from player ";
    $query .= " where team=$top7team ";
    $rows       = pdo_fetch(__FUNCTION__, c_all, $query);
    $ranks      = array();
    $timestamps = array();
    foreach ($rows as $row) {
        $r         = explode(" ", $row['date_reg']);
        $d         = explode("-", $r[0]);
        $t         = explode(":", $r[1]);
        $timestamp = mktime($t[0], $t[1], $t[2], $d[1], $d[2], $d[0]);
        // Issue #10 -> remove captain as 1st position in rank order
        #if ($row['captain']) {
        #    $timestamp += 3600 * 24;
        #}
        // ticket 52
        $row['timestamp'] = $timestamp;
        $timestamps[]     = $timestamp;
        $ranks[]          = $row;
    }

    arsort($timestamps);
    $new_ranks = array();
    foreach ($timestamps as $k => $value) {
        $new_ranks[] = $ranks[$k];
    }

    printr_log(__FUNCTION__, "new_ranks", $new_ranks);
    return $new_ranks;
}

function get_final_results($top7team)
{

    $day = c_last_day;

    $query = "select m.day, date, time, ";
    $query .= "team1, team2, t1.team_long as local, t2.team_long as visiteur, ";
    $query .= "s1.pm as score1, s2.pm as score2, p1.player as player1, p2.player as player2, ";
    $query .= "s1.V as v1, s2.V as v2, ";
    $query .= "pl1.pseudo as pseudo1, pl2.pseudo as pseudo2 ";
    $query .= "from `match` as m ";
    $query .= "join `team` as t1 on t1.team_idx=m.team1 ";
    $query .= "join `team` as t2 on t2.team_idx=m.team2 ";
    $query .= "join `score` as s1 on s1.day=m.day and s1.team=m.team1 ";
    $query .= "join `score` as s2 on s2.day=m.day and s2.team=m.team2 ";
    $query .= "join `prono` as p1 on p1.day=m.day and p1.team=m.team1 ";
    $query .= "join `prono` as p2 on p2.day=m.day and p2.team=m.team2 ";
    $query .= "join `player` as pl1 on p1.player=pl1.player_idx ";
    $query .= "join `player` as pl2 on p2.player=pl2.player_idx ";
    $query .= "where m.day>$day and  pl1.team=$top7team and pl2.team=$top7team ";
    $query .= "order by date, time";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function display_final($p)
{

    global $strDate;
    global $tr_class;
    global $title_phase_finale;

    $day    = $p['day'];
    $season = $p['season'];

    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    // Line 1 :        $title
    // -----------------------------------------------
    $title = "Classement final TOP7";
    $class = "top7";
    echo "<table class=\"day\">\n";
    echo "<tr>\n";
    echo "<th class=\"$class\">$title</th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    // Line 2 :   Rang Titre   Joueur
    // -----------------------------------------------
    $class  = $class1  = $class2  = $class3  = "top7";
    $classt = "teamtop7";
    echo "<table class=\"day\" border=0>\n";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$classt\">Titre</th>\n";
    echo "<th class=\"$classt\">Joueur</th>\n";
    echo "<th class=\"$classt\"></th>\n";

    echo "</tr>\n";

    // Line 3 :   Rang Titre   Joueur
    // -----------------------------------------------

    $results    = array();
    $ranks      = get_rank7_finales($season, c_finale_day, $top7team, c_winner);
    $results[1] = $ranks[0];

    $ranks      = get_rank7_finales($season, c_finale_day, $top7team, c_loser);
    $results[2] = $ranks[0];

    $ranks = get_rank7_finales($season, c_demifinales_day, $top7team, c_loser);
    if (count($ranks) == 1) {
        $results[3] = "";
        $results[4] = $ranks[0];
    } else {
        $results[3] = $ranks[0];
        $results[4] = $ranks[1];
    }

    $ranks = get_rank7_finales($season, c_barrage_day, $top7team, c_loser);
    if (count($ranks) == 1) {
        $results[5] = "";
        $results[6] = $ranks[0];
    } else {
        $results[5] = $ranks[0];
        $results[6] = $ranks[1];
    }

    $ranks      = get_rank7(c_last_day, $top7team);
    $results[7] = $ranks[6];

    $class = "top7";
    foreach ($results as $idx => $player) {

        $pseudo = "";
        if (isset($player['pseudo'])) {
            $pseudo     = $player['pseudo'];
            $rank_day26 = "";
            $team       = "";
            foreach ($ranks as $pos => $rank) {
                if ($rank['player'] == $player['player']) {
                    if ($pos) {
                        $pos_ext = $pos + 1 . "ème";
                    } else {
                        $pos_ext = "1er";
                    }

                    $rank_day26 = sprintf("%s - %d pts", $pos_ext, $rank['pt']);
                    if ($idx < 7) {
                        $rank_day26 = sprintf("%s - %s", $rank_day26, $player['name']);
                    }
                    $rank_day26 = "<i>($rank_day26)</i>";
                }
            }
        }

        $class = $tr_class[$idx % 2];
        $title = $title_phase_finale[$idx - 1];
        echo "<tr class=\"rank7_$idx\">\n";
        echo "<td class=\"point\">&nbsp;$idx</td>\n";
        echo "<td>&nbsp;$title</td>\n";

        // to rewrite
        if ($day >= c_last_day) {
            echo "<td>&nbsp;$pseudo</td>\n";
            echo "<td>&nbsp;$rank_day26</td>\n";
        } else {
            echo "<td>&nbsp;</td>\n";
            echo "<td>&nbsp;</td>\n";
        }
        echo "</tr>\n";
    }
    echo "</table>\n";
}

function calcul_point_fun($row)
{
    $fun = $row['point'] + 2 * $row['ve'] - 2 * $row['pc'];
    if ($row['eq'] == 14) {
        if ($row['d14'] == 14) {
            $fun += 30;
        } elseif ($row['d14'] == 15) {
            $fun += 10;
        } else {
            $fun += 5;
        }
    }
    if ($fun < 0) {
        $fun = 0;
    }
    return $fun;
}


function display_rank7($p)
{

    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    $day    = $p['day'];
    $season = $p['season'];

    // point fun
    $query = "select pseudo, ";
    $query .= "player_idx as player, ";
    $query .= "fun ";
    $query .= "from player ";
    $query .= "where season=$season and player.team=$top7team ";

    $rows  = pdo_fetch(__FUNCTION__, c_all, $query);
    $pfun  = array();
    foreach ($rows as $row) {
        $pfun[$row['player']] = $row['fun'];
    }

    // pc : Points Coiffeur = BO de l'équipe non pronostiquée
    $query = "select pseudo, ";
    $query .= "player_idx as player, ";
    $query .= "coalesce(sum(score.bo),0) as pc ";
    $query .= "from `player` left join ( ";
    $query .= "	select * from ( ";
    $query .= "		select team1 as new_team, prono.day, prono.season, player  ";
    $query .= "		from `match` join `prono` on match.day=prono.day and match.season=prono.season ";
    $query .= "		where prono.team=team2 ";
    $query .= "		union  ";
    $query .= "		select team2 as new_team, prono.day, prono.season, player  ";
    $query .= "		from `match` join `prono` on match.day=prono.day and match.season=prono.season ";
    $query .= "		where prono.team=team1 ";
    $query .= "	) as tt ";
    $query .= "	order by day, player) as new_prono ";
    $query .= "on player_idx=new_prono.player ";
    $query .= "left join `score` on new_prono.new_team=score.team and new_prono.day=score.day and new_prono.season=score.season ";
    $query .= "where (score.day<=$day or score.day is NULL) and player.team=$top7team ";
    $query .= "group by player_idx ";

    $rows = pdo_fetch(__FUNCTION__, c_all, $query);
    $pcs  = array();
    $i    = 0;
    foreach ($rows as $row) {
        $pcs[$row['player']] = $row['pc'];
    }

    // classement at day-1
    $day_before = 1;
    if ($day > 1) {
        $day_before = $day - 1;
    }

    $ranks            = get_rank7($day_before, $top7team);
    $i                = 1;
    $day_before_ranks = array();
    foreach ($ranks as $rank) {
        $day_before_ranks[$rank['player']] = $i++;
    }

    // classement at day
    $ranks = get_rank7($day, $top7team);

    // classement + evo et pc
    $i          = 1;
    $top7_ranks = array();
    foreach ($ranks as $rank) {
        $player = $rank['player'];
        // evo : classement du J-1 pour trouver l'évolution
        $evo = 0;
        if (isset($day_before_ranks[$player])) {
            if ($day_before_ranks[$player] > $i) {
                $evo = 1;
            }

            if ($day_before_ranks[$player] < $i) {
                $evo = -1;
            }
        }

        // pc : point coiffeur
        $pc = $pcs[$player];

        // fun : point fun
        $fun = $pfun[$player];

        /*
        $fun = $rank['pt'] + 2 * $rank['ve'] - 2 * $pc;
        if ($rank['ne'] == 14) {
            $fun += 5;
        }

        if ($fun < 0) {
            $fun = 0;
        }
 */
        $top7_ranks[] = $rank + array("evo" => $evo, "pc" => $pc, "fun" => $fun);
        $i++;
    }

    $action   = "rank7";
    $idbutton = "Rank7Button";
    $left     = "<form id=\"form_nav_L\" action=\"$action\" method=\"post\">\n";
    $left .= "<input type=\"submit\" id=\"$idbutton\" name=\"prev\" value=\"<<\">\n";
    $left .= "</form>\n";

    $right = "<form id=\"form_nav_R\" action=\"$action\" method=\"post\">\n";
    $right .= "<input type=\"submit\" id=\"$idbutton\" name=\"next\" value=\">>\">\n";
    $right .= "</form>\n";

    $title = get_top7_title($day);

    $idx    = 1;
    $class  = "top7";
    $classt = "teamtop7";
    echo "<table class=\"rank7\">\n";

    echo "<tr>\n";
    echo "<th class=\"$class\">$left</th>\n";
    echo "<th class=\"$class\">$title</th>\n";
    echo "<th class=\"$class\">$right</th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    echo "<table class=\"rank7\">\n";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ev", "Evolution classement");
    echo "</th>\n";
    echo "<th class=\"$classt\">Joueur</th>\n";
    echo "<th class=\"$class\">PTS</th>\n";
    echo "<th class=\"fun\">";
    put_abbr("(fun)", "Points fun");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Points Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nbre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("p", "Points Marqués");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("c", "Points Encaissés");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    foreach ($top7_ranks as $rank) {
        echo "<tr class=\"rank7_$idx\">\n";
        #echo "<td class=\"point\">" . $rank['player'] . "</td>\n";
        echo "<td class=\"point\">$idx</td>\n";
        $img = put_evolution($rank['evo']);
        #$img="";
        echo "<td class=\"point\">" . $img . "</td>\n";
        echo "<td>" . $rank['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['pt'] . "</td>\n";
        echo "<td class=\"fun\">(" . $rank['fun'] . ")</td>\n";
        echo "<td class=\"point\">" . $rank['pb'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['j'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['g'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['n'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['p'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['pm'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['pe'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['pbo'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['pbd'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['ne'] . "</td>\n";
        echo "<td class=\"point\">" . $rank['pc'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

function LNR_rank($ranks, $day, $season)
{

    $ranks1        = $ranks;
    $ranks2        = array();
    $new_criterion = array("point_" => 0, "v_" => 0, "d_" => 0, "diff_" => 0, "trydiff_" => 0);
    foreach ($ranks1 as $idx => $rank) {
        $ranks2[$idx] = array_merge($rank, $new_criterion);
    }

    $points        = array();
    foreach ($ranks1 as $idx => $rank) {
        $point = $rank['point'];
        if (!in_array($point, $points)) array_push($points, $point);
    }
    $e_teams      = array();
    foreach ($points as $k => $point) {
        foreach ($ranks1 as $idx => $rank) {
            if ($rank['point'] == $point) $e_teams[$k][] = $rank['team'];
        }
    }
    $equal_teams   = array();
    foreach ($e_teams as $team) {
        if (count($team) > 1) $equal_teams[] = $team;
    }
    printr_log(__FUNCTION__, "equal_teams", $equal_teams);

    // step 1 : put equality teams in temporary table : teams -> (team1, team2)
    global $pdo;
    $idx = 0;
    foreach ($equal_teams as $teams) {

        try {
            $q = $pdo->prepare("drop temporary table if exists `t1`");
            $q->execute();
            $q = $pdo->prepare("create temporary table `t1` ( `team1` tinyint(4))");
            $q->execute();
            $q = $pdo->prepare("drop temporary table if exists `t2`");
            $q->execute();
            $q = $pdo->prepare("create temporary table `t2` ( `team2` tinyint(4))");
            $q->execute();
            foreach ($teams as $team) {
                $q = $pdo->prepare("insert into `t1` ( `team1`) values ( $team)");
                $q->execute();
                $q = $pdo->prepare("insert into `t2` ( `team2`) values ( $team)");
                $q->execute();
            }
        } catch (Exception $e) {
            error(__FUNCTION__, "(" . $e->getCode() . ") " . $e->getMessage());
        }

        // step 2 : get all combinations : select team1, team2 from t1, t2 where team1<>team2 : (team1, team2)
        // step 3 : get days from all those combintations : (day, team1, team2)
        $query = "select * ";
        $query .= "from `match` as tm ";
        $query .= "join (select team1, team2 from t1, t2 where team1<>team2) as te ";
        $query .= "on tm.team1=te.team1 and tm.team2=te.team2 ";
        #$query .= "where season=$season ";
        $query .= "where day<=$day  and season=$season ";
        $query .= "order by day";
        $rows  = pdo_fetch(__FUNCTION__, c_all, $query);
        $teams = array();
        $t     = array();
        foreach ($rows as $row) {
            $teams[] = array("day" => $row['day'], "team" => $row['team1']);
            $teams[] = array("day" => $row['day'], "team" => $row['team2']);
            $t[]     = $row;
        }

        if (count($teams) == 0) {
            continue;
        }

        // step 4 : sum points match from each day, team : (day, team, pm)
        try {
            $q = $pdo->prepare("drop temporary table if exists `t3`");
            $q->execute();
            $q = $pdo->prepare("create temporary table `t3` ( `day` tinyint(4), `team` tinyint(4))");
            $q->execute();
            $query = "insert into `t3` ( `day`, `team`) values ";
            foreach ($teams as $team) {
                $query .= "( " . $team['day'] . "," . $team['team'] . " ),";
            }

            $query = substr($query, 0, -1);
            $q     = $pdo->prepare($query);
            $q->execute();
        } catch (Exception $e) {
            error(__FUNCTION__, "(" . $e->getCode() . ") " . $e->getMessage());
        }

        $query = "select ts.team, sum(pc) as point_,  ";
        $query .= "sum(V) as v_, sum(D) as d_, ";
        $query .= "sum(pm)-sum(pe) as diff_, ";
        $query .= "sum(em)-sum(ee) as trydiff_ ";
        $query .= "from `score` as ts ";
        $query .= "join `t3` as t using( day, team) ";
        $query .= "where day<=$day  and season=$season ";
        $query .= "group by ts.team ";
        #$query .= "order by point desc, ga desc, trydiff desc";
        $rows = pdo_fetch(__FUNCTION__, c_all, $query);
        $t    = array();
        foreach ($rows as $row) {
            $t[] = $row;
            foreach ($ranks1 as $k => $rank) {
                if ($rank['team'] == $row['team']) {
                    $ranks2[$k] = array_merge($rank, $row);
                }
            }
        }
        $idx++;
    }

    foreach ($ranks2 as $k => $rank) {
        $criterion1[$k] = $rank['point']; // point terrain
        $criterion2[$k] = $rank['point_']; // point terrain sur match des équipes concernées
        $criterion3[$k] = $rank['v_'];        // nbre victoires sur match des équipes concernées
        $criterion4[$k] = $rank['d_'];        // nbre défaites sur match des équipes concernées
        $criterion5[$k] = $rank['diff']; // goal average sur ensemble des matchs
        $criterion6[$k] = $rank['diff_']; // goal average sur matchs des équipes concernées
        $criterion7[$k] = $rank['trydiff_']; // difference essais sur matchs des équipes concernées
        $criterion8[$k] = $rank['trydiff']; // difference essais sur ensemble des matchs
        $criterion9[$k] = $rank['ptm']; // nbre de points marqués
        $criteriona[$k] = $rank['nem']; // nbre d'essais marqués
        $criterionb[$k] = $rank['previous_season']; // classement de la précédente saison
    }
    array_multisort(
        $criterion1,
        SORT_DESC,
        $criterion2,
        SORT_DESC,
        #       $criterion3, SORT_DESC,
        #       $criterion4, SORT_ASC,
        $criterion5,
        SORT_DESC,
        $criterion6,
        SORT_DESC,
        $criterion7,
        SORT_DESC,
        $criterion8,
        SORT_DESC,
        $criterion9,
        SORT_DESC,
        $criteriona,
        SORT_DESC,
        $criterionb,
        SORT_ASC,
        $ranks2
    );

    return $ranks2;
}

function display_rank($p)
{

    $day    = $p['day'];
    $season = $p['season'];

    $query = "select ts.team, ";
    $query .= "t.team_long as name, ";
    $query .= "previous_season, ";
    $query .= "sum(pc) as point, ";
    $query .= "sum(J) as j, ";
    $query .= "sum(V) as v, ";
    $query .= "sum(N) as n, ";
    $query .= "sum(D) as d, ";
    $query .= "sum(pm) as ptm, ";
    $query .= "sum(pe) as pte, ";
    $query .= "sum(pm)-sum(pe) as diff, ";
    $query .= "sum(bo) as pbo, ";
    $query .= "sum(bd) as pbd, ";
    $query .= "sum(em) as nem, ";
    $query .= "sum(ee) as nee, ";
    $query .= "sum(em)-sum(ee) as trydiff ";
    $query .= "from `score` as ts ";
    $query .= "left join `team` as t on t.team_idx=ts.team and t.season=ts.season ";
    $query .= "where day<=$day and t.season=$season ";
    $query .= "group by team ";
    $query .= "order by j desc, point desc, ptm desc, diff desc, trydiff desc";
    $ranks = pdo_fetch(__FUNCTION__, c_all, $query);

    $new_ranks = LNR_rank($ranks, $day, $season);

    $action   = "rank";
    $idbutton = "Rank14Button";
    $left     = "<form id=\"form_nav_L\" action=\"$action\" method=\"post\">\n";
    $left .= "<input type=\"submit\" id=\"$idbutton\" name=\"prev\" value=\"<<\">\n";
    $left .= "</form>\n";

    $right = "<form id=\"form_nav_R\" action=\"$action\" method=\"post\">\n";
    $right .= "<input type=\"submit\" id=\"$idbutton\" name=\"next\" value=\">>\">\n";
    $right .= "</form>\n";

    $title = get_top14_title($day);

    $idx    = 1;
    $class  = "top14";
    $classt = "teamtop14";
    echo "<table class=\"rank\">\n";

    echo "<tr>\n";
    echo "<th class=\"$class\">$left</th>\n";
    echo "<th class=\"$class\">$title</th>\n";
    echo "<th class=\"$class\">$right</th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    echo "<table class=\"rank\">\n";

    echo "<th class=\"$class\">&nbsp;#</th>\n";
    echo "<th class=\"$classt\">Equipe</th>\n";
    echo "<th class=\"$class\">PTS</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Points Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nbre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("p", "Points Marqués");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("c", "Points Encaissés");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Em", "Essais Marqués");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ee", "Essais Encaissés");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence d'essais");
    echo "</th>\n";
    echo "</tr>\n";

    $class = "point";
    $idx   = 0;
    foreach ($new_ranks as $rank) {
        #echo "<pre>$k";print_r($rank);echo "</pre>";
        $idx++;
        echo "<tr class=\"rank_$idx\">\n";
        echo "<td class=\"$class\">$idx</td>\n";
        echo "<td>" . $rank['name'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['point'] . "</td>\n";
        echo "<td class=\"$class\">" . ($rank['pbo'] + $rank['pbd']) . "</td>\n";
        echo "<td class=\"$class\">" . $rank['j'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['v'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['n'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['d'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['ptm'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['pte'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['diff'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['pbo'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['pbd'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['nem'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['nee'] . "</td>\n";
        echo "<td class=\"$class\">" . $rank['trydiff'] . "</td>\n";
        echo "</tr>\n";
    }
    echo "</table>\n";
}

function get_team14_name($team, $season)
{

    $query = "select team_long as name ";
    $query .= "from `team` where team_idx=$team and season=$season";
    $row = pdo_fetch(__FUNCTION__, c_one, $query);
    return $row['name'];
}

function get_top7_pronos($player)
{

    $query  = "select * from prono where player=$player order by day";
    $rows   = pdo_fetch(__FUNCTION__, c_all, $query);
    $pronos = array();
    foreach ($rows as $row) {
        $pronos[$row['day']] = $row;
    }

    return $pronos;
}

function get_score_player($player)
{

    // ne : Nbre d'équipes différentes qui ont été sélectionnées
    $query = "select day, team, count( team) as ne ";
    $query .= "from prono where player=$player ";
    $query .= "group by team ";
    $query .= "order by day";
    $rows = pdo_fetch(__FUNCTION__, c_all, $query);
    $ne   = array();
    foreach ($rows as $row) {
        $day      = $row['day'];
        $ne[$day] = $row;
    }

    $query = "select player, day, team, pm, em, bo, bd, ve, V, N, (V*4+N*2+bo+bd) as pt  ";
    $query .= "from `prono` join `score` using(season, day, team) ";
    $query .= "where player=$player ";
    $query .= "order by day ";
    $rows   = pdo_fetch(__FUNCTION__, c_all, $query);
    $scores = array();
    $n      = 1;
    foreach ($rows as $row) {
        $day         = $row['day'];
        $nb_of_teams = array("ne" => "");
        if (isset($ne[$day])) {
            $nb_of_teams = array("ne" => $n++);
        }

        $scores[$day] = $row + $nb_of_teams;
    }

    return $scores;
}

function get_score_players($day, $season, $top7team)
{

    // ne : Nbre d'équipes différentes qui ont été sélectionnées
    $query = "select prono.player as player, count( distinct prono.team) as ne ";
    $query .= "from prono ";
    $query .= "left join player on prono.player=player.player_idx ";
    $query .= "where player.team=$top7team and prono.team > 0 and prono.day<=$day ";
    $query .= "group by prono.player ";
    $rows = pdo_fetch(__FUNCTION__, c_all, $query);
    $ne   = array();
    foreach ($rows as $row) {
        $ne[$row['player']] = array("ne" => $row['ne']);
    }

    $query = "select * from ";
    $query .= "(select player_idx, pseudo ";
    $query .= "from `player` join `team_player` on team_idx=team ";
    $query .= "where team_idx=$top7team) as t1 ";
    $query .= "join ";
    $query .= "(select player, day, team, pm, em, bo, bd, ve, V, N, (V*4+N*2+bo+bd) as pt  ";
    $query .= "from `prono` join `score` using(day, season, team) ";
    $query .= "where prono.day=$day and prono.season=$season) as t2 ";
    $query .= "where t1.player_idx=t2.player ";
    $rows   = pdo_fetch(__FUNCTION__, c_all, $query);
    $scores = array();
    foreach ($rows as $row) {
        $player          = $row['player'];
        $scores[$player] = $row + $ne[$player];
    }

    printr_log(__FUNCTION__, "scores", $scores);
    return $scores;
}

function get_top7_matchs($player, $season)
{

    $query = "select t1.team_long as local, t2.team_long as visiteur, ";
    $query .= "s1.pm as score1, s2.pm as score2, ";
    $query .= "s1.em as try1, s2.em as try2, ";
    $query .= "s1.bo as bo1, s2.bo as bo2, ";
    $query .= "s1.bd as bd1, s2.bd as bd2, ";
    $query .= "team1, team2, date, time, tm.day ";
    $query .= "from `match` as tm ";
    $query .= "left join `team` as t1 on t1.team_idx=tm.team1 and t1.season=$season ";
    $query .= "left join `team` as t2 on t2.team_idx=tm.team2 and t2.season=$season ";
    $query .= "left join `score` as s1 on s1.team=tm.team1 and s1.day=tm.day and s1.season=$season ";
    $query .= "left join `score` as s2 on s2.team=tm.team2 and s2.day=tm.day and s2.season=$season ";
    $query .= "left join `prono` as p on (p.team=s1.team and p.day=s1.day and p.season=s1.season) ";
    $query .= "or (p.team=s2.team and p.day=s2.day and p.season=s2.season) ";
    $query .= "where p.player=$player ";
    #$query .= "and t1.season=$season and t2.season=$season ";
    #$query .= "and s1.season=$season and s2.season=$season ";
    $query .= "and tm.season=$season ";
    #$query .= "where (tm.team1=$team and s1.team=$team) or (tm.team2=$team and s2.team=$team) ";
    ##$query .= "order by tm.day ";
    $query .= "order by date, time, tm.day ";

    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_team14_matchs($team, $season)
{

    $query = "select t1.team_long as local, t2.team_long as visiteur, ";
    $query .= "s1.pm as score1, s2.pm as score2, ";
    $query .= "s1.em as try1, s2.em as try2, ";
    $query .= "s1.bo as bo1, s2.bo as bo2, ";
    $query .= "s1.bd as bd1, s2.bd as bd2, ";
    $query .= "team1, team2, date, time, tm.day ";
    $query .= "from `match` as tm ";
    $query .= "left join `team` as t1 on t1.team_idx=tm.team1  and t1.season=tm.season ";
    $query .= "left join `team` as t2 on t2.team_idx=tm.team2  and t2.season=tm.season ";
    $query .= "left join `score` as s1 on s1.team=tm.team1 and s1.day=tm.day and s1.season=tm.season ";
    $query .= "left join `score` as s2 on s2.team=tm.team2 and s2.day=tm.day and s2.season=tm.season ";
    $query .= "where (tm.season=$season and s1.season=$season and tm.team1=$team and s1.team=$team) ";
    $query .= "or (tm.season=$season and s2.season=$season and tm.team2=$team and s2.team=$team) ";
    $query .= "order by date, time, tm.day ";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_day_from_date()
{

    $now   = now();
    $today = date("Y-m-d", $now);

    $query = "select day, date from `match` ";
    $query .= "where date >= \"$today\" order by date limit 1";
    $rows = pdo_fetch(__FUNCTION__, c_one, $query);

    if (count($rows) > 1) {
        $day = $rows['day'];
    } else {
        $day = c_finale_day;
    }

    // ################
    //  PYL 16Nov2020
    # $day = 19;
    // ###############
    print_log(__FUNCTION__, "day", $day);
    return $day;
}

function get_top7_season_by_id($id)
{
    $query = "select * from `season` where Id=$id";
    return pdo_fetch(__FUNCTION__, c_one, $query);
}

function get_top7_season()
{
    $today = date("Y-m-d", now());
    $query = "select * from `season` where \"$today\" > start order by start desc limit 1";
    return pdo_fetch(__FUNCTION__, c_one, $query);
}

function get_first_day_season($season)
{

    $day   = 1;
    $query = "select date, time from `match` ";
    $query .= "where season=$season and day >= $day limit 1";
    $season = pdo_fetch(__FUNCTION__, c_one, $query);
    $date   = $season['date'] . " 23:00:00";
    print_log(__FUNCTION__, "date", $date);
    print_log(__FUNCTION__,"d", strtotime($date));
    print_log(__FUNCTION__,"d", strtotime($date) - 7 * 24 * 3600);
    return strtotime($date) - 7 * 24 * 3600;
}

function get_last_day_season($season)
{

    $day   = c_finale_day;
    $query = "select date, time from `match` ";
    $query .= "where season=$season and day >= $day limit 1";
    $rows = pdo_fetch(__FUNCTION__, c_one, $query);

    $date = $rows['date'] . " 23:00:00";
    return strtotime($date);
}

function get_last_day_from_date($now, $season)
{

    $today   = date("Y-m-d", $now);
    $r       = explode("-", $today);
    $today_W = date('W', mktime(0, 0, 0, $r[1], $r[2], $r[0])); // sunday=0, saturday=6, friday=5

    $query = "select day, date from `match` ";
    $query .= "where season=$season and date >= \"$today\" order by date limit 1";
    $rows1 = pdo_fetch(__FUNCTION__, c_one, $query);

    $query = "select day, date from `match` ";
    $query .= "where season=$season and date < \"$today\" order by date desc limit 1";
    $rows2 = pdo_fetch(__FUNCTION__, c_one, $query);

    printr_log(__FUNCTION__, "rows1", $rows1);
    printr_log(__FUNCTION__, "rows2", $rows2);

    if (count($rows2) == 1) {
        $rows2 = $rows1;
    }
    #??? a voir

    if (count($rows1) > 1) {
        $next_day  = $rows1['day'];
        $next_date = $rows1['date'];
        $prev_day  = $rows2['day'];
        $prev_date = $rows2['date'];
    } else {
        $next_day  = $rows2['day'];
        $next_date = $rows2['date'];
        $prev_day  = $rows2['day'];
        $prev_date = $rows2['date'];
    }
    $r          = explode("-", $next_date);
    $next_day_W = date('W', mktime(0, 0, 0, $r[1], $r[2], $r[0])); // sunday=0, saturday=6, friday=5

    $r          = explode("-", $prev_date);
    $prev_day_W = date('W', mktime(0, 0, 0, $r[1], $r[2], $r[0])); // sunday=0, saturday=6, friday=5

    $day = $next_day;
    if ($today_W == $next_day_W) {
        $day = $next_day;
    } elseif ($today_W >= $prev_day_W) {
        $day = $prev_day;
    }

    return $day;
}

function new_password($id, $key)
{

    $player = get_info_player($id);
    $pseudo = $player['pseudo'];
    $email  = $player['email'];
    $status = $player['status'];

    $errors = array();
    put_new_password_form($key, $status, $pseudo, $email, $errors);
}

function put_new_password_form($key, $status, $pseudo, $email, $errors)
{

    $action = "update_password";

    #echo "<div class=\"passwordbox\">\n";
    echo "<div class=\"passwordbox2\">\n";

    #echo "<div class=\"logintitle\">Top7</div>\n";
    echo "<img src=" . c_logo_file . ">\n";

    echo "<table class=\"login\">\n";

    $title = c_msg_password_title1;
    if ($status == c_player_waiting) {
        $title = c_msg_password_title2;
    }

    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    echo "<h3 class=\"login\">$title</h3>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<form id=\"PasswordForm\" action=\"$action\" method=\"post\" onsubmit=\"return check_not_empty()\">\n";

    echo "<tr>\n";
    echo "<td colspan=\"2\" align=\"left\">";
    $size = c_pseudo_size;
    echo "<input class=\"login\" type=\"text\" size=\"$size\" readonly=\"readonly\" name=\"pseudo\" value=\"$pseudo\">\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td colspan=\"2\" align=\"left\">";
    $size = c_email_size;
    echo "<input class=\"login\" type=\"text\" size=\"$size\" readonly=\"readonly\" name=\"email\" value=\"$email\">\n";
    echo "</td>\n";
    echo "</tr>\n";

    $legend = "Créer ton mot de passe";
    echo "<tr>\n";
    echo "<td colspan=\"2\" align=\"left\">";
    $size = c_password_size;
    echo "<input class=\"login\" type=\"password\" size=\"$size\" id=\"password1\" name=\"password1\" placeholder=\"$legend\">\n";
    echo "<span id=\"resultpw1\"></span>\n";
    echo "</td>\n";
    echo "</tr>\n";

    $legend = "Confirme ton mot de passe";
    echo "<tr>\n";
    echo "<td colspan=\"2\" align=\"left\">";
    echo "<input class=\"login\" type=\"password\" size=\"$size\" id=\"password2\" name=\"password2\" placeholder=\"$legend\">\n";
    echo "<span id=\"resultpw2\"></span>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td>";
    echo "<input type=\"submit\" id=\"RegisterButton\" name=\"button\" value=\"Envoyer\">";
    echo "</td>\n";
    echo "</tr>\n";

    if (count($errors)) {
        echo "<tr>\n";
        echo "<td align=\"left\">";
        echo "Attention ! <br>";
        foreach ($errors as $error) {
            echo "<li>" . utf8_encode($error) . "</li>\n";
        }
        echo "</td>";
        echo "</tr>";
    }
    echo "</table>\n";

    echo "<input type=\"hidden\" name=\"key\"   value=\"$key\">\n";
    echo "<input type=\"hidden\" name=\"status\" value=\"$status\">\n";
    echo "</form>\n";

    echo "</div>\n";
    #echo "</div>\n";

}

function put_password_form($action)
{

    #echo "<div class=\"passwordbox\">\n";
    echo "<div class=\"passwordbox1\">\n";

    #echo "<div class=\"logintitle\">Top7</div>\n";
    echo "<img src=" . c_logo_file . ">\n";

    echo "<table class=\"login\" border=0>\n";

    $title = c_msg_password_title1;
    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    echo "<h3 class=\"login\">$title</h3>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<form id=\"PasswordForm\" action=\"$action\" method=\"post\">\n";

    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    $message = c_msg_password_legend1;
    echo mb_convert_encoding($message, "UTF-8");
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    $size = c_password_size;
    echo "<input class=\"login\" autofocus=\"autofocus\" type=\"email\" size=\"$size\" id=\"email\" name=\"email\" placeholder=\"Ton email\">\n";
    echo "<span id=\"resultemail\"></span>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td>";
    echo "<input type=\"submit\" id=\"ResetPasswordButton\" name=\"button\" value=\"Envoyer\">";
    echo "</td>\n";
    echo "</form>\n";

    $action = "./";
    echo "<form id=\"CancelForm\" action=\"$action\" method=\"post\">\n";
    echo "<td>";
    echo "<input type=\"submit\" id=\"CancelButton\" name=\"button\" value=\"Annuler\">\n";
    echo "</td>\n";
    echo "</form>\n";

    echo "</tr>\n";

    echo "</table>\n";

    echo "</div>\n";
    #echo "</div>\n";

}

function print_alert($alert)
{
    global $alert_msgs;
    $message = $alert_msgs[$alert];
    echo "<script type=\"text/javascript\">
	alert(\"$message\");
</script>";
}

function print_message($message, $action)
{

    $n  = substr_count($message, "\n");
    $px = 220 + 20 * $n;
    $px = $px . "px";

    #echo "<div class=\"messagebox1\">\n";
    echo "<div class=\"messagebox1\" style=\"height: $px\">\n";

    #echo "<div class=\"logintitle\">Top7</div>\n";
    echo "<img src=" . c_logo_file . ">\n";

    echo "<table class=\"login\">\n";

    echo "<tr>\n";
    echo "<td align=\"left\">" . mb_convert_encoding($message, "UTF-8");
    echo "</td>\n";
    echo "</tr>\n";

    $url = dirname($_SERVER['PHP_SELF']);
    if ($action == c_previous) {
        $url = basename($_SERVER['PHP_SELF'], ".php");
    }

    #$url = substr($url,0,strrpos($url, "."));
    $onclick = "window.location.href='$url'; return false;";

    echo "<tr>\n";
    echo "<td>\n";
    echo "<form id=\"CancelForm\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"CancelButton\" name=\"button\" value=\"Retour\" onClick=\"$onclick\">\n";
    echo "</form>\n";
    echo "</td>\n";

    echo "</tr>\n";

    echo "</table>\n";

    echo "</div>\n";
}

function password_in_progress()
{

    $message = "<br>\n";
    $message .= "Patience le message a été envoyé !";
    $message .= "<br><br>\n";
    $message .= "Vérifie ta boite mail et aussi le spam.";
    $message .= "<br>\n";
    $message = mb_convert_encoding($message, 'HTML-ENTITIES', 'UTF-8');
    print_message($message, c_home);
}

function password_instruction($email)
{

    $message = "Un email vient d'être envoyé à l'adresse <b>$email</b> avec un lien qui va te permettre de créer un nouveau mot de passe.";
    $message .= "<br><br>\n";
    $message .= "Si tu ne trouves pas le message, regarde dans le spam.";
    $message .= "<br>\n";
    $message = mb_convert_encoding($message, 'HTML-ENTITIES', 'UTF-8');
    print_message($message, c_home);
}

function password_email_not_found()
{

    $message = "<br>\n";
    $message .= c_msg_password_legend2;
    $message = mb_convert_encoding($message, 'HTML-ENTITIES', 'UTF-8');
    $message .= "<br>\n";
    print_message($message, c_previous);
}

function register_message($errors)
{
    $message = "";
    foreach ($errors as $error) {
        $message .= $error . "<br>\n";
    }

    print_message($message, c_previous);
}

function put_register_form($team, $pseudos, $emails, $errors, $action="register")
{

    #echo "<div class=\"registerbox\">\n";
    echo "<div class=\"registerbox1\">\n";

    echo "<img src=" . c_logo_file . ">\n";

    echo "<table class=\"login\" border=0>\n";


    if( $action == "register") {  # to register a new top7team
        $readonly = ""; 
    } else {  # to register top7team from previous season
        $readonly="readonly";
    }
    


    if (count($errors) == 0) {
        echo "<tr>\n";
        echo "<td colspan=\"3\" align=\"left\">";
        $rule = file_get_contents(c_register_rule_file);
        $rule = mb_convert_encoding($rule, 'HTML-ENTITIES', "UTF-8");
        echo $rule . "\n";
        echo "</td>\n";
        echo "</tr>\n";
    }

    $info  = "Nom de l'équipe";
    $name  = "team";
    $size  = c_team7_size;
    $class = "login";
    $i     = 0;
    if (isset($errors["team"][$i])) {
        $class = "error";
    }

    echo "<tr>\n";

    echo "<td align=\"center\" colspan=\"3\">\n";
    echo "<form id=\"RegisterForm\" action=\"$action\" method=\"post\">\n";
    echo "Equipe ";
    echo "<input class=\"$class\" autofocus=\"autofocus\" type=\"text\" size=\"$size\" name=\"$name\" placeholder=\"$info\" value=\"$team\">";
    echo "</td>\n";
    echo "</tr>\n";

    for ($i = 0, $j = 1; $i < 7; $i++, $j++) {
        $info1 = "Pseudo joueur $j";
        if ($i == 0) {
            $info1 .= " (Capitaine)";
        }

        $info2 = "Email joueur $j";
        $size1 = c_pseudo_size;
        $size2 = c_password_size;
        $email = $pseudo = "";
        if (isset($pseudos[$i])) {
            $pseudo = $pseudos[$i];
        }

        if (isset($emails[$i])) {
            $email = $emails[$i];
        }

        $class1 = $class2 = "login";
        if (isset($errors["pseudo"][$i])) {
            $class1 = "error";
        }

        if (isset($errors["email"][$i])) {
            $class2 = "error";
        }

        echo "<tr>\n";
        echo "<td align=\"right\">";
        if ($i == 0) {
            echo "(C) ";
        }

        echo "Joueur $j ";
        echo "</td>\n";
        echo "<td>";
        echo "<input class=\"$class1\" $readonly type=\"text\" size=\"$size1\" name=\"pseudos[]\" placeholder=\"$info1\" value=\"$pseudo\">";
        echo "</td>\n";
        echo "<td>";
        echo "<input class=\"$class2\" $readonly type=\"text\" size=\"$size2\" name=\"emails[]\" placeholder=\"$info2\" value=\"$email\">";
        echo "</td>\n";
        echo "</tr>\n";
    }

    if (count($errors)) {
        echo "<tr>\n";
        echo "<td colspan=\"3\" align=\"left\">";
        echo "Il y a quelques erreurs à corriger dans les champs sur fond rouge :\n";
        echo "<ul>\n";
        foreach ($errors["msg"] as $msg) {
            #echo "<li>" . utf8_encode($msg) . "</li>\n";
            echo "<li>" . $msg . "</li>\n";
        }

        echo "</ul>\n";
        echo "</td>\n";
        echo "</tr>\n";
    }

    echo "<tr>\n";
    echo "<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
    echo "</td>\n";
    echo "<td align=\"center\">\n";

    // google recaptcha
    echo "<input type=\"hidden\" id=\"g-recaptcha-response\" name=\"g-recaptcha-response\">\n";
    echo "<input type=\"hidden\" name=\"action\" value=\"validate_captcha\">\n";

    echo "<input type=\"submit\" id=\"RegisterButton\" name=\"button\" value=\"Envoyer\">\n";

    echo "</form>\n";
    echo "</td>\n";


    $action = "./";
    echo "<td align=\"center\">\n";
    echo "<form id=\"CancelForm\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"CancelButton\" name=\"button\" value=\"Annuler\">\n";
    echo "</form>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "</table>\n";

    echo "</div>\n";
    #echo "</div>\n";

}

function register($action)
{

    echo "<div class=\"registerbox\">\n";

    #echo "<div class=\"logintitle\">Top7</div>\n";
    echo "<img src=" . c_logo_file . ">\n";

    echo "<table class=\"login\">\n";

    $size = 30;
    echo "<form id=\"RegisterForm\" action=\"$action\" method=\"post\">\n";

    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    echo "Pour s'inscrire il suffit d'un pseudo, d'un email et d'un mot de passe.";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    echo "<input class=\"login\" autofocus=\"autofocus\" type=\"text\" size=\"$size\" id=\"pseudo\" name=\"pseudo\" placeholder=\"Choisissez votre pseudo\">\n";
    echo "<span id=\"resultpseudo\"></span>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    echo "<input class=\"login\" type=\"email\" size=\"$size\" id=\"email\" name=\"email\" placeholder=\"Ton email\">\n";
    echo "<span id=\"resultemail\"></span>\n";
    echo "</td>\n";
    echo "</tr>\n";

    $legend = "Créer votre mot de passe";
    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    echo "<input class=\"login\" type=\"password\" size=\"$size\" id=\"password1\" name=\"password1\" placeholder=\"$legend\">\n";
    echo "<span id=\"resultpw1\"></span>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td colspan=\"2\">";
    echo "<input class=\"login\" type=\"password\" size=\"$size\" id=\"password2\" name=\"password2\" placeholder=\"Confirmer votre mot de passe\">\n";
    echo "<span id=\"resultpw2\"></span>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td>";
    echo "<input type=\"submit\" id=\"RegisterButton\" name=\"button\" value=\"S'inscrire\">";
    echo "</td>\n";
    echo "</form>\n";

    $action = "./";
    echo "<form id=\"CancelForm\" action=\"$action\" method=\"post\">\n";
    echo "<td>";
    echo "<input type=\"submit\" id=\"CancelButton\" name=\"button\" value=\"Annuler\">";
    echo "</td>\n";
    echo "</form>\n";

    echo "</tr>\n";

    echo "</table>\n";

    echo "</div>\n";
}

function put_login_form($token)
{

    init_sql();
    setlocale(LC_TIME, "fr_FR.utf8");

    echo "<div class=\"loginbox1\">\n";

    $now                = now();
    $top7_season        = get_top7_season();
    $season             = $top7_season['Id'];
    $season_start       = strtotime($top7_season['start']);
    $start_register     = strtotime($top7_season['start_register']);
    $stop_register      = strtotime($top7_season['stop_register']);
    $time_season_opened = get_first_day_season($season);

    echo "<table class=\"login\" border=0>\n";
    echo "<tr>\n";
    echo "<td align=\"center\">";
    if ($now > $time_season_opened and $now < $stop_register) {
        $legend = "Nouvelle " . $top7_season['title'];
    } else {
        $legend = $top7_season['title'];
    }

    echo "<div class=\"season\">$legend</div>\n";
    echo "</td>\n";
    echo "</tr>\n";
    echo "<tr>\n";
    echo "<td align=\"center\">";
    if ($now > $time_season_opened and $now < $stop_register) {
        echo "<div class=\"season_start\">Le jeu peut démarrer à tout moment en cours de saison ...</div>";
    }

    echo "<div class=\"season_start\">&nbsp;</div>";
    echo "</td>\n";
    echo "</tr>\n";
    echo "<tr>\n";
    echo "<td align=\"center\">";
    $display_register_link = false;
    if ($now >= $season_start and $now < $stop_register) {
        if ($now < ($start_register - 3600*24)) {
            echo "<div class=\"season\">Crée ton équipe dès le " . strftime("%d %B", $start_register) . " !</div>";
        } else {
            echo "<div class=\"season\">Crée ton équipe maintenant !</div>";
            $display_register_link = true;
        }
    }
    echo "</td>\n";
    echo "</tr>\n";
    echo "</table>\n";

    #echo "<img src=\"top7.png\">\n";
    echo "<img src=\"top7_new.png\">\n";

    $action = "login";
    echo "<form id=\"LoginForm\" action=\"$action\" method=\"post\">\n";

    echo "<table class=\"login\" border=0>\n";

    echo "<tr>\n";
    echo "<td align=\"center\">";
    $legend = c_msg_home_legend4;
    echo "<a class=\"login\" href=\"intro\">$legend</a>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td align=\"left\">";
    $size = c_email_size;
    echo "<input class=\"login\" autofocus=\"autofocus\" type=\"text\" size=\"$size\" name=\"login\" placeholder=\"Ton email\">";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td align=\"left\">";
    $size = c_password_size;
    echo "<input class=\"login\" type=\"password\" size=\"$size\" name=\"password\" placeholder=\"Ton mot de passe\">";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td align=\"left\">";
    $legend = c_msg_home_legend1;
    echo "<a class=\"login\" href=\"password\">$legend</a>\n";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td align=\"left\">";
    echo "<input type=\"submit\" id=\"ConnectButton\" name=\"button\" value=\"Se connecter\">";
    echo "</td>\n";
    echo "</tr>\n";

    echo "<tr>\n";
    echo "<td>";
    if ($display_register_link) {
        echo c_msg_home_legend2 . "\n";
        $legend = c_msg_home_legend3;
        echo "<a class=\"login\" href=\"register\">$legend</a>\n";
    }
    echo "</td>\n";
    echo "</tr>\n";

    echo "</table>\n";

    echo "<input type=\"hidden\" name=\"token\" value=\"$token\">\n";

    // google recaptcha
    echo "<input type=\"hidden\" id=\"g-recaptcha-response\" name=\"g-recaptcha-response\">\n";
    echo "<input type=\"hidden\" name=\"action\" value=\"validate_captcha\">\n";

    echo "</form>\n";

    echo "</div>\n";
    #echo "</div>\n";

}

function display_info_player($player, $p)
{

    global $strDate;
    global $player_status;

    if (!isset($player)) {
        $player = "?";
    }

    $game = $p['game'];

    $info     = get_info_player($player);
    $pseudo   = $info['pseudo'];
    $palmares = get_palmares_player($info['email']);
    $team     = get_top7team_name($info['team']);
    $captain  = get_top7team_captain($info['team']);
    $date_reg = utf8_encode(strftime($strDate, strtotime($info['date_reg'])));

    $password = get_last_password_email($player);

    $line_mode_pseudo = c_line_info;
    $div1             = "edit1";
    $comment_pseudo   = "";
    if ($info['player_idx'] == $p['player']) {
        $line_mode_pseudo = c_line_edit;
    }

    $line_mode_email  = c_line_info;
    $comment_email    = "";
    $div2             = "";
    $status           = $player_status[$info['status']];
    $comment_status   = "";
    $line_mode_status = c_line_info;
    if ($info['status'] == c_player_waiting) {
        $line_mode_email  = c_line_edit;
        $div2             = "edit2";
        $comment_email    = "Attention, un changement d'email renvoie une nouvelle inscription à valider.";
        $delay            = get_forum_delay(now() - $password['time']);
        $status           = $player_status[$info['status']] . ", depuis $delay.";
        $comment_status   = "Cliquer pour renvoyer un email d'inscription.";
        $line_mode_status = c_line_button;
    }
    if ($game == c_season_over) {
        $line_mode_pseudo = c_line_info;
        $line_mode_email  = c_line_info;
        $line_mode_status = c_line_info;
    }

    $infos = array(
        array(
            "line" => $line_mode_pseudo, "div"  => $div1, "name"                  => "pseudo", "title" => "Pseudo",
            "info"       => $info['pseudo'], "player" => $info['player_idx'], "comment" => $comment_pseudo
        ),
        array(
            "line" => $line_mode_email, "div"  => $div2, "name"                  => "email", "title" => "Email",
            "info"       => $info['email'], "player" => $info['player_idx'], "comment" => $comment_email
        ),
        array(
            "line" => $line_mode_status, "title" => "Status", "status"             => $info['status'],
            "info"       => $status, "player"          => $info['player_idx'], "comment" => $comment_status,
            "pseudo"     => $info['pseudo'], "email"   => $info['email'], "team"         => $info['team'], "captain" => $captain
        ),
    );
    if ($info['status'] == c_player_enable) {
        $infos[] = array("line" => c_line_info, "title" => "Inscrit le", "info" => $date_reg);
    }

    $infos[] = array("line" => c_line_info, "title" => "Equipe Top7", "info" => $team);
    $infos[] = array("line" => c_line_info, "title" => "Capitaine", "info" => $captain);

    foreach ($palmares as $info) {
        if ($info['rank'] == "") {
            if ($info['season'] == c_canceled_season) {
                $info['rank'] = "Annulée";
            } else {
                $info['rank'] = "En cours";
            }
        }

        $infos[] = array(
            "line" => c_line_button, "title"        => $info['title'], "info" => $info['rank'],
            "player"                => $info['player_idx'], "season" => $info['season']
        );
    }

    print_table_info("Joueur Top7", $infos);
}

function print_table_info($title, $infos)
{

    echo "<table class=\"player\">\n";
    echo "<tr class=\"player\">\n";
    echo "<th class=\"top7\" colspan=\"3\">$title</th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    echo "<table class=\"player\" border=0>\n";

    foreach ($infos as $k => $element) {
        if ($element['line'] == c_line_info) {
            put_line_info($element);
        }

        if ($element['line'] == c_line_edit) {
            put_line_edit($k, $element);
        }

        if ($element['line'] == c_line_button) {
            put_line_button($element);
        }
    }

    echo "</table>\n";
}

function put_player_link($p)
{

    $player              = $p['player'];
    $day                 = $p['day'];
    $season              = $p['season'];
    $mode                = $p['mode'];
    $pseudo              = $p['pseudo'];
    $captain             = $p['captain'];
    $register_new_season = $p['register_new_season'];

    printr_log(__FUNCTION__, "p", $p);
    printr_log(__FUNCTION__, "get_top7_season()", get_top7_season());
    

    if( $register_new_season) {
        $top7_season = get_top7_season();
        $new_season  = strtolower($top7_season['title']);
    }

    $team     = "?";
    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    if ($top7team > 0) {
        $team = get_top7team_name($top7team);
    }

    $top7_season = get_top7_season_by_id($season);

    echo "<table class=\"player_link\" border=0>\n";

    echo "<tr>\n";
    echo "<td align=\"left\" width=\"15%\">";
    echo "<img src=" . c_logo_file . ">\n";
    echo "</td>\n";
    echo "<td class=\"season_title\" align=\"left\" width=\"25%\">";
    echo $top7_season['title'];
    echo "</td>\n";

    if (strrpos($_SERVER['REQUEST_URI'], "stats")) {
        echo "<td class=\"season_title\" align=\"center\" width=\"10%\">";
        $action = "display";
        $title  = "Retour au TOP7";
        $idbutton = "StatsButton";
        echo "<form id=\"form_stats\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\" id=\"$idbutton\" class=\"selected\" value=\"$title\">\n";
        echo "</form>\n";
        echo "</td>\n";

        echo "<td class=\"season_title\" align=\"center\" width=\"10%\">";
        $action = "records";
        $title  = "RECORDS & PALMARES";
        $idbutton = "RecordsButton";
        echo "<form id=\"form_stats\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\" id=\"$idbutton\" class=\"selected\" value=\"$title\">\n";
        echo "</form>\n";
        echo "</td>\n";
    } elseif (strrpos($_SERVER['REQUEST_URI'], "records")) {
        echo "<td class=\"season_title\" align=\"center\" width=\"10%\">";
        $action = "display";
        $title  = "Retour au TOP7";
        $idbutton = "StatsButton";
        echo "<form id=\"form_stats\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\" id=\"$idbutton\" class=\"selected\" value=\"$title\">\n";
        echo "</form>\n";
        echo "</td>\n";

        echo "<td class=\"season_title\" align=\"center\" width=\"20%\">";
        $action = "stats";
        $title  = "STATS Inter-EQUIPES !";
        $idbutton = "StatsButton";
        echo "<form id=\"form_stats\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\" id=\"$idbutton\" class=\"selected\" value=\"$title\">\n";
        echo "</form>\n";
        echo "</td>\n";
    } else {

        echo "<td class=\"season_title\" align=\"center\" width=\"20%\">";
        $action = "stats";
        $title  = "STATS Inter-EQUIPES !";
        $idbutton = "StatsButton";
        echo "<form id=\"form_stats\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\" id=\"$idbutton\" class=\"selected\" value=\"$title\">\n";
        echo "</form>\n";
        echo "</td>\n";
    }


    echo "<td align=\"right\" width=\"40%\">";
    if ($mode == c_admin) {
        display_select_params();
        display_select_reset();
        display_select_day($day);
        display_select_top7team($top7team);
        display_select_player($top7team, $player);
    }
    echo "Equipe : <a href=\"team\">$team</a> - ";
    if ($captain) {
        echo "Capitaine : <a href=\"player\">$pseudo</a> - ";
    } else {
        echo "Joueur : <a href=\"player\">$pseudo</a> - ";
    }

    echo "<a href=\"logout\">Deconnexion</a>";
    echo "</td>\n";
    echo "</tr>\n";

    if ($register_new_season) {
        echo "<tr>\n";
        echo "<td class=\"alert\" colspan=\"3\">\n";
        echo "Nouvelle $new_season, <a href=\"register_new_season\" title=\"Capitaine, réinscrit ton équipe pour la nouvelle saison\">clique ici !</a>";
        echo "</td>\n";
        echo "</tr>\n";
    }

    echo "</table>\n";
}

function put_nav($p)
{

    printr_log(__FUNCTION__, "SESSION", $p);

    $player = 0;
    if (isset($p['player'])) {
        $player = $p['player'];
    }

    $to_display = 0;
    if (isset($p['display'])) {
        $to_display = $p['display'];
    }

    $mode = 0;
    if (isset($p['mode'])) {
        $mode = $p['mode'];
    }

    $next = c_top14;

    $status = 0;
    if (isset($p['status'])) {
        $status = $p['status'];
    }

    $season = 0;
    if (isset($p['season'])) {
        $season = $p['season'];
    }

    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    $selected_top14_team = 0;
    if (isset($p['top14team'])) {
        $selected_top14_team = $p['top14team'];
    }

    $selected_top7_player = 0;
    if (isset($p['top7_player'])) {
        $selected_top7_player = $p['top7_player'];
    }

    echo "<table class=\"nav\" border=0>\n";
    echo "<tr>\n";

    if ($status == c_can_play and $mode == c_player and $player > 0) {

        echo "<td class=\"nav\">";
        $title    = "Prono";
        $action   = "display";
        $game     = c_enable;
        $display  = c_top7_player;
        $selected = "";
        if ($to_display == $display) {
            $selected = "class=\"selected\"";
        }

        echo "<form id=\"form_play\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\" id=\"PronoButton\" $selected value=\"$title\">\n";
        echo "<input type=\"hidden\" name=\"game\" value=\"$game\">\n";
        echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
        echo "</form>\n";
        echo "</td>\n";
    }

    if ($mode == c_admin) {

        echo "<td class=\"nav\">";
        $title    = "Match Top14";
        $action   = "calendar";
        $display  = c_top14_match;
        $selected = "";
        if ($to_display == $display) {
            $selected = "class=\"selected\"";
        }

        echo "<form id=\"form_admin\" action=\"$action\" method=\"post\">\n";
        echo "<input type=\"submit\" id=\"Rank7Button\" $selected value=\"$title\">\n";
        echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
        echo "</form>\n";
        echo "</td>\n";
    }

    echo "<td class=\"nav\">";

    if ($mode == c_admin) {
        $action = "update_day";
    } else {
        $action = "display";
    }

    $title    = "Résultats Top7";
    $display  = c_top7;
    $game     = c_disable;
    $idbutton = "Rank7Button";
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    echo "<form id=\"form_home\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"$idbutton\" $selected value=\"$title\">\n";
    echo "<input type=\"hidden\" name=\"game\" value=\"$game\">\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "</form>\n";

    echo "</td>\n";

    echo "<td class=\"nav\">";

    $title    = "Classement Top7";
    $action   = "rank7";
    $display  = c_rank7;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    echo "<form id=\"form_rank7\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"$idbutton\" $selected value=\"$title\">\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "</form>\n";

    echo "</td>\n";

    echo "<td class=\"nav\">";

    $title    = "Joueur Top7";
    $action   = "rank7";
    $display  = c_top7_match;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    $players = get_top7_players($top7team);

    echo "<form id=\"form_top7_team\" action=\"$action\" method=\"post\">\n";
    echo "<select name=\"top7_player\" id=\"Top7PlayerSelect\" $selected onChange=\"if(this.value!='none') this.form.submit();\">\n";
    echo "<option selected=\"selected\" value=\"none\">$title</option>\n";
    foreach ($players as $idx => $top7_player) {
        echo "<option value=$idx>$top7_player</option>\n";
    }
    echo "</select>\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "</form>\n";

    echo "</td>\n";

    echo "<td class=\"nav\">";

    if ($mode == c_admin) {
        $action = "update_day";
    } else {
        $action = "display";
    }

    $title    = "Résultats Top14";
    $idbutton = "Rank14Button";
    $display  = c_top14;
    $game     = c_disable;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    echo "<form id=\"form_home\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"$idbutton\" $selected value=\"$title\">\n";
    echo "<input type=\"hidden\" name=\"game\" value=\"$game\">\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "</form>\n";
    echo "</td>\n";

    echo "<td class=\"nav\">";

    $title    = "Classement Top14";
    $action   = "rank";
    $display  = c_rank14;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    echo "<form id=\"form_rank14\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"$idbutton\" $selected value=\"$title\">\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "</form>\n";

    echo "</td>\n";

    echo "<td class=\"nav\">";

    $title    = "Equipe Top14";
    $action   = "rank";
    $display  = c_team14;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    $teams = get_top14_teams($season);

    echo "<form id=\"form_top14_team\" action=\"$action\" method=\"post\">\n";
    echo "<select name=\"top14team\" id=\"Top14TeamSelect\" $selected onChange=\"if(this.value!='none') this.form.submit();\">\n";
    echo "<option selected=\"selected\" value=\"none\">$title</option>\n";
    foreach ($teams as $idx => $team) {
        echo "<option value=$idx>$team</option>\n";
    }
    echo "</select>\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "</form>\n";

    echo "</td>\n";

    echo "<td class=\"nav\">";

    $title    = "Final";
    $action   = "display";
    $display  = c_top_final;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    echo "<form id=\"form_rank14\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"$idbutton\" $selected value=\"$title\">\n";
    echo "<input type=\"hidden\" name=\"display\" value=\"$display\">\n";
    echo "</form>\n";

    echo "</td>\n";

    echo "</tr>\n";
    echo "</table>\n";
}

function put_bottom_info($p)
{

    $top = basename($_SERVER['PHP_SELF'], ".php");

    echo "<br>\n";
    echo "<table class=\"nav\" border=0>\n";
    echo "<tr><td>\n";
    echo "<div class=\"info\">\n";
    echo "<a href=\"javascript:unhide('manual');\">Comment jouer ?</a> - ";
    echo "<a href=\"javascript:unhide('blog');\">Les brèves d'Ovalie</a> - ";
    echo "<a href=\"javascript:unhide('rules');\">Les règles du Top7</a>";
    if ($top == "rank7" or $top == "rank") {
        echo " - <a href=\"javascript:unhide('legend');\">Légendes</a>";
    }

    if ($top == "rank7") {
        echo " - <a href=\"javascript:unhide('pointsFun');\">Points fun</a>";
    }

    echo " - <a href=\"javascript:unhide('contact');\">Contact</a>";
    echo "</div>\n";

    put_manual();
    put_blog();
    put_rules();
    if ($top == "rank7") {
        put_legend(c_top7);
    }

    if ($top == "rank") {
        put_legend(c_top14);
    }

    put_contact();

    echo "</td></tr>\n";
    echo "</table>\n";
}

function get_forum_delay($diff)
{
    $years = abs(floor($diff / 31536000));
    $days  = abs(floor(($diff - ($years * 31536000)) / 86400));
    $hours = abs(floor(($diff - ($years * 31536000) - ($days * 86400)) / 3600));
    $mins  = abs(floor(($diff - ($years * 31536000) - ($days * 86400) - ($hours * 3600)) / 60)); #floor($difference / 60);
    $s     = "";
    $delay = "0 mn";
    if ($years) {
        if ($years > 1) {
            $s = "s";
        }

        $delay = "$years an$s";
    } elseif ($days) {
        if ($days > 1) {
            $s = "s";
        }

        $delay = "$days jour$s";
    } elseif ($hours) {
        if ($hours > 1) {
            $s = "s";
        }

        $delay = "$hours heure$s";
    } elseif ($mins) {
        if ($mins > 1) {
            $s = "s";
        }

        $delay = "$mins mn$s";
    }
    return $delay;
}

function update_forum($p, $s)
{
    $f = "update_forum";

    $team    = $s['top7team'];
    $player  = $s['player'];
    $day     = $s['day'];
    $season  = $s['season'];
    $format  = "%Y-%m-%d %H:%M";
    $date    = strftime($format, now());
    $parent  = $p['parent'];
    $comment = addslashes($p['comment']);

    $query = "insert into `forum` ( `idx2`, `team`, `player`, `season`, `day`, `date`, `comment`) ";
    $query .= "value ('$parent', '$team', '$player', '$season', '$day', '$date', '$comment')";
    pdo_exec(__FUNCTION__, $query);
}

function get_forum($p)
{

    $day    = $p['day'];
    $season = $p['season'];
    $team   = $p['top7team'];

    $query = "select idx1, idx2, date, pseudo, comment from `forum` ";
    $query .= "join player on player=player_idx ";
    $query .= "where forum.team=$team and forum.day=$day and forum.season=$season ";
    $query .= "order by date ";
    $rows = pdo_fetch(__FUNCTION__, c_all, $query);

    $comments = array();
    $tree     = array();
    foreach ($rows as $row) {
        $idx1            = $row['idx1'];
        $idx2            = $row['idx2'];
        $comments[$idx1] = $row;
        $tree[$idx1]     = $idx2;
    }
    $res = to_tree($tree);
    return array('tree' => $res, 'comments' => $comments);
}

function print_forum_comment($comment)
{

    $pseudo        = $comment['pseudo'];
    $date          = $comment['date'];
    $text          = $comment['comment'];
    $breaks        = array("\n");
    $text          = str_ireplace($breaks, "<br>", $text);
    $text_with_url = preg_replace('"\b(https?://\S+)"', '<a href="$1" target="_blank">$1</a>', $text);
    $parent        = $comment['idx1'];
    $delay         = get_forum_delay(now() - strtotime($date));
    if (strlen($delay)) {
        $interval = "il y a $delay";
    } else {
        $interval = "à l'instant";
    }

    echo "<div class=\"forumtext\">\n";
    echo $text_with_url . "<br>\n";
    echo "&nbsp;&nbsp;&nbsp;<i>Posté par</i> $pseudo<i>, $interval.</i><br>\n";
    put_forum_form($parent);
    echo "</div>\n";
    echo "<hr>\n";
}

function print_forum_loop($tree, $comments)
{

    if (count($tree)) {
        echo "<ul>\n";
        foreach ($tree as $child => $parent) {
            $comment = $comments[$child];
            print_forum_comment($comment);
            print_forum_loop($tree[$child], $comments);
        }
        echo "</ul>\n";
    }
}

function to_tree($array)
{
    $flat = array();
    $tree = array();

    foreach ($array as $child => $parent) {
        if (!isset($flat[$child])) {
            $flat[$child] = array();
        }
        if (!empty($parent)) {
            $flat[$parent][$child] = &$flat[$child];
        } else {
            $tree[$child] = &$flat[$child];
        }
    }

    return $tree;
}

function put_forum_form($parent)
{

    if ($_SESSION['season'] < $_SESSION['top7_season']) {
        return;
    }

    if ($_SESSION['close_forum'] < now()) {
        return;
    }

    $action = "update_forum";
    $form   = "<form id=\"CommentForm\" method=\"post\" action=\"$action\">\n";
    $form .= "<textarea class=\"login\" name=\"comment\" rows=\"4\" cols=\"60\" placeholder=\"Entre ton commentaire\"></textarea>\n";
    $form .= "<input type=\"submit\" id=\"CommentButton\" name=\"button\" value=\"Envoyer\">\n";
    $form .= "<input type=\"hidden\" name=\"parent\" value=\"$parent\">\n";
    $form .= "</form>\n";

    $id = "comment$parent";
    echo "<div class=\"newcomment\">\n";
    if ($parent) {
        echo "<a href=\"javascript:unhide('$id');\">Repondre au commentaire</a>";
    } else {
        echo "<a href=\"javascript:unhide('$id');\">Nouveau commentaire</a>";
    }
    echo "</div>\n";

    echo "<div id=\"$id\" class=\"hidden\">\n";
    echo "<div class=\"newcomment\">\n";
    echo $form;
    echo "</div>\n";
    echo "</div>\n";
}

function put_forum($p)
{

    $day   = $p['day'];
    $title = get_day_title($day);

    echo "<br>\n";
    echo "<table class=\"forum\">\n";
    echo "<tr class=\"forumtitle\"><th>Forum - $title</th></tr>\n";

    $mix            = get_forum($p);
    $tree           = $mix['tree'];
    $comments       = $mix['comments'];
    $nb_of_comments = count($comments);
    $s              = '';
    if ($nb_of_comments > 1) {
        $s = 's';
    }

    echo "<tr><td>\n";
    echo "<div class=\"info\">\n";
    echo "<a href=\"javascript:unhide('forum');\">$nb_of_comments commentaire$s</a>\n";
    echo "</div>\n";
    echo "</td></tr>\n";

    echo "<tr><td>\n";
    echo "<div id=\"forum\" class=\"unhidden\">\n";
    print_forum_loop($tree, $comments);
    echo "</td></tr>\n";
    echo "</div>\n";
    echo "</table>\n";

    echo "<table class=\"forum\">\n";
    echo "<tr><td>\n";
    put_forum_form(0);
    echo "</td></tr>\n";
    echo "</table>\n";
}

function put_manual()
{

    echo "<div id=\"manual\" class=\"hidden\">\n";
    echo "<div class=\"info\">\n";

    readfile(c_manual_file);

    echo "</div>\n";
    echo "</div>\n";
}

function put_contact()
{

    echo "<div id=\"contact\" class=\"hidden\">\n";
    echo "<div class=\"info\">\n";

    readfile(c_contact_file);

    echo "</div>\n";
    echo "</div>\n";
}

function put_legend($top)
{

    echo "<div id=\"legend\" class=\"hidden\">\n";
    echo "<div class=\"info\">\n";

    if ($top == c_top7) {
        readfile(c_legend7_file);
    }

    if ($top == c_top14) {
        readfile(c_legend14_file);
    }

    echo "</div>\n";
    echo "</div>\n";

    echo "<div id=\"pointsFun\" class=\"hidden\">\n";
    echo "<div class=\"info\">\n";

    if ($top == c_top7) {
        readfile(c_pointsFun_file);
    }

    echo "</div>\n";
    echo "</div>\n";
}

function put_rules()
{

    echo "<div id=\"rules\" class=\"hidden\">\n";
    echo "<div class=\"info\">\n";

    readfile(c_rules_file);

    echo "</div>\n";
    echo "</div>\n";
}

function put_blog()
{

    echo "<div id=\"blog\" class=\"unhidden\">\n";
    echo "<div class=\"info\">\n";

    echo "<h3>L'Hebdo du rugby par Antonio</h3>\n";
    $news = array();
    if (c_display_blog) {
        $news = get_rss(c_file_blog, c_nb_news);
    }

    foreach ($news as $new) {
        echo "<li>";
        echo "<a href=\"" . $new['link'] . "\" target=\"_blank\">" . $new['title'] . "</a>\n";
        echo " : " . $new['description'];
        echo "</li>\n";
    }
    echo "</div>\n";
    echo "</div>\n";
}

function check_session()
{

    session_start();
    printr_log(__FUNCTION__, "SESSION", $_SESSION);

    if (isset($_SESSION['last_activity']) && (now() - $_SESSION['last_activity'] > c_session_activity)) {
        session_unset();
        session_destroy();
        echo '<meta http-equiv="refresh" content="0;URL=index">';
        exit;
    }
    $_SESSION['last_activity'] = now();

    if (!isset($_SESSION['login'])) {
        echo '<meta http-equiv="refresh" content="0;URL=index">';
    }

    if (!isset($_SESSION['token'])) {
        echo '<meta http-equiv="refresh" content="0;URL=index">';
    }
}

function save_rss($url)
{
    file_put_contents(c_file_blog, file_get_contents(c_url_blog));
}

function get_rss($file, $nb_news)
{

    $t_news = array();

    if (filesize($file) == 0) {
        return $t_news;
    }
    // ticket 58

    if ($xml = simplexml_load_file($file)) {

        $i = 1;
        foreach ($xml->channel->item as $item) {
            $news          = array();
            $news["title"] = $item->title;
            $news["link"]  = $item->link;
            $news["date"]  = $item->pubDate;
            $s             = strip_tags($item->description, "<p>");
            $n             = stripos($s, "</p>") + 5;
            #echo "n=$n";
            $news["description"] = strip_tags(substr($s, 0, $n));
            #$news["description"] = $item->description;
            $t_news[] = $news;
            $i++;
            if ($i > $nb_news) {
                break;
            }
        }
    }
    return $t_news;
}

function get_time_game_closed($day, $today, $season, $monday)
{
    print_log(__FUNCTION__, "today", $today);
    print_log(__FUNCTION__, "day", $day);

    if ($today > $day) {
        $day = $today;
    }

    $query = "select date, time from `match` where day=$day and season=$season order by date,time limit 1";
    $row   = pdo_fetch(__FUNCTION__, c_one, $query);

    $d                = explode("-", $row['date']);
    $t                = explode(":", $row['time']);
    $time_game_closed = mktime($t[0] - 1, $t[1], 0, $d[1], $d[2], $d[0]); // 1h avant le 1er match

    print_log(__FUNCTION__, "time_game_closed", $time_game_closed);

    return $time_game_closed;
}

function get_monday_from_day($day, $today, $season)
{

    if ($today > $day) {
        $day = $today;
    }

    $query = "select date from `match` where day=$day and season=$season order by date limit 1";
    $row   = pdo_fetch(__FUNCTION__, c_one, $query);
    $r     = explode("-", $row['date']);
    $day_w = date('w', mktime(0, 0, 0, $r[1], $r[2], $r[0])); // sunday=0, saturday=6, friday=5
    if ($day_w == 0) {
        $day_w = 7;
    }

    $monday = mktime(0, 0, 0, $r[1], $r[2] - $day_w + 1, $r[0]);
    #echo "day=$day, day_w=$day_w";
    #printr( $r);
    #printr( $row);
    #echo "<pre> today:" . strftime("%Y-%m-%d %H:%M", now()) . " - monday:" . strftime( "%Y-%m-%d", $monday) . " - thursday:" . strftime( "%Y-%m-%d", $monday + c_time_game_closed) . "</pre>";
    return $monday;
}

function check_game_closed($top7team, $day)
{

    $query = "select player_idx from `prono` ";
    $query .= "left join `player` on player.player_idx=prono.player ";
    $query .= "where prono.day=$day and player.team=$top7team";
    $players = pdo_fetch(__FUNCTION__, c_all, $query);

    printr_log(__FUNCTION__, "players", $players);

    $res = false;
    if ($day <= c_last_day and count($players) == 7) {
        $res = true;
    }

    if ($day == c_barrage_day and count($players) == 4) {
        $res = true;
    }

    if ($day == c_demifinales_day and count($players) == 4) {
        $res = true;
    }

    if ($day == c_finale_day and count($players) == 2) {
        $res = true;
    }

    $time_game_closed = $_SESSION['time_game_closed'];
    if (now() > $time_game_closed) {
        $res = true;
    }

    return $res;
}

function get_all_players($season)
{

    $team_status   = c_team_enable;
    $player_status = c_player_enable;
    $query         = "select player_idx as player, pseudo, team as top7team from player join team_player ";
    $query .= "on player.team=team_player.team_idx and player.season=team_player.season ";
    $query .= "where player.status=$player_status and team_player.status=$team_status and player.season=$season";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function check_status_player($p)
{

    printr_log(__FUNCTION__, "p", $p);
    $player           = $p['player'];
    $info_player      = get_info_player($player);
    $info_team        = get_info_team($info_player['team']);
    $status           = array();
    $status['player'] = $info_player['status'];
    $status['team']   = $info_team['status'];
    printr_log(__FUNCTION__, "status", $status);
    return $status;
}

function get_top7_day_selection($day, $p)
{

    global $phase_finale_player;

    $monday           = $p['monday'];
    $time_game_closed = $p['time_game_closed'];
    $top7team         = $p['top7team'];

    if ($day <= c_last_day) {
        $ranks = get_rank7($day, $top7team);
    }

    if ($day == c_barrage_day) {
        $ranks = get_rank7(c_last_day, $top7team);
    }

    if ($day == c_demifinales_day) {
        $ranks1 = get_rank7(c_last_day, $top7team);
        $ranks2 = get_rank7_one_day(c_barrage_day, $top7team);
#        $ranks  = array($ranks1[0], $ranks1[1], $ranks2[1], $ranks2[0]);
        $ranks  = array($ranks1[0], $ranks1[1], $ranks2[0], $ranks2[1]);
        printr_log(__FUNCTION__, "ranks1 day=$day", $ranks1);
        printr_log(__FUNCTION__, "ranks2 day=$day", $ranks2);
    }
    if ($day == c_finale_day) {
        $ranks = get_rank7_one_day(c_demifinales_day, $top7team);
    }

    printr_log(__FUNCTION__, "ranks day=$day", $ranks);
    if (count($ranks) == 0 or $day == 1) {
        $ranks = get_random_rank7($top7team);
        printr_log(__FUNCTION__, "ranks day=$day - random", $ranks);
    }

    $query = "select * from ";
    $query .= "( select player_idx as registered, pseudo  from `player` where player.team=$top7team) as t1 ";
    $query .= "left join ";
    $query .= "( select player as played from `prono` where day=$day) as t2 ";
    $query .= "on registered=played";
    $rows = pdo_fetch(__FUNCTION__, c_all, $query);
    foreach ($rows as $row) {
        $players[$row['registered']] = $row;
    }

    $now         = now();
    $selections  = array();
    $midi_minuit = array("minuit", "midi");

    if ($day <= c_last_day) {

        if ($day > 1) $ranks = array_reverse($ranks);    # 1st day
        #$ranks = array_reverse($ranks);    # 1st day

        $i          = 0;
        $prev_prono = 0;
        foreach ($ranks as $rank) {
            $player   = $rank['player'];
            $deadline = $monday + $i * c_time_deadline - 10;
            if ($now > $deadline) {
                $status = c_can_play;
            } else {
                $status = c_cannot_play;
            }

            if ($players[$player]['registered'] == $players[$player]['played']) {
                $prono = c_played;
            } else {
                $prono = c_not_played;
            }

            if ($prono == c_not_played and $prev_prono == c_played) {
                $status = c_can_play;
            }

            $info         = "(à partir de " . utf8_encode(strftime("%A %d %b ", $deadline)) . $midi_minuit[$i % 2] . ")";
            $selections[] = $players[$player]
                + array("deadline" => $deadline, "prono" => $prono, "status" => $status, "info" => $info);
            $i++;
            if ($prev_prono == c_not_played) {
                $prev_prono = c_not_played;
            } else {
                $prev_prono = $prono;
            }
        }
    } else {

        $phase = 0;
        if (isset($p['phase'])) {
            $phase = $p['phase'];
        }

        $deadline1 = 0;
        if (isset($p['deadline1'])) {
            $deadline1 = $p['deadline1'];
        }

        $deadline2 = 0;
        if (isset($p['deadline2'])) {
            $deadline2 = $p['deadline2'];
        }

        $selected_players = $phase_finale_player[$day][$phase];

        $i                   = 0;
        $idx                 = 0;
        $idx_barrage_day     = array(0, 0, 1, 2, 2, 1); # button to display when display=c_top7_player
        $idx_demifinales_day = array(1, 2, 2, 1); # button to display when display=c_top7_player
        $idx_finale_day      = array(1, 2); # button to display when display=c_top7_player
        if (count($players)) {
            foreach ($ranks as $rank) {
                $player = $rank['player'];
                if ($player == '') continue;
                if ($players[$player]['registered'] == $players[$player]['played']) {
                    $prono = c_played;
                } else {
                    $prono = c_not_played;
                }

                if (isset($selected_players[$i]) and $selected_players[$i]) {
                    if ($day == c_barrage_day) {
                        $idx = $idx_barrage_day[$i];
                    }

                    if ($day == c_demifinales_day) {
                        $idx = $idx_demifinales_day[$i];
                    }

                    if ($day == c_finale_day) {
                        $idx = $idx_finale_day[$i];
                    }

                    $status   = $selected_players[$i];
                    $deadline = 0;
                    if ($phase == 0 and $status == c_cannot_play) {
                        $deadline = $deadline1;
                    }

                    #if( $phase == 1 and $status == c_cannot_play) $prono = c_played;
                    if ($now > $deadline2) {
                        $prono = c_played;
                    }

                    $info         = "(à partir de " . utf8_encode(strftime("%A %d %b ", $deadline)) . $midi_minuit[0] . ")";
                    //$selections[] = $players[$player]
                    // + array("deadline" => $deadline, "prono" => $prono, "status" => $status, "info" => $info, 'idx' => $idx);
                    $selections[] = array_merge(
                        $players[$player],
                        array("deadline" => $deadline, "prono" => $prono, "status" => $status, "info" => $info, 'idx' => $idx)
                    );
                }
                $i++;
            }
        }
    }

    printr_log(__FUNCTION__, "selections", $selections);
    return $selections;
}

function init_time_session()
{

    date_default_timezone_set('Europe/Paris');

    $top7_season = get_top7_season();
    print_log(__FUNCTION__, "top7_season", $top7_season);

    if (isset($_SESSION['season'])) {
        $season = $_SESSION['season'];
    } else {
        $season             = $top7_season['Id'];
        $_SESSION['season'] = $season;
    }
    $season_start       = strtotime($top7_season['start']);


    print_log(__FUNCTION__, "season", $season);

    $now = now();

    $day = get_last_day_from_date($now, $season);
    #    $day=13;
    
    $today              = get_day_from_date($now);
    $monday             = get_monday_from_day($day, $today, $season);
    $time_game_closed   = $monday + c_time_game_closed - 10;
    $time_game_closed   = get_time_game_closed($day, $today, $season, $monday); // ticket 1+22
    $time_season_closed = get_last_day_season($season);
    $time_season_opened = get_first_day_season($season);
    
    print_log(__FUNCTION__, "now", $now);
    print_log(__FUNCTION__, "season", $season);
    print_log(__FUNCTION__, "time_season_opened", $time_season_opened);
    if ($now < $time_season_opened) $day = 0;

    if ($now < $season_start) $_SESSION['last_season'] = $season;
    else $_SESSION['last_season'] = $season;  # TODO to fix later 

    if ($day > c_last_day) {
        $deadline1 = $monday + 3 * 24 * 3600 - 60;
        $deadline2 = $time_game_closed - 60;
        $phase     = 0;
        if ($now > $deadline1) {
            $phase = 1;
        }

        $_SESSION['phase']     = $phase;
        $_SESSION['deadline1'] = $deadline1;
        $_SESSION['deadline2'] = $deadline2;
    }
    $_SESSION['top7_season']        = $top7_season['Id'];
    $_SESSION['day']                = $day;
    $_SESSION['today']              = $today;
    $_SESSION['monday']             = $monday;
    $_SESSION['time_game_closed']   = $time_game_closed;
    $_SESSION['time_season_closed'] = $time_season_closed;
    $_SESSION['time_season_opened'] = $time_season_opened;
    $_SESSION['close_forum']        = strtotime($top7_season['close_forum']);
}

function check_date_player($p)
{

    $day = $p['day'];
    print_log(__FUNCTION__, "day", $day);
    if ($day <= c_last_day) {
        $game = check_player_phase_reguliere($p);
    }

    if ($day > c_last_day) {
        $game = check_player_phase_finale($p);
    }

    print_log(__FUNCTION__, "game", $game);
    return $game;
}

function check_player_phase_finale($p)
{

    global $opponent_player;

    $player             = $p['player'];
    $team               = $p['top7team'];
    $day                = $p['day'];
    $today              = $p['today'];
    $monday             = $p['monday'];
    $time_game_closed   = $p['time_game_closed'];
    $time_season_closed = $p['time_season_closed'];
    $phase              = $p['phase'];
    $deadline1          = $p['deadline1'];
    $deadline2          = $p['deadline2'];
    printr_log(__FUNCTION__, "p", $p);

    $selections = get_top7_day_selection($today, $p);
    printr_log(__FUNCTION__, "selections", $selections);

    $i          = 0;
    $current    = 0;
    $status     = c_no_more_selected;
    $prono      = 0;
    $deadline   = 0;
    $idx        = 0;
    $player_idx = 0;
    $players    = array();
    foreach ($selections as $selection) {
        $players[] = $selection['registered'];
        if ($selection['status'] == c_can_play or $selection['status'] == c_cannot_play) {
            $idx++;
        }

        if ($selection['registered'] == $player) {
            $current    = $i;
            $deadline   = $selection['deadline'];
            $status     = $selection['status'];
            $prono      = $selection['prono'];
            $player_idx = $selection['idx'];
        }
        $i++;
    }

    $_SESSION['deadline']            = $deadline;
    $_SESSION['status']              = $status;
    $_SESSION['player_idx']          = $player_idx;
    $_SESSION['next_player_to_play'] = 0;

    if ($idx) {
        $_SESSION['player1'] = $players[$current];
        $_SESSION['player2'] = $players[$opponent_player[$day][$current]];
    }
    printr_log(__FUNCTION__, "players", $players);

    $now = now();

    if ($now > $time_game_closed) {
        $res = c_disable;
    } elseif ($now < $monday) {
        $res = c_not_opened;
    } else {
        $res = c_disable;
        #$res = c_enable;
        if ($status == c_can_play) {
            $res = c_enable;
        }

        if ($status == c_can_play and $prono == c_played) {
            $res = c_validated;
        }

        if ($prono == c_played) {
            $res = c_validated;
        }

        if ($status == c_not_selected) {
            $res = c_enable;
        }

        if ($status == c_no_more_selected) {
            $res = c_game_over;
        }

        if ($status == c_cannot_play and $prono == c_not_played) {
            $res = c_enable;
        }
    }
    if ($now > $time_season_closed) {
        $res = c_season_over;
    }

    return $res;
}

function check_player_phase_reguliere($p)
{

    $player           = $p['player'];
    $team             = $p['top7team'];
    $day              = $p['day'];
    $today            = $p['today'];
    $monday           = $p['monday'];
    $time_game_closed = $p['time_game_closed'];

    $selections = get_top7_day_selection($today, $p);

    $i        = 0;
    $current  = $next  = $next_to_play  = $last  = 0;
    $deadline = 0;
    foreach ($selections as $selection) {
        if ($selection['registered'] == $player) {
            $current  = $i;
            $next     = $i + 1;
            $previous = $i - 1;
            $deadline = $selection['deadline'];
        }
        $i++;
        if ($selection['prono'] == c_not_played and $next_to_play == 0) {
            $next_to_play = $i;
        }
    }
    $next_to_play -= 1;
    $last = $i - 1;
    if ($next > $last) {
        $next = $last;
    }

    if ($previous < 0) {
        $previous = 0;
    }

    if ($current == $last) {
        $next_player = 0;
    } else {
        $next_player = $selections[$next]['registered'];
    }

    if ($previous) {
        $previous_player = $selections[$previous]['registered'];
    } else {
        $previous_player = 0;
    }

    $next_player_to_play = $selections[$next_to_play]['registered'];

    $_SESSION['next_player_to_play'] = $next_player_to_play;
    $_SESSION['deadline']            = $deadline;
    $_SESSION['next_player']         = $next_player;

    $prono = $selections[$current]['prono'];
    if ($current <= $next_to_play) {
        $prev_prono = c_played;
    } else {
        $prev_prono = c_not_played;
    }

    $now = now();

    if ($now > $time_game_closed) {
        $res = c_disable;
    } elseif ($now < $monday) {
        $res = c_not_opened;
    } else {
        if ($now > $deadline) {
            if ($prono == c_played) {
                $res = c_validated;
            }

            if ($prono == c_not_played) {
                $res = c_enable;
            }
        } else {
            if ($prono == c_played) {
                $res = c_validated;
            }

            if (
                $prono == c_not_played and
                $prev_prono == c_played
            ) {
                $res = c_enable;
            }

            if (
                $prono == c_not_played and
                $prev_prono == c_not_played
            ) {
                $res = c_disable;
            }
        }
    }
    $status = c_cannot_play;
    if ($res == c_enable) {
        $status = c_can_play;
    }

    $_SESSION['status'] = $status;

    $time_season_opened = $_SESSION['time_season_opened'];
    if ($now < $time_season_opened) {
        $res = c_not_opened;
    }

    return $res;
}

function check_player($p)
{

    printr_log(__FUNCTION__, "login", $p['login']);
    init_sql();

    global $pdo;
    $query = "select player_idx as player, season, pseudo, team, email, password, captain from player ";
    $query .= "where email=?  order by player_idx desc limit 1";
    $row = pdo_fetch_param(__FUNCTION__, c_one, $query, array($p['login']));

    if (isset($row['password']) and $row['password'] == md5($p['password'])) {
        $player = $row;
    } else {
        $player = false;
    }


    printr_log(__FUNCTION__, "password", $p['password']);
    printr_log(__FUNCTION__, "md5.password", md5($p['password']));
    printr_log(__FUNCTION__, "player", $player);

    return $player;
}

function get_button($name, $team, $action, $p, $nb_teams)
{

    $button = "<form id=\"$name\" name=\"$name\" method=\"post\" action=\"$action\">\n";
    foreach ($p as $name => $value) {
        $button .= "<input type=\"hidden\" name=\"$name\" value=\"$value\">\n";
    }
    $id    = "TeamButton";
    $title = "title=\"jamais jouée !\"";
    if ($nb_teams) {
        $id    = "TeamButton1";
        $title = "title=\"déjà jouée $nb_teams fois\"";
    }
    $button .= "<input type=\"submit\" id=\"$id\" name=\"button\" value=\"$team\" $title>\n";
    $button .= "</form>\n";

    return $button;
}

function put_abbr($title, $tooltip)
{

    echo "<abbr title=\"$tooltip\">$title</abbr>";
}

function get_palmares_player($email)
{
    global $title_phase_finale;

    $query    = "select * from `player` join `season` on player.season=season.Id where email=\"$email\" order by season asc";
    $rows     = pdo_fetch(__FUNCTION__, c_all, $query);
    $palmares = array();
    foreach ($rows as $row) {
        $palmares[] = array(
            "title"      => $row['title'],
            "rank"       => $title_phase_finale[$row['rankFinal'] - 1],
            "player_idx" => $row['player_idx'],
            "season"     => $row['season'],
        );
    }
    return $palmares;
}

function get_info_player($player)
{

    $query = "select * from `player` where player_idx=\"$player\"";
    return pdo_fetch(__FUNCTION__, c_one, $query);
}

function get_last_password_email($player)
{

    $query = "select * from `password` where player=\"$player\" order by time desc limit 1";
    return pdo_fetch(__FUNCTION__, c_one, $query);
}

function get_info_team($team)
{

    $query = "select * from `team_player` where team_idx=\"$team\"";
    return pdo_fetch(__FUNCTION__, c_one, $query);
}

function get_info_team_date_reg($team)
{

    $query = "select date_reg from `player` where team=\"$team\" order by date_reg desc";
    return pdo_fetch(__FUNCTION__, c_one, $query);
}

function get_email_team($team)
{

    $query = "select email, pseudo from `player` where team=\"$team\"";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_player_from_email($email)
{

    $query = "select player_idx, email from player where email=? order by player_idx desc";
    $row   = pdo_fetch_param(__FUNCTION__, c_one, $query, array($email));
    if (count($row) == 2) {
        return $row['player_idx'];
    } else {
        return false;
    }
}

function init_password_pending($player)
{

    $query = "select player, status, time from password where player=? order by time desc";
    $row   = pdo_fetch_param(__FUNCTION__, c_one, $query, array($player));
    printr_log(__FUNCTION__, "row", $row);

    if (count($row) == 1) {
        // not registered
        $key = insert_password_player($player);
        send_email_password($player, $key);
        return false;
    }

    if (now() - $row['time'] > c_delay_reset_password) {
        // already registered
        $key = insert_password_player($player);
        send_email_password($player, $key);
        return false;
    }
    return true;
}

function insert_password_player($player)
{

    $key    = random_generator(10);
    $key    = md5($key);
    $time   = now();
    $status = c_password_pending;
    $query  = "insert into `password` ( `player`, `time`, `keyword`, `status`) value ( '$player', '$time', '$key', '$status')";
    pdo_exec(__FUNCTION__, $query);
    return $key;
}

function delete_password_player($player)
{

    $query = "delete from `password` where `player`='$player'";
    pdo_exec(__FUNCTION__, $query);
}

function key_is_valid($key)
{

    print_log(__FUNCTION__, "key", $key);
    $query = "select * from password where keyword=?";
    $row   = pdo_fetch_param(__FUNCTION__, c_one, $query, array($key));
    printr_log(__FUNCTION__, "row", $row);

    if (count($row) == 1) {
        return false;
    }

    if ((now() - $row['time']) > c_delay_reset_password) {
        return false;
    }

    return $row['player'];
}

function send_email_register($pseudo, $email, $team, $captain, $key)
{

    $info_team = get_info_team($team);
    $team_name = $info_team['name'];

    $top7_season = get_top7_season();
    $saison      = $top7_season['title'];

    $e            = array();
    $e['subject'] = c_email_subject_register;
    $e['dest']    = $email;
    $capitaine    = "";
    if ($captain) {
        $capitaine = "Capitaine";
    }

    $e['msg'] = "<h3>Bienvenue $capitaine $pseudo dans le Top7</h3><br>";

    $url = c_url_top7 . "new_password?key=$key";
    $e['msg'] .= "$capitaine $pseudo, tu fais partie de l'équipe <b>$team_name</b> pour la nouvelle " . $saison . ".<br>";

    $e['msg'] .= "<br><b>Attention</b>, pour pouvoir jouer il faut que tous les joueurs de l'équipe aient validé leur inscription.<br>";

    if ($captain) {
        $e['msg'] .= "N'hésite pas à relancer tous les joueurs de ton équipe.<br>";
        $e['msg'] .= "Si besoin, tu peux modifier une adresse mail d'un joueur qui n'a pas encore validé son inscription. En cliquant sur le lien de ton <b>équipe</b> puis sur le joueur concerné.";
    } else {
        $e['msg'] .= "N'hésite pas à contacter le capitaine de ton équipe.";
    }

    $e['msg'] .= "<br>Pour valider l'inscription et créer ton mot de passe, clique sur ce lien $url <br>";
    $t = c_delay_reset_password / 24 / 3600;
    $e['msg'] .= "Attention ce lien n'est valide que pendant $t jours.<br>";

    if ($captain) {
        $e['msg'] .= "Une fois l'équipe validée et prête à jouer, le capitaine peut se connecter et jouer en place de n'importe quel joueur en cliquant sur le nom du joueur dans le lien <b>équipe</b>.<br>";
    }

    $e['msg'] .= "<br>";
    $e['msg'] .= "<h3>Les règles du jeu</h3>";

    $e['msg'] .= file_get_contents(c_rules_file);
    send_email($e);
}

function send_email_password($id, $key)
{

    $url    = c_url_top7 . "new_password?key=$key";
    $player = get_info_player($id);
    $pseudo = $player['pseudo'];

    $msg = "<h3>Salut $pseudo</h3><br>";
    $msg .= "Pour réinitialiser le mot de passe, clique sur ce lien $url <br>";
    $t = c_delay_reset_password / 24 / 3600;
    $msg .= "Attention ce lien n'est valide que pendant $t jours.<br>";
    $e            = array();
    $e['dest']    = $player['email'];
    $e['msg']     = $msg;
    $e['subject'] = c_email_subject_reinit_password;
    send_email($e);
}

function send_email_alert_player($p)
{
    $f = "send_email_alert_player";

    $player1 = $p['player1'];
    $player2 = $p['player2'];

    $day         = $p['day'];
    $player_info = get_player($player2);
    $pseudo2     = $player_info['pseudo'];
    $email       = $player_info['email'];

    $player_info = get_player($player1);
    $pseudo1     = $player_info['pseudo'];

    $msg = "<h3>Salut $pseudo2</h3><br>";
    $msg .= "$pseudo1 vient de jouer pour toi ! <br>";
    $msg .= "Clique sur le lien <a href=\"" . c_url_top7 . "\">www.topseven.fr</a><br>";
    $e            = array();
    $e['dest']    = $email;
    $e['msg']     = $msg;
    $e['subject'] = get_day_title($day);
    send_email($e);
}

function send_email_game_is_opened($p, $player)
{

    $day         = $p['day'];
    $player_info = get_player($player);
    $pseudo      = $player_info['pseudo'];
    $email       = $player_info['email'];

    $msg = "<h3>Salut $pseudo</h3><br>";

    $msg .= get_selection_order($p);

    $e            = array();
    $e['dest']    = $email;
    $e['msg']     = $msg;
    $e['subject'] = get_day_title($day);
    send_email($e);
}

function send_email_game_is_closed($p)
{

    $day      = $p['day'];
    $top7team = $p['top7team'];

    $msg1 = get_prono_player($p);

    $title  = get_day_title($day);
    $emails = get_email_team($top7team);

    foreach ($emails as $email) {
        $pseudo = $email['pseudo'];

        $msg = "<h3>Salut $pseudo</h3><br>";
        $msg .= $msg1;

        $e            = array();
        $e['dest']    = $email['email'];
        $e['msg']     = $msg;
        $e['subject'] = $title;
        send_email($e);
    }
}

function send_email_next_player($p, $player)
{

    $day         = $p['day'];
    $player_info = get_player($player);
    $pseudo      = $player_info['pseudo'];
    $email       = $player_info['email'];

    $msg = "<h3>Salut $pseudo</h3><br>";
    $msg .= "C'est à ton tour de jouer ! <br>";
    $msg .= "Clique sur le lien <a href=\"" . c_url_top7 . "\">www.topseven.fr</a><br>";
    $e            = array();
    $e['dest']    = $email;
    $e['msg']     = $msg;
    $e['subject'] = get_day_title($day);
    send_email($e);
}

function send_email_forum($p, $s)
{
    $f = "send_email_forum";

    $team    = $s['top7team'];
    $player  = $s['player'];
    $day     = $s['day'];
    $format  = "%Y-%m-%d %H:%M";
    $date    = strftime($format, now());
    $parent  = $p['parent'];
    $comment = $p['comment'];
    $author  = get_pseudo_from_player($player);

    $top7team = $s['top7team'];
    $title    = get_day_title($day);
    $emails   = get_email_team($team);

    $style = "font-family: Verdana, sans-serif; font-size: small; border-collapse: collapse; background-color: #FAFAE0; width: 90%;";
    $msg1  = "<table style=\"$style\">\n";

    $style = "background-color: #FAFAE0; color: green; text-align: center;";
    $msg1 .= "<tr><th style=\"$style\">Nouveau commentaire de $author sur le forum $title.</th></tr>";

    $style = "background-color: #FAFAFA; color: black; text-align: left; padding-left: 10px; white-space: pre;";

    $msg1 .= "<tr><td style=\"$style\">$comment</td></tr>";
    $msg1 .= "</table>";

    foreach ($emails as $email) {
        $pseudo = $email['pseudo'];
        $msg    = "<h3>Salut $pseudo</h3><br>";
        $msg .= $msg1;
        $e            = array();
        $e['dest']    = $email['email'];
        $e['msg']     = $msg;
        $e['subject'] = "Nouveau commentaire de $author";
        if ($author != $pseudo) {
            send_email($e);
        }
    }
}

function check_new_team($name)
{

    $top7_season = get_top7_season();
    $season      = $top7_season['Id'];
    $query       = "select name from `team_player` where name=\"$name\" and season=$season";
    $row         = pdo_fetch(__FUNCTION__, c_one, $query);
    if (count($row) == 1) {
        return false;
    } else {
        return true;
    }
}

function check_new_pseudo($pseudo)
{

    $top7_season = get_top7_season();
    $season      = $top7_season['Id'];
    $query       = "select pseudo from `player` where pseudo=\"$pseudo\" and season=$season";
    $row         = pdo_fetch(__FUNCTION__, c_one, $query);
    if (count($row) == 1) {
        return false;
    } else {
        return true;
    }
}

function check_syntax_email($email)
{
    return filter_var($email, FILTER_VALIDATE_EMAIL);
}

function check_same_inputs($inputs)
{
    $sames = array();
    $i     = 0;
    foreach ($inputs as $ref) {
        $j = 0;
        foreach ($inputs as $input) {
            if ($i != $j and $ref == $input) {
                $sames[] = $j;
            }

            $j++;
        }
        $i++;
    }
    return $sames;
}

function check_new_email($email)
{

    $top7_season = get_top7_season();
    $season      = $top7_season['Id'];
    $query       = "select email from `player` where season=$season and email=\"$email\"";
    $row         = pdo_fetch(__FUNCTION__, c_one, $query);
    if (count($row) == 1) {
        return false;
    } else {
        return true;
    }
}

function random_generator($digits)
{

    srand((float) microtime() * 10000000);
    $input = array("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z");

    $random_generator = "";
    for ($i = 1; $i < $digits + 1; $i++) {
        if (rand(1, 2) == 1) {
            $rand_index = array_rand($input);
            $random_generator .= $input[$rand_index];
        } else {
            $random_generator .= rand(1, 10);
        }
    }

    return $random_generator;
}

function update_name_team($name, $team)
{
    $query = "update `team_player` set `name`='$name' where `team_idx`='$team'";
    pdo_exec(__FUNCTION__, $query);
}

function update_email_player($email, $player)
{
    $status = c_player_waiting;
    $query  = "update `player` set `email`='$email', `status`='$status' where `player_idx`='$player'";
    pdo_exec(__FUNCTION__, $query);
}

function update_pseudo_player($pseudo, $player)
{
    $query = "update `player` set `pseudo`='$pseudo' where `player_idx`='$player'";
    pdo_exec(__FUNCTION__, $query);
}

function check_last_registered_player($player)
{

    $info = get_info_player($player);
    $team = $info['team'];

    $query = "select status from `player` where team=$team";
    $rows  = pdo_fetch(__FUNCTION__, c_all, $query);
    $n     = $m     = 0;
    foreach ($rows as $row) {
        if ($row['status'] == c_player_enable) {
            $n++;
        }

        $m++;
    }

    if ($n == $m) {
        $status = true;
    } else {
        $status = false;
    }

    $new_team_validated = false;
    if ($status) {
        $query = "select status from `team_player` where team_idx=$team";
        $row   = pdo_fetch(__FUNCTION__, c_one, $query);

        if ($row['status'] == c_team_waiting) {
            $status = c_team_enable;
            $query  = "update `team_player` set `status`='$status' where `team_idx`='$team'";
            pdo_exec(__FUNCTION__, $query);
            $new_team_validated = true;
        }
    }

    if ($new_team_validated) {
        $info_team    = get_info_team($team);
        $e            = array();
        $e['subject'] = c_email_subject_init_team . " " . $info_team['name'];
        $emails       = get_email_team($team);
        foreach ($emails as $email) {

            $e['dest'] = $email['email'];
            $e['msg']  = "<h3>Bienvenue " . $email['pseudo'] . " dans le Top7</h3><br>";
            $e['msg'] .= "Ton équipe <b>" . $info_team['name'] . "</b> est désormais au complet !<br>";
            $e['msg'] .= "Tu peux dès maintenant commencer à jouer.<br>";
            send_email($e);
        }
    }
}

function update_register($pseudo, $email, $password)
{

    $top7_season = get_top7_season();
    $season      = $top7_season['Id'];
    $query       = "select player_idx, status, date_reg from player where pseudo=? and email=? and season=?";
    $row         = pdo_fetch_param(__FUNCTION__, c_one, $query, array($pseudo, $email, $season));

    $password = md5($password);
    $date_reg = $row['date_reg'];
    $status   = $row['status'];
    $player   = $row['player_idx'];

    if ($status == c_player_waiting) {
        $status   = c_player_enable;
        $format   = "%Y-%m-%d %H:%M";
        $date_reg = strftime($format, now());
    }

    printr_log(__FUNCTION__, "data", array($password, $status, $date_reg, $pseudo, $email));
    $query = "update player set password=?, status=?, date_reg=? where pseudo=? and email=?";
    $row   = pdo_fetch_param(__FUNCTION__, c_none, $query, array($password, $status, $date_reg, $pseudo, $email));

    return $player;
}

function insert_new_player($pseudo, $email, $team, $captain)
{

    $password = md5("top7top7");
    $pseudo   = $pseudo;
    $email    = $email;
    $team     = $team;

    $top7_season = get_top7_season();
    $season      = $top7_season['Id'];

    $status   = c_player_waiting;
    $format   = "%Y-%m-%d %H:%M";
    $date_reg = strftime($format, now());
    $query  = "insert into player (season, pseudo, password, email, status, team, captain, date_reg) ";
    $query .= "value (:season, :pseudo, :password, :email, :status, :team,  :captain, :date_reg)";
    $data = array(
        "season"    => $season,
        "pseudo"    => $pseudo,
        "password"  => $password,
        "email"     => $email,
        "status"    => $status,
        "team"      => $team,
        "captain"   => $captain,
        "date_reg"  => $date_reg
    );
    return pdo_insert(__FUNCTION__, $query, $data);
}

function insert_same_player($pseudo, $password, $email, $team, $captain)
{

    $top7_season = get_top7_season();
    $season      = $top7_season['Id'];

    $status   = c_player_enable;
    $format   = "%Y-%m-%d %H:%M:%S";
    $date_reg = strftime($format, now());
    $query  = "insert into player (season, pseudo, password, email, status, team, captain, date_reg) ";
    $query .= "value (:season, :pseudo, :password, :email, :status, :team,  :captain, :date_reg)";
    $data = array(
        "season"    => $season,
        "pseudo"    => $pseudo,
        "password"  => $password,
        "email"     => $email,
        "status"    => $status,
        "team"      => $team,
        "captain"   => $captain,
        "date_reg"  => $date_reg
    );
    return pdo_insert(__FUNCTION__, $query, $data);
}

function put_line_button($element)
{

    $action = "player";

    $info   = $element['info'];
    $player = $element['player'];

    $title   = $element['title'];
    $info    = $element['info'];
    $comment = "";
    if (isset($element['comment'])) {
        $comment = $element['comment'];
    }

    echo "<tr class=\"player\">\n";
    echo "<td class=\"player_title\">$title</td><td class=\"player_sep\">:</td>\n";
    echo "<td class=\"player_info\" colspan=\"2\">\n";
    echo "<form action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"PlayerButton\" name=\"button\" value=\"$info\">\n";
    echo "<input type=\"hidden\" name=\"player\" value=\"$player\">\n";
    if (isset($element['season'])) {
        $season = $element['season'];
        echo "<input type=\"hidden\" name=\"season\" value=\"$season\">\n";
    }
    if (isset($element['status'])) {
        $status  = $element['status'];
        $player  = $element['player'];
        $pseudo  = $element['pseudo'];
        $email   = $element['email'];
        $team    = $element['team'];
        $captain = $element['captain'];
        echo "<input type=\"hidden\" name=\"status\" value=\"$status\">\n";
        echo "<input type=\"hidden\" name=\"_player\" value=\"$player\">\n";
        echo "<input type=\"hidden\" name=\"_pseudo\" value=\"$pseudo\">\n";
        echo "<input type=\"hidden\" name=\"_email\" value=\"$email\">\n";
        echo "<input type=\"hidden\" name=\"team\" value=\"$team\">\n";
        echo "<input type=\"hidden\" name=\"captain\" value=\"$captain\">\n";
    }
    echo "</form>\n";
    echo "<div class=\"comment\">$comment</div>\n";
    echo "</td>\n";
    echo "</tr>";
}

function put_line_edit($id, $element)
{

    $title   = $element['title'];
    $info    = $element['info'];
    $comment = $element['comment'];
    $name    = $element['name'];
    $player  = $element['player'];
    $action  = $_SERVER['PHP_SELF'];
    $div     = $element['div'];

    $action = substr($action, 0, strrpos($action, "."));

    #echo "<div>\n";
    echo "<tr class=\"player\">\n";
    echo "<td class=\"player_title\">$title</td><td class=\"player_sep\">:</td>\n";
    echo "<td class=\"player_edit\">";
    echo "<form action=\"$action\" id=\"formedit$id\" method=\"post\">\n";
    echo "<input class=\"edit\" type=\"text\" name=\"$name\" value=\"$info\" readonly=\"true\" ondblclick=\"this.readOnly='';\" onblur=\"this.readOnly='true';document.getElementById('formedit$id').submit();\"/>\n";
    echo "<input type=\"hidden\" name=\"player\" value=\"$player\">\n";
    echo "</form>\n";
    echo "</div>\n";
    echo "</td>\n";
    echo "<td>\n";
    echo "<div class=\"comment\">$comment</div>\n";
    echo "</td>\n";
    echo "</tr>\n";
}

function put_line_info($element)
{
    $title = $element['title'];
    $info  = $element['info'];
    echo "<tr class=\"player\">\n";
    echo "<td class=\"player_title\">$title</td><td class=\"player_sep\">:</td>\n";
    echo "<td class=\"player_info\" colspan=\"2\">$info</td></tr>\n";
}

function display_info_team($p)
{

    global $strDate;
    global $player_status;
    global $team_status;

    $player = "?";
    if (isset($p['player'])) {
        $player = $p['player'];
    }

    $top7team = 0;
    if (isset($p['top7team'])) {
        $top7team = $p['top7team'];
    }

    $captain = 0;
    if (isset($p['captain'])) {
        $captain = $p['captain'];
    }

    $game = $p['game'];

    $info_team   = get_info_team($top7team);
    $team_name   = $info_team['name'];
    $status      = $team_status[$info_team['status']];
    $top7_season = get_top7_season_by_id($info_team['season']);
    $season      = explode(" ", $top7_season['title']);

    $players       = get_top7team_players($top7team);
    $date_last_reg = get_info_team_date_reg($top7team);
    #$date_reg = utf8_encode( strftime( $strDate, strtotime( $players[0]['date_reg'])));  // date_reg captain
    $date_reg = utf8_encode(strftime($strDate, strtotime($date_last_reg['date_reg']))); // last date_reg  = tema registering

    $line = c_line_info;
    $div  = "";
    if ($captain) {
        $line = c_line_edit;
        $div  = "edit1";
    }

    if ($game == c_season_over) {
        $line = c_line_info;
    }

    $infos = array(
        array("line" => $line, "div" => $div, "name" => "team", "title" => "Equipe", "info" => $team_name, "player" => 0, "comment" => ""),
        array("line" => c_line_info, "title" => "Status", "info" => $status),
        array("line" => c_line_info, "title" => "Inscrite depuis", "info" => $date_reg),
        array("line" => c_line_info, "title" => $season[0], "info" => $season[1]),
    );
    $i      = 0;
    $j      = 0;
    $action = "player";
    foreach ($players as $k => $player) {
        $j++;
        $line = c_line_info;
        if ($captain) {
            $line = c_line_button;
        }

        if ($game == c_season_over) {
            $line = c_line_info;
        }

        $status = "[" . $player_status[$player['status']] . "]";
        if ($player['status'] == c_player_enable) {
            $status = "";
        }

        if ($player['status'] == c_player_waiting) {
            $password = get_last_password_email($player['player_idx']);
            $delay    = get_forum_delay(now() - $password['time']);
            $status   = "[" . $player_status[$player['status']] . ", depuis $delay]";
        }
        if ($i) {
            $title = "Joueur ($j) $status";
        } else {
            $title = "Capitaine ($j) $status";
        }

        $infos[] = array("line" => $line, "title" => $title, "info" => $player['pseudo'], "player" => $player['player_idx']);
        $i++;
    }

    print_table_info("Equipe Top7", $infos);
}

function send_email($p)
{

    global $debug_email;

    setlocale(LC_TIME, "fr_FR");

    $email_admin = c_email_admin;
    $headers     = "From: $email_admin" . "\r\n";
    $headers .= "Reply-To: $email_admin" . "\r\n";
    $headers .= "MIME-Version: 1.0" . "\r\n";
    $headers .= 'Content-Type: text/html; charset="utf-8"' . "\r\n";
    $headers .= 'Content-Transfer-Encoding: 8bit' . "\r\n";

    $dest    = $p['dest'];
    $subject = "Top7 : " . $p['subject'];

    $msg = "<html><head><title>Top7</title></head><body>";
    $msg .= $p['msg'];
    $msg .= "<br>_________________________________________<br>";
    $msg .= "<a href=\"" . c_url_top7 . "\">www.topseven.fr</a><br>";
    #$msg .= "<br>".strftime(" %d/%m/%Y %H:%M")."</pre>";
    $msg .= "</body></html>";

    #$subject = utf8_encode( $subject);
    #$msg = utf8_encode( $msg);

    if (!$debug_email) {
        mail($dest, $subject, $msg, $headers);
    }

    mail(c_email_pyl, $subject, $msg, $headers);
    #mail( "pylscblt@gmail.com", $subject, $msg, $headers);
    #echo $msg;
}

function get_exec_time()
{
    $time = explode(' ', microtime());
    return ($time[1] + $time[0]);
}

function print_exec_time($startexectime, $endexectime)
{
    #$endexectime = get_exec_time();
    $totaltime = round($endexectime - $startexectime, 4);
    echo "page generated in $totaltime seconds.";
}

function print_info_register($p)
{

    $pseudo = "?";
    if (isset($p['pseudo'])) {
        $pseudo = $p['pseudo'];
    }

    $team = "?";
    if (isset($p['team'])) {
        $team = $p['team'];
    }

    #echo "<div class=\"registerbox\">\n";
    echo "<div class=\"registerbox2\">\n";

    echo "<img src=" . c_logo_file . ">\n";

    echo "<table class=\"login\" border=0>\n";

    echo "<tr>\n";
    echo "<td>Bravo capitaine <b>$pseudo</b> !<br>Tu es à la tête de l'équipe <b>$team</b>. Surveille ton email et n'oublie pas de motiver ton équipe.</td>\n";
    echo "</tr>\n";

    $action = "./";
    echo "<tr>\n";
    echo "<form id=\"CancelForm\" action=\"$action\" method=\"post\">\n";
    echo "<td align=\"center\">";
    echo "<input type=\"submit\" id=\"CancelButton\" name=\"button\" value=\"Retour\">";
    echo "</td>\n";
    echo "</tr>\n";

    echo "</table>\n";

    echo "</div>\n";
    #echo "</div>\n";

}

function put_form_nav_records($title, $display, $selected)
{

    $action   = "records";
    $idbutton = "RecordsButton";

    echo "<form id=\"form_stats\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"$idbutton\" $selected value=\"$title\">\n";
    echo "<input type=\"hidden\" name=\"display_stats\" value=\"$display\">\n";
    echo "</form>\n";
}

function put_form_nav_stats($title, $display, $selected)
{

    $action   = "stats";
    $idbutton = "StatsButton";

    echo "<form id=\"form_stats\" action=\"$action\" method=\"post\">\n";
    echo "<input type=\"submit\" id=\"$idbutton\" $selected value=\"$title\">\n";
    echo "<input type=\"hidden\" name=\"display_stats\" value=\"$display\">\n";
    echo "</form>\n";
}

function put_nav_records($p)
{

    $to_display = 0;
    if (isset($p['display_stats'])) {
        $to_display = $p['display_stats'];
    }

    $class = "nav_stats";
    echo "<table class=\"$class\" border=0>\n";
    echo "<tr>\n";

    echo "<td class=\"$class\">";
    $title    = "Par équipe";
    $display  = c_stats_by_team;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }
    put_form_nav_records($title, $display, $selected);
    echo "</td>\n";

    echo "<td class=\"$class\">";
    $title    = "Par joueur";
    $display  = c_stats_by_player;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }
    put_form_nav_records($title, $display, $selected);
    echo "</td>\n";

    echo "<td class=\"$class\">";
    $title    = "Fun";
    $display  = c_stats_fun;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }
    put_form_nav_records($title, $display, $selected);
    echo "</td>\n";

    echo "<td class=\"$class\">";
    $title    = "Extérieur";
    $display  = c_stats_exterieur;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }
    put_form_nav_records($title, $display, $selected);
    echo "</td>\n";

    echo "<td class=\"$class\">";
    $title    = "Coiffeur";
    $display  = c_stats_coiffeur;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }
    put_form_nav_records($title, $display, $selected);
    echo "</td>\n";

    echo "<td class=\"$class\">";
    $title    = "BOff !";
    $display  = c_stats_BOff;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }
    put_form_nav_records($title, $display, $selected);
    echo "</td>\n";

    echo "<td class=\"$class\">";
    $title    = "14 !";
    $display  = c_stats_14;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }
    put_form_nav_records($title, $display, $selected);
    echo "</td>\n";

    echo "</tr>\n";
    echo "</table>\n";
}

function put_nav_stats($p)
{

    $to_display = 0;
    if (isset($p['display_stats'])) {
        $to_display = $p['display_stats'];
    }

    $class = "nav_stats";
    echo "<table class=\"$class\" border=0>\n";
    echo "<tr>\n";

    echo "<td class=\"$class\">";

    $title    = "Par équipe";
    $display  = c_stats_by_team;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    put_form_nav_stats($title, $display, $selected);

    echo "</td>\n";

    echo "<td class=\"$class\">";

    $title    = "Par joueur";
    $display  = c_stats_by_player;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    put_form_nav_stats($title, $display, $selected);

    echo "</td>\n";

    echo "<td class=\"$class\">";

    $title    = "Moyenne";
    $display  = c_stats_average;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    put_form_nav_stats($title, $display, $selected);

    echo "</td>\n";

    echo "<td class=\"$class\">";

    $title    = "Fun";
    $display  = c_stats_fun;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    put_form_nav_stats($title, $display, $selected);

    echo "</td>\n";

    echo "<td class=\"$class\">";

    $title    = "Extérieur";
    $display  = c_stats_exterieur;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    put_form_nav_stats($title, $display, $selected);

    echo "</td>\n";

    echo "<td class=\"$class\">";

    $title    = "Coiffeur";
    $display  = c_stats_coiffeur;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    put_form_nav_stats($title, $display, $selected);

    echo "</td>\n";

    echo "<td class=\"$class\">";

    $title    = "BOff !";
    $display  = c_stats_BOff;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    put_form_nav_stats($title, $display, $selected);

    echo "</td>\n";

    echo "<td class=\"$class\">";

    $title    = "14 !";
    $display  = c_stats_14;
    $selected = "";
    if ($to_display == $display) {
        $selected = "class=\"selected\"";
    }

    put_form_nav_stats($title, $display, $selected);

    echo "</td>\n";

    echo "</tr>\n";
    echo "</table>\n";
}

function records($p)
{

    $display = $p['display_stats'];

    $season  = 0;
    if (isset($p['season'])) {
        $season = $p['season'];
    }

    $title = "RECORDS";
    echo "<table class=\"player\">\n";
    echo "<tr class=\"player\">\n";
    echo "<th class=\"stats\">$title <font size=2><i>(toutes saisons confondues)</i></font></th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    switch ($display) {
        case c_stats_by_team:
            $data = get_records_by_team($season);
            put_records_by_team($data);
            break;
        case c_stats_by_player:
            $datas = get_records_by_player($season);
            put_records_by_player($datas);
            break;
        case c_stats_fun:
            $datas = get_records_fun($season);
            put_records_fun($datas);
            break;
        case c_stats_exterieur:
            $datas = get_records_exterieur($season);
            put_records_exterieur($datas);
            break;
        case c_stats_coiffeur:
            $datas = get_records_coiffeur($season);
            put_records_coiffeur($datas);
            break;
        case c_stats_BOff:
            $datas = get_records_BOff($season);
            put_records_BOff($datas);
            break;
        case c_stats_14:
            $datas = get_records_14($season);
            put_records_14($datas);
            break;
        default:
            $datas = get_records_by_player($season);
            put_records_by_player($datas);
            break;
    }
}

function stats($p)
{

    printr_log(__FUNCTION__, "p", $p);
    $display = $p['display_stats'];
    $season  = 0;
    if (isset($p['last_season'])) {
        $season = $p['last_season'];
    }

    $top7_season = get_top7_season_by_id($season);

    $title = "Stats " . $top7_season['title'];

    echo "<table class=\"player\">\n";
    echo "<tr class=\"player\">\n";
    echo "<th class=\"stats\">$title <font size=2><i>(toutes équipes confondues)</i></font></th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    #echo "<pre>";print_r($p);echo "</pre>";

    switch ($display) {
        case c_stats_by_team:
            $data = get_stats_by_team($season);
            put_stats_by_team($data);
            break;
        case c_stats_by_player:
            $data = get_stats_by_player($season);
            put_stats_by_player($data);
            break;
        case c_stats_average:
            $data = get_stats_average($season);
            put_stats_average($data);
            break;
        case c_stats_fun:
            $data = get_stats_fun($season);
            put_stats_fun($data);
            break;
        case c_stats_exterieur:
            $data = get_stats_exterieur($season);
            put_stats_exterieur($data);
            break;
        case c_stats_coiffeur:
            $data = get_stats_coiffeur($season);
            put_stats_coiffeur($data);
            break;
        case c_stats_BOff:
            $data = get_stats_BOff($season);
            put_stats_BOff($data);
            break;
        case c_stats_14:
            $data = get_stats_14($season);
            put_stats_14($data);
            break;
        default:
            $data = get_stats_by_player($season);
            put_stats_by_player($data);
            break;
    }
}

function get_records_by_team($season)
{
    $query = "select ";
    $query .= "team_player.name, ";
    $query .= "season.title as season, ";
    $query .= "sum(point) as pts, ";
    $query .= "format(sum(point)/(sum(J)/7),2) as avg_day, "; // moyenne par journée
    $query .= "sum(fun) as fun, ";
    $query .= "format(sum(J)/7,0) as J, ";
    $query .= "sum(G) as G, ";
    $query .= "sum(N) as N, ";
    $query .= "sum(P) as P, ";
    $query .= "sum(pm)-sum(pe) as diff, ";
    $query .= "sum(bd) as bd, ";
    $query .= "sum(bo) as bo, ";
    $query .= "sum(bo)+sum(bd) as bonus, ";
    $query .= "sum(pc) as pc, ";
    $query .= "sum(ve) as ve, ";
    $query .= "sum(if(eq=14,1,0)) as n14 ";
    $query .= "from `team_player` ";
    $query .= "join `player` on team_player.team_idx=player.team ";
    $query .= "join `season` on team_player.season=season.Id ";
    $query .= "and team_player.season < $season ";
    $query .= "and team_player.season <> " . c_canceled_season . " ";
    $query .= "group by team_player.team_idx order by PTS desc, G desc, ve desc, n14 desc, N desc, diff desc ";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_stats_by_team($season)
{
    $query = "select ";
    $query .= "team_player.name, ";
    $query .= "sum(point) as pts, ";
    $query .= "format(sum(point)/(sum(J)/7),2) as avg_day, "; // moyenne par journée
    $query .= "sum(fun) as fun, ";
    $query .= "format(sum(J)/7,0) as J, ";
    $query .= "sum(G) as G, ";
    $query .= "sum(N) as N, ";
    $query .= "sum(P) as P, ";
    $query .= "sum(pm)-sum(pe) as diff, ";
    $query .= "sum(bd) as bd, ";
    $query .= "sum(bo) as bo, ";
    $query .= "sum(bo)+sum(bd) as bonus, ";
    $query .= "sum(pc) as pc, ";
    $query .= "sum(ve) as ve, ";
    $query .= "sum(if(eq=14,1,0)) as n14 ";
    $query .= "from `team_player` join player ";
    $query .= "where team_player.season=$season and player.team=team_player.team_idx ";
    $query .= "group by name order by PTS desc, G desc, ve desc, n14 desc, N desc, diff desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_records_by_player($season)
{
    $query = "select ";
    $query .= "pseudo, ";
    $query .= "team_player.name as team, ";
    $query .= "season.title as season, ";
    $query .= "point as pts, ";
    $query .= "format(point/J,2) as avg, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `team_player` ";
    $query .= "join `player` on team_player.team_idx=player.team ";
    $query .= "join `season` on team_player.season=season.Id ";
    $query .= "and team_player.season < $season ";
    $query .= "and team_player.season <> " . c_canceled_season . " ";
    $query .= "order by PTS desc, G desc, ve desc, eq desc, N desc, diff desc ";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_stats_by_player($season)
{
    $query = "select ";
    $query .= "pseudo, ";
    $query .= "team_player.name as team, ";
    $query .= "point as pts, ";
    $query .= "format(point/J,2) as avg, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `player` join `team_player` ";
    $query .= "where player.season=$season and player.team=team_player.team_idx ";
    $query .= "order by PTS desc, G desc, ve desc, eq desc, N desc, diff desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_stats_average($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "point as pts, ";
    $query .= "format(point/J,2) as avg, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `player` join `team_player` ";
    $query .= "where player.season=$season and player.team=team_player.team_idx ";
    $query .= "order by avg desc, PTS desc, G desc, ve desc, eq desc, N desc, diff desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_records_fun($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "season.title as season, ";
    $query .= "point as pts, ";
    $query .= "format(point/J,2) as avg, ";
    $query .= "fun, ";
    $query .= "format(fun/J,2) as avg_fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `team_player` ";
    $query .= "join `player` on team_player.team_idx=player.team ";
    $query .= "join `season` on team_player.season=season.Id ";
    $query .= "and team_player.season < $season ";
    $query .= "and team_player.season <> " . c_canceled_season . " ";
    $query .= "order by fun desc, PTS desc, G desc, ve desc, eq desc, N desc, diff desc ";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_stats_fun($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "point as pts, ";
    $query .= "format(point/J,2) as avg, ";
    $query .= "fun, ";
    $query .= "format(fun/J,2) as avg_fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `player` join `team_player` ";
    $query .= "where player.season=$season and player.team=team_player.team_idx ";
    $query .= "order by fun desc, PTS desc, G desc, ve desc, eq desc, N desc, diff desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_records_exterieur($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "season.title as season, ";
    $query .= "point as pts, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `team_player` ";
    $query .= "join `player` on team_player.team_idx=player.team ";
    $query .= "join `season` on team_player.season=season.Id ";
    $query .= "and team_player.season < $season ";
    $query .= "and team_player.season <> " . c_canceled_season . " ";
    $query .= "and ve <> '' ";
    $query .= "order by ve desc, G desc, N desc, PTS desc ";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_stats_exterieur($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "point as pts, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `player` join `team_player` ";
    $query .= "where player.season=$season and player.team=team_player.team_idx ";
    $query .= "and ve <> '' ";
    $query .= "order by ve desc, G desc, N desc, PTS desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_records_coiffeur($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "season.title as season, ";
    $query .= "point as pts, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `team_player` ";
    $query .= "join `player` on team_player.team_idx=player.team ";
    $query .= "join `season` on team_player.season=season.Id ";
    $query .= "and team_player.season < $season ";
    $query .= "and team_player.season <> " . c_canceled_season . " ";
    $query .= "and pc <> '' ";
    $query .= "order by pc desc, bo desc, bd desc, PTS desc ";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_stats_coiffeur($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "point as pts, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `player` join `team_player` ";
    $query .= "where player.season=$season and player.team=team_player.team_idx ";
    $query .= "and pc <> '' ";
    $query .= "order by pc desc, bo desc, bd desc, PTS desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_records_BOff($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "season.title as season, ";
    $query .= "point as pts, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `team_player` ";
    $query .= "join `player` on team_player.team_idx=player.team ";
    $query .= "join `season` on team_player.season=season.Id ";
    $query .= "and team_player.season < $season ";
    $query .= "and team_player.season <> " . c_canceled_season . " ";
    $query .= "and bo <> '' ";
    $query .= "order by bo desc, bd desc, PTS desc ";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_stats_BOff($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "point as pts, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "eq, ";
    $query .= "ve ";
    $query .= "from `player` join `team_player` ";
    $query .= "where player.season=$season and player.team=team_player.team_idx ";
    $query .= "and bo <> '' ";
    $query .= "order by bo desc, bd desc, PTS desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_records_14($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "season.title as season, ";
    $query .= "point as pts, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "ve, ";
    $query .= "eq, ";
    $query .= "d14 ";
    $query .= "from `team_player` ";
    $query .= "join `player` on team_player.team_idx=player.team ";
    $query .= "join `season` on team_player.season=season.Id ";
    $query .= "and team_player.season < $season ";
    $query .= "and team_player.season <> " . c_canceled_season . " ";
    #$query .= "and d14 <> '' ";
    $query .= "order by ifnull(d14, 26) asc, eq desc, pts desc ";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function get_stats_14($season)
{
    $query = "select ";
    $query .= "pseudo,  ";
    $query .= "team_player.name as team, ";
    $query .= "point as pts, ";
    $query .= "fun, ";
    $query .= "J, ";
    $query .= "G, ";
    $query .= "N, ";
    $query .= "P, ";
    $query .= "pm-pe as diff, ";
    $query .= "bd, ";
    $query .= "bo, ";
    $query .= "bo+bd as bonus, ";
    $query .= "pc, ";
    $query .= "ve, ";
    $query .= "eq, ";
    $query .= "d14 ";
    $query .= "from `player` join `team_player` ";
    $query .= "where player.season=$season and player.team=team_player.team_idx ";
    #$query .= "and d14 <> '' ";
    $query .= "order by ifnull(d14, 26) asc, eq desc, pts desc";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function remove_duplicate_name($datas, $name)
{
    $keys = array();
    $filtered_datas = array();
    foreach($datas as $rank) {
        $key = $rank[$name];
        if(!in_array($key, $keys)) {
            $filtered_datas[] = $rank;
            $keys[] = $key;
        }
    }
    return $filtered_datas;
}

function put_records_by_team($datas)
{
    if( c_records_remove_duplicate) $datas = remove_duplicate_name($datas, 'name');

    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Equipe Saison PTS Bonus J G N P +/- BO BD Ge 14! Co
    // -----------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Saison</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("14!", "14 équipes différentes !");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        if ($idx == 1) echo "<tr class=\"records_$idx\">\n";
        else echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">$idx</td>\n";
        echo "<td class=\"point\">" . $data['name'] . "</td>\n";
        echo "<td class=\"point\">" . $data['season'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"point\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['n14'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
        if($idx > c_records_limit) break;
    }
    echo "</table>\n";
}

function put_stats_by_team($datas)
{
    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Equipe PTS (Moy) (fun) Bonus J G N P +/- BO BD Ge 14! Co
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"fun_stats\">";
    put_abbr("(Moy)", "Moyenne des points par journée");
    echo "</th>\n";
    echo "<th class=\"fun_stats\">";
    put_abbr("(fun)", "Points fun");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("14!", "14 équipes différentes !");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">$idx</td>\n";
        echo "<td class=\"point\">" . $data['name'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['avg_day'] . ")</td>\n";
        echo "<td class=\"fun\">(" . $data['fun'] . ")</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"point\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['n14'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

function put_records_by_player($datas)
{
    if( c_records_remove_duplicate) $datas = remove_duplicate_name($datas, 'pseudo');

    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Saison PTS Bonus J G N P +/- BO BD Ge Eq Co
    // -----------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Saison</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        if ($idx == 1) echo "<tr class=\"records_$idx\">\n";
        else echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['pts']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"point\">" . $data['season'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
        if($idx > c_records_limit) break;
    }
    echo "</table>\n";
}

function put_stats_by_player($datas)
{
    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe PTS (Moy) (fun) Bonus J G N P +/- BO BD Ge Eq Co
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"fun_stats\">";
    put_abbr("(Moy)", "Moyenne des points par journée");
    echo "</th>\n";
    echo "<th class=\"fun_stats\">";
    put_abbr("(fun)", "Points fun");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['pts']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['avg'] . ")</td>\n";
        echo "<td class=\"fun\">(" . $data['fun'] . ")</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

function put_stats_average($datas)
{
    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Moyenne Pts J G N P +/- BO BD Ge Eq Co
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Moyenne", "Moyenne des points par journée");
    echo "</th>\n";
    echo "<th class=\"$class\">Points</th>\n"; // PTS
    echo "<th class=\"fun_stats\">";
    put_abbr("(fun)", "Points fun");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['avg']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['avg'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['fun'] . ")</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

function put_records_fun($datas)
{
    if( c_records_remove_duplicate) $datas = remove_duplicate_name($datas, 'pseudo');

    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Saison Pts Fun PTS Bonus J G N P +/- BO BD Ge Eq Co
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Saison</th>\n";
    echo "<th class=\"$class\">Points fun</th>\n"; // PTS
    echo "<th class=\"$class\">PTS</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        if ($idx == 1) echo "<tr class=\"records_$idx\">\n";
        else echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['fun']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"point\">" . $data['season'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['fun'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
        if($idx > c_records_limit) break;
    }
    echo "</table>\n";
}

function put_stats_fun($datas)
{
    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Pts Fun (Moy) PTS (Moy) Bonus J G N P +/- BO BD Ge Eq Co
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Points fun</th>\n"; // PTS
    echo "<th class=\"fun_stats\">";
    put_abbr("(Moy)", "Moyenne des points fun par journée");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n";
    echo "<th class=\"fun_stats\">";
    put_abbr("(Moy)", "Moyenne des points par journée");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['fun']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['fun'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['avg_fun'] . ")</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['avg'] . ")</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

function put_records_exterieur($datas)
{
    if( c_records_remove_duplicate) $datas = remove_duplicate_name($datas, 'pseudo');

    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Saison Exterieur J G N P PTS  Bonus +/- BO BD Eq Co
    // -------------------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Saison</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        if ($idx == 1) echo "<tr class=\"records_$idx\">\n";
        else echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['ve']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"point\">" . $data['season'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"point\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
        if($idx > c_records_limit) break;
    }
    echo "</table>\n";
}

function put_stats_exterieur($datas)
{
    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Exterieur J G N P PTS (fun) Bonus +/- BO BD Eq Co
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"fun_stats\">";
    put_abbr("(fun)", "Points fun");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['ve']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['G'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['fun'] . ")</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"point\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

function put_records_coiffeur($datas)
{
    if( c_records_remove_duplicate) $datas = remove_duplicate_name($datas, 'pseudo');

    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Season Coiffeur BO BD PTS Bonus J G N P +/- Ge Eq
    // -----------------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Saison</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        if ($idx == 1) echo "<tr class=\"records_$idx\">\n";
        else echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['pc']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"point\">" . $data['season'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pc'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"point\">" . $data['G'] . "</td>\n";
        echo "<td class=\"point\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"point\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $data['eq'] . "</td>\n";
        $idx++;
        if($idx > c_records_limit) break;
    }
    echo "</table>\n";
}

function put_stats_coiffeur($datas)
{
    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Coiffeur BO BD PTS (fun) Bonus J G N P +/- Ge Eq
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"fun_stats\">";
    put_abbr("(fun)", "Points fun");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['pc']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pc'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['fun'] . ")</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"point\">" . $data['G'] . "</td>\n";
        echo "<td class=\"point\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"point\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $data['eq'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

function put_records_BOff($datas)
{
    if( c_records_remove_duplicate) $datas = remove_duplicate_name($datas, 'pseudo');

    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Saison BO BD PTS Bonus J G N P +/- Ge Eq Co
    // -----------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Saison</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        if ($idx == 1) echo "<tr class=\"records_$idx\">\n";
        else echo "<tr class=\"$rank\">\n";
        #echo "<td class=\"point\">" . $exaequo->proc($data['bo']) . "</td>\n";
        echo "<td class=\"point\">" . $idx . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"point\">" . $data['season'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"point\">" . $data['G'] . "</td>\n";
        echo "<td class=\"point\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"point\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
        if($idx > c_records_limit) break;
    }
    echo "</table>\n";
}

function put_stats_BOff($datas)
{
    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe BO BD PTS (fun) Bonus J G N P +/- Ge Eq Co
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"fun_stats\">";
    put_abbr("(fun)", "Points fun");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['bo']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['fun'] . ")</td>\n";
        echo "<td class=\"point\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"point\">" . $data['G'] . "</td>\n";
        echo "<td class=\"point\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"point\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

function put_records_14($datas)
{
    if( c_records_remove_duplicate) $datas = remove_duplicate_name($datas, 'pseudo');

    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Saison 14! Eq PTS Bonus J G N P +/- BO BD Ge Co
    // ---------------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Saison</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("14!", "Journée pour 14 équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        if ($idx == 1) echo "<tr class=\"records_$idx\">\n";
        else echo "<tr class=\"$rank\">\n";
        #echo "<td class=\"point\">" . $exaequo->proc($data['d14']) . "</td>\n";
        echo "<td class=\"point\">" . $idx . "</td>\n";
        if ($data['d14'] < 14) {
            $class  = "point_italic";
            $class1 = $class;
        } else {
            $class  = "point";
            $class1 = "point_bold";
        }
        echo "<td class=\"$class\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"$class\">" . $data['team'] . "</td>\n";
        echo "<td class=\"$class\">" . $data['season'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['d14'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"$class\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"point\">" . $data['G'] . "</td>\n";
        echo "<td class=\"point\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"point\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"point\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        if ($data['d14'] < 14) {
            echo "</i>";
        }
        $idx++;
        if($idx > c_records_limit) break;
    }
    echo "</table>\n";
}

function put_stats_14($datas)
{
    echo "<table class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe 14! Eq PTS (fun) Bonus J G N P +/- BO BD Ge Co
    // ------------------------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("14!", "Journée pour 14 équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Eq", "Nombre d'équipes différentes");
    echo "</th>\n";
    echo "<th class=\"$class\">PTS</th>\n"; // PTS
    echo "<th class=\"fun_stats\">";
    put_abbr("(fun)", "Points fun");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Bonus", "Bonus");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("J", "Nombre de journées");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("G", "Gagné");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("N", "Nul");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("P", "Perdu");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("+/-", "Différence de points");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BO", "Bonus Offensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("BD", "Bonus Defensif");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Ge", "Victoires Extérieures");
    echo "</th>\n";
    echo "<th class=\"$class\">";
    put_abbr("Co", "Points coiffeur");
    echo "</th>\n";
    echo "</tr>\n";

    $idx    = 1;
    $ranks  = array("odd", "even");
    $class0 = "point";
    $class1 = "point_bold";
    $exaequo = new Exaequo();
    foreach ($datas as $data) {
        $rank = $ranks[$idx % 2];
        echo "<tr class=\"$rank\">\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['d14']) . "</td>\n";
        if ($data['d14'] < 14) {
            $class  = "point_italic";
            $class1 = $class;
        } else {
            $class  = "point";
            $class1 = "point_bold";
        }
        echo "<td class=\"$class\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"$class\">" . $data['team'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['d14'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['eq'] . "</td>\n";
        echo "<td class=\"$class1\">" . $data['pts'] . "</td>\n";
        echo "<td class=\"fun\">(" . $data['fun'] . ")</td>\n";
        echo "<td class=\"$class\">" . $data['bonus'] . "</td>\n";
        echo "<td class=\"point\">" . $data['J'] . "</td>\n";
        echo "<td class=\"point\">" . $data['G'] . "</td>\n";
        echo "<td class=\"point\">" . $data['N'] . "</td>\n";
        echo "<td class=\"point\">" . $data['P'] . "</td>\n";
        echo "<td class=\"point\">" . $data['diff'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['bd'] . "</td>\n";
        echo "<td class=\"point\">" . $data['ve'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pc'] . "</td>\n";
        if ($data['d14'] < 14) {
            echo "</i>";
        }
        $idx++;
    }
    echo "</table>\n";
}

function put_records_legend($display)
{
}

function put_stats_legend($display)
{

    echo "<div id=\"legend\" class=\"hidden\">\n";
    echo "<div class=\"info\">\n";
    readfile(c_stats_legend_file . "." . $display . ".html");
    echo "</div>\n";
    echo "</div>\n";

    echo "<div id=\"pointsFun\" class=\"hidden\">\n";
    echo "<div class=\"info\">\n";
    readfile(c_pointsFun_file);
    echo "</div>\n";
    echo "</div>\n";
}

function put_stats_info($p)
{

    $display = $p['display_stats'];
    echo "<br>\n";
    echo "<table class=\"nav\" border=0>\n";
    echo "<tr><td>\n";
    echo "<div class=\"info\">\n";
    echo "<a href=\"javascript:unhide('legend');\">Légendes</a> - ";
    echo "<a href=\"javascript:unhide('pointsFun');\">Points fun</a>";
    echo "</div>\n";
    put_stats_legend($display);
    echo "</td></tr>\n";
    echo "</table>\n";
}

function get_palmares($season)
{
    $query = "select ";
    $query .= "pseudo, ";
    $query .= "team_player.name as team, ";
    $query .= "season.title as season, ";
    $query .= "point as pts ";
    $query .= "from `team_player` ";
    $query .= "join `player` on team_player.team_idx=player.team ";
    $query .= "join `season` on team_player.season=season.Id ";
    $query .= "and team_player.season < $season ";
    $query .= "and team_player.season <> " . c_canceled_season . " ";
    $query .= "and player.rankFinal = 1 ";
    $query .= "group by team_player.team_idx ";
    $query .= "order by season.Id";
    return pdo_fetch(__FUNCTION__, c_all, $query);
}

function palmares_star_icon($count) {
    $stars = "";
    for ($i=0; $i<$count; $i++) {
        $stars .= "<img src=\"star.png\">";
    }
    return $stars;
}

function palmares($p)
{
    $season  = 0;
    if (isset($p['season'])) {
        $season = $p['season'];
    }

    $title = "PALMARES DES CHAMPIONS";
    echo "<table id=\"palmares\" class=\"nav_stats\">\n";
    echo "<tr class=\"player\">\n";
    echo "<th class=\"palmares\">$title</th>\n";
    echo "</tr>\n";
    echo "</table>\n";

    $data = get_palmares($season);
    printr_log(__FUNCTION__, 'data', $data);

    $palmares_not_sorted = array();
    foreach( $data as $item) {
        $pseudo = trim($item['pseudo'], " ★☆");
        if( array_key_exists( $pseudo, $palmares_not_sorted)) {
            $count = $palmares_not_sorted[$pseudo]["count"] += 1;
            $year = $palmares_not_sorted[$pseudo]["season"] . "," . substr($item["season"], -4);
            $pts = $palmares_not_sorted[$pseudo]["pts"];
            if( $item["pts"] > $pts) $pts =  $item["pts"];
        } else {
            $year = substr($item['season'], -4);
            $count = 1;
            $pts = $item["pts"];
        }
        $palmares_not_sorted[$pseudo] = array("count" => $count, "team" => $item["team"], "season" => $year, "pts" => $pts);
    }

    $palmares = array();
    foreach ($palmares_not_sorted as $pseudo => $data) {
        $palmares[] = array_merge(array( "pseudo" => $pseudo), $data);
    }    
    printr_log(__FUNCTION__, 'palmares not sorted', $palmares);

    #$count = array_column($palmares, 'count');
    #$pts = array_column($palmares, 'pts');
    $count = array();
    $pts = array();
    foreach ($palmares as $key => $row) {
        $count[$key]  = $row['count'];
        $pts[$key] = $row['pts'];
    }
    $palmares_sorted = array_multisort($count, SORT_DESC, $pts, SORT_DESC, $palmares);
    printr_log(__FUNCTION__, 'palmares sorted', $palmares);

    echo "<table id=\"palmares\" class=\"day\" border=0>\n";
    // Line 1 :   #  Joueur Equipe Titres Saison Points 
    // -------------------------------------------------
    $class = "stats";
    echo "<tr>\n";
    echo "<th class=\"$class\">#</th>\n";
    echo "<th class=\"$class\">Joueur</th>\n";
    echo "<th class=\"$class\">Equipe</th>\n";
    echo "<th class=\"$class\">Titres</th>\n";
    echo "<th class=\"$class\">Saison</th>\n";
    echo "<th class=\"$class\">Points</th>\n";
    echo "</tr>\n";


    $idx    = 1;
    $ranks  = array("odd", "even");
    $exaequo = new Exaequo();
    foreach ($palmares as $data) {
        $rank = $ranks[$idx % 2];
        if ($idx == 1) echo "<tr class=\"palmares_$idx\">\n";
        else echo "<tr class=\"$rank\">\n";
        #echo "<td class=\"point\">$idx</td>\n";
        echo "<td class=\"point\">" . $exaequo->proc($data['pts']) . "</td>\n";
        echo "<td class=\"point\">" . $data['pseudo'] . "</td>\n";
        echo "<td class=\"point\">" . $data['team'] . "</td>\n";
        $stars = palmares_star_icon($data['count']);
        echo "<td class=\"point\">" . $stars . "</td>\n";
        echo "<td class=\"point\">" . $data['season'] . "</td>\n";
        echo "<td class=\"point\">" . $data['pts'] . "</td>\n";
        $idx++;
    }
    echo "</table>\n";
}

class Exaequo
{
    function __construct()
    {
        $this->idx = 0;
        $this->val = 0;
    }
    function proc($value)
    {
        $print = True;
        if ($this->idx == 0) $this->val = $value;
        else {
            if ($value == $this->val) $print = False;
            else $this->val = $value;
        }
        $this->idx++;
        if ($print) return $this->idx;
        else return "";
    }
}

function register_same_top7team($p, $team_name) 
{
    $team = $p['top7team_to_register'];
    $players = get_top7team_players($team);
    printr_log(__FUNCTION__, "players", $players);

    $team_idx = insert_new_team($team_name, c_team_enable);

    foreach($players as $player) {
        insert_same_player($player['pseudo'], $player['password'], $player['email'], $team_idx, $player['captain']);   
    }
    return $team_idx;
}