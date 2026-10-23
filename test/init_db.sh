#!/bin/bash

batch=topseven.sql
user=topseven
password=topseven
db=topseven
cat $batch | docker exec -i lamp_database mysql -u$user -p$password $db
