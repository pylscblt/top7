#!/bin/bash

file=team.csv

head -n 1 $file | awk -F "," '{ \
    printf("INSERT INTO `team` "); \
    printf("(`%s`,`%s`,`%s`,`%s`,`%s`) VALUES\n",$1,$2,$3,$4,$5)}'
n=$( awk 'END {print NR-1}' $file )
tail -n $n $file | awk -F "," '{ \
    printf("(%d,'\''%s'\'','\''%s'\'',%d,%d),\n",$1,$2,$3,$4,$5)}'
