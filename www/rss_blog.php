#!/usr/local/bin/php
cd /home/topsevenyu/www
<?php
// call by crontab
include("common.inc");

function getHtmlTags($url) {
	$input=@file_get_contents($url);
	$regex="<a\s[^>]*href=(\"??)([^\" >]*?)\\1[^>]*>(.*)<\/a>";
	if(preg_match_all("/$regex/siU",$input,$matches,PREG_SET_ORDER)) return $matches;
	else return FALSE;
}

# save RSS
file_put_contents( "/home/topsevenyu/www/" . c_file_blog, file_get_contents( c_url_blog));

// read  page categorie / Les brèves d'Ovalie to get link on last Edition

$path="/home/topsevenyu/www/img/";
$login_img="/home/topsevenyu/www/top7_login.jpeg";

# save picture
#$url="http://www.lesbrevesdovalie.com";
#$url="http://www.lesbrevesdovalie.com/archives/les_breves_d_ovalie___";
$url="http://www.lesbrevesdovalie.com/tag/TOP%2014";
$page1=getHtmlTags($url);
if($page1) {
	#echo "<pre>";
	#print_r($page1);
	#echo "</pre>";
	foreach($page1 as $match) {
        $pos = stripos($match[0], "data-pin-media");
        if($pos !== false) {
            $lines = explode("\n", $match[0]);
            foreach($lines as $line) {
                $pos = stripos($line, "data-pin-media");
                if($pos !== false) {
                    #echo "<pre>";
                    #echo $line;
                    #echo "</pre>";
                    preg_match("/data-pin-media=(.*)/", $line, $match);
                    $url = substr($match[1], 1, -1);
                    #echo "<pre>$url</pre>";
                    $name = end(explode("%", $url));
                    #echo "<pre>$name</pre>";
		            if(!file_exists($path.$name)) {
			            file_put_contents($path.$name, file_get_contents($url));
			            if(filesize($path.$name)>1000) copy($path.$name, $login_img);
			        }
                }
            }
            break;
        }
    }
}
?>
