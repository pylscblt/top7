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

#$url="http://www.lesbrevesdovalie.com";
$url="http://www.lesbrevesdovalie.com/archives/les_breves_d_ovalie___";
$url="http://www.lesbrevesdovalie.com/tag/TOP%2014";
$page1=getHtmlTags($url);
if($page1) {
	#echo "<pre>";
	#print_r($page1);
	#echo "</pre>";
	foreach($page1 as $match) {
		if(strstr($match[3],"Les brèves d'Ovalie - Edition")) {
			$url=$match[2];
			#echo "$url";
			// get 1st picture on last Edition
			$page2=getHtmlTags($url);
			if($page2) {
				foreach($page2 as $match) {
					if(strstr($match[2],"storage.canalblog.com")) {
						#echo "<pre>";print_r($match);echo "</pre>";
						$file=basename($match[2], ".jpg");
						$filename=$file.".jpg";
						#echo $path.$filename;
						if(!file_exists($path.$filename)) {
							file_put_contents($path.$filename, file_get_contents($match[2]));
							if(filesize($path.$filename)>1000) copy($path.$filename, $login_img);
						}
						break;
					}
				}
			}
			break;
		}
	}
}
?>
