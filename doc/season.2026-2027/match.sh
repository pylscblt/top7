#!/bin/bash

file=match.csv

awk -F "," 'NR==1 { \
    printf("INSERT INTO `match` "); \
    printf("(`%s`,`%s`,`%s`,`%s`,`%s`,`%s`) VALUES\n",$1,$2,$3,$4,$5,$6)}' $file
n=$( awk 'END {print NR}' $file )
awk -F "," -v n=$n 'NR>1 && NR<n { \
    printf("(%d,%d,%d,%d,'\''%s'\'','\''%s'\''),\n",$1,$2,$3,$4,$5,$6)}' $file
awk -F "," -v n=$n 'NR==n { \
    printf("(%d,%d,%d,%d,'\''%s'\'','\''%s'\'');\n",$1,$2,$3,$4,$5,$6)}' $file

