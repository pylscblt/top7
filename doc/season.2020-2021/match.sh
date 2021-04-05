#!/bin/bash

file=match.csv

head -n 1 $file | awk -F "," '{ \
    printf("INSERT INTO `match` "); \
    printf("(`%s`,`%s`,`%s`,`%s`,`%s`,`%s`) VALUES\n",$1,$2,$3,$4,$5,$6)}'
n=$( awk 'END {print NR-1}' $file )
tail -n $n $file | awk -F "," '{ \
    printf("(%d,%d,%d,%d,'\''%s'\'','\''%s'\''),\n",$1,$2,$3,$4,$5,$6)}'
