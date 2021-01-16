#!/bin/bash
first="$1" 
for i in `seq 100`
do
	sleep 1
	if [[ $(($i%3)) -eq 1 ]] ; then
		clear
		echo "check ."
	elif [[ $(($i%3)) -eq 2 ]] ; then
		clear
		echo "check .."
	else
		clear
		echo "check ..."
	fi
	if [[ `./prog | grep "fail" | wc -l` -ne 0 ]] ; then
		echo "Error"
		exit
	fi
done
