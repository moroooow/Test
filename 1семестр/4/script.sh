#!/bin/bash

echo -n "Enter strings count: "
read stringsCount
echo -n "Enter filename: "
read fileName

Counter=0

while read line && [ $Counter -lt $stringsCount ]
do
	((Counter++));
	echo "$line"
done < "$fileName"
