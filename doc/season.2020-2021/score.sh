#!/bin/bash

function line()
{
    season=6
    day=$1
    team=$2
    echo "($season,$day,$team,0,0,0,0,0,0,0,0,0,0,0,0,0),"
}

echo "INSERT INTO \`score\` (\`season\`, \`day\`, \`team\`, \`rank\`, \`pm\`, \`pe\`, \`pc\`, \`bd\`, \`bo\`, \`em\`, \`ee\`, \`ve\`, \`J\`, \`V\`, \`N\`, \`D\`) VALUES"

day=1
while [ $day -le 26 ]; do
    team=1
    while [ $team -le 14 ]; do
        line $day $team
        (( team++ ))
    done
    (( day++ ))
done
team=0
match=1
while [ $match -le 4 ]; do
    line $day $team
    (( match++ ))
done
(( day++ ))
match=1
while [ $match -le 4 ]; do
    line $day $team
    (( match++ ))
done
(( day++ ))
match=1
while [ $match -le 2 ]; do
    line $day $team
    (( match++ ))
done
