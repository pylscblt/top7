#!/bin/bash

file=team.csv

awk -F "," 'NR==1 { \
    printf("INSERT INTO `team` "); \
    printf("(`%s`,`%s`,`%s`,`%s`,`%s`) VALUES\n",$1,$2,$3,$4,$5)}' $file
n=$( awk 'END {print NR}' $file )
awk -F "," -v n=$n 'NR>1 && NR<n { \
    printf("(%d,'\''%s'\'','\''%s'\'',%d,%d),\n",$1,$2,$3,$4,$5)}' $file
awk -F "," -v n=$n 'NR==n { \
    printf("(%d,'\''%s'\'','\''%s'\'',%d,%d);\n",$1,$2,$3,$4,$5)}' $file
