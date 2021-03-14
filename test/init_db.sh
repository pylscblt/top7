#!/bin/bash

batch=topseven.sql
user=topseven
password=topseven
db=topseven
cat $batch | docker exec -i test_db_1 mysql -u$user -p$password $db
