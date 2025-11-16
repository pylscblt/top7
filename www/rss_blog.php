#!/usr/local/bin/php
<?php
// call by crontab
include("common.inc");

# save RSS
$path="/home/topsevenyu/www/";
$path = "";
file_put_contents($path . c_file_blog, file_get_contents( c_url_blog));

$img_path=$path."img/";
$login_img=$path."top7_login.jpeg";

# get jpeg file from the 1st item with category=Les Breves d'Ovalie
$news = get_rss(c_file_blog, 4);
foreach($news as $new) {
    if( substr($new['category'][0],0,6) === 'Les Br') {
#    if( str_starts_with($new['category'][0], 'Les Brèves')) {
        $img_url = $new['img'];
        $name = basename($img_url);
        echo "<pre>$img_url</pre>";
        echo "<pre>$name</pre>";
        if(!file_exists($img_path.$name)) {
            file_put_contents($img_path.$name, file_get_contents($img_url));
            if(filesize($img_path.$name)>1000) copy($img_path.$name, $login_img);
        }
        break;
    }
}

?>
