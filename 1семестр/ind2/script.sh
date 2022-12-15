#!/bin/bash
N=$1
posL=2
posR=$[$N * 2 - $posL - 1]

for(( i=1; i <= $[$N * 2 - 1]; i++ ))
do
	if [ $i -eq 1 ]  || [ $i -eq $[$N * 2 - 1] ]
	then
		for(( j=1; j <= $N; j++ ))
		do
			echo -n '* '
		done
		echo ' '
	elif [ $i == $N ]
	then
		for(( j=1; j <= $[$N - 1]; j++ ))
		do
			echo -n ' '
		done
		echo '*'
		posL=$[$N - 1]
		posR=$N
	else
		for(( j=1; j <= $[$posL - 1]; j++ ))
		do
			echo -n ' '
		done
		echo -n '*'
		for(( j=1; j <= $[$posR - $posL]; j++ ))
		do
			echo -n ' '
		done
		echo '*'
		if [ $i -gt $N ]
		then
			posL=$[$posL - 1]
			posR=$[$posR + 1]
		else
			posL=$[$posL + 1]
			posR=$[$posR - 1]
		fi
	fi
done
