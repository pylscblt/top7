/* Top7 
 *
 *
 *
 */


function unhide(divID) {
    var item = document.getElementById(divID);
    if (item) {
      item.className=(item.className=='hidden')?'unhidden':'hidden';
    }
}

function display_c(start) {
	window.start = parseFloat(start);
	var end = 0 // change this to stop the counter at a higher value
	var refresh=1000; // Refresh rate in milli seconds
	if(window.start >= end ) mytime=setTimeout('display_ct()',refresh);
}

function display_ct() {
// Calculate the number of days left
	var days=Math.floor(window.start / 86400); 
// After deducting the days calculate the number of hours left
	var hours = Math.floor((window.start - (days * 86400 ))/3600)
// After days and hours , how many minutes are left 
	var minutes = Math.floor((window.start - (days * 86400 ) - (hours *3600 ))/60)
// Finally how many seconds left after removing days, hours and minutes. 
	var secs = Math.floor((window.start - (days * 86400 ) - (hours *3600 ) - (minutes*60)))

	//if( days > 0) var x = window.start + " sec (" + days + " jours " + hours + " h " + minutes + " mn  " + secs + " sec)";
	//else var x = window.start + " sec (" + hours + " h " + minutes + " mn  " + secs + " sec)";
	if( days > 0) var x = days + " jours " + hours + " h " + minutes + " mn " + secs + " sec";
	else var x = hours + " h " + minutes + " mn " + secs + " sec";

	var ct = document.getElementById('ct');
	if (ct) {
		document.getElementById('ct').innerHTML = x;
		window.start= window.start- 1;

		tt=display_c(window.start);
	}
}

function check_not_empty() {
    var p1 = document.forms["PasswordForm"]["password1"].value;
    var p2 = document.forms["PasswordForm"]["password2"].value;
    if (p1 == null || p1 == "" || p2 == null || p2 == "") {
        return false;
    }
}
/*
 *
 *
 */

