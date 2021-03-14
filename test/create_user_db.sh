#!/bin/bash

batch=user_db.sql
user=root
password=root
cat $batch | docker exec -i test_db_1 mysql -u$user -p$password
