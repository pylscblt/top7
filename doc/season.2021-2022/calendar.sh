#!/bin/bash

file=calendar.csv

awk -F "," 'NR==1 { \
    printf("INSERT INTO `calendar` "); \
    printf("(`%s`, `%s`, `%s`) VALUES\n",$1,$2,$3)}' $file
n=$( awk 'END {print NR}' $file )
awk -F "," -v n=$n 'NR>1 && NR<n { \
    printf("(%d, %d, '\''%s'\''),\n",$1,$2,$3)}' $file
awk -F "," -v n=$n 'NR==n { \
    printf("(%d, %d, '\''%s'\'');\n",$1,$2,$3)}' $file

