#!/bin/bash

file=match.csv
awk -F "," '{printf("%s,%s,%s\n",$1,$2,$5)}' $file |sort -u |sort --field-separator="," -n -k 2 > calendar.csv


file=calendar.csv

awk -F "," 'NR==1 { \
    printf("INSERT INTO `calendar` "); \
    printf("(`%s`, `%s`, `%s`) VALUES\n",$1,$2,$3)}' $file
n=$( awk 'END {print NR}' $file )
awk -F "," -v n=$n 'NR>1 && NR<n { \
    printf("(%d, %d, '\''%s'\''),\n",$1,$2,$3)}' $file
awk -F "," -v n=$n 'NR==n { \
    printf("(%d, %d, '\''%s'\'');\n",$1,$2,$3)}' $file

