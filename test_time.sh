#!/bin/bash

declare -a nums=(10 100 1000 10000 100000 1000000 10000000)
declare -a commands=("stl" "qsort" "merge" "quick")

for j in "${commands[@]}"
do 
	for i in  "${nums[@]}"
	do
		echo $i
		echo $j
		shuf -i 1-10000000 -n $i > /tmp/andrew_test.txt
		measure  ./lsort -m $j -n  < /tmp/andrew_test.txt > /dev/null
	done
done
