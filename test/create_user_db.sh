#!/bin/bash

batch=user_db.sql
user=root
password=root
cat $batch | docker exec -i lamp_database mysql -u$user -p$password
