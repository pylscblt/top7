#!/bin/bash

usage() 
{
    echo "Usage: $(basename $0) [file.tgz]
    example: $(basename $0) top7_2020-10-05_0152.tgz" 
    exit 1
}
[[ -z "$1" ]] && usage
file=$1
[[ -f "$file" ]] || echo "file $file not found"

tar -zxvf $file -C /tmp || exit

user=topseven
password=topseven
db=topseven
sql_file=top7.sql
sed -i "1i USE $db;"  /tmp/$sql_file
cat /tmp/$sql_file | docker exec -i test_db_1 mysql -u$user -p$password
exit
