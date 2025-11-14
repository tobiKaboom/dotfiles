#!/bin/bash

while true
do
	xsetroot -name "$(free -m | grep Mem | awk '{ printf "%3.0f\n", ($3/$2)*100}')% ram  $( TZ='Europe/Rome' date +"%R" )" 
	sleep 10
done
