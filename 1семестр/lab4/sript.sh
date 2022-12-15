#!/bin/bash
sumcalc()
{
	res=$(bc<<<"scale=6;$1+$2")
}
minuscalc()
{
	res=$(bc<<<"scale=6;$1-$2")
}
multiplecalc()
{
	res=$(bc<<<"scale=6;$1*$2")
}
dividecalc()
{
if [[ $2 == 0 ]] || [[ $2 == 0.0 ]]
then
	error=1
	echo "Деление на ноль!"
else
	res=$(bc<<<"scale=6;$1/$2")
fi
}
res=$1
shift 1

while [ $# ]
do
if [ "$1" = "x" ] || [ "$1" = "X" ]
then
	multiplecalc $res $2
elif [ "$1" = "+" ]
then
	sumcalc $res $2
elif [ "$1" = "-" ]
then
	minuscalc $res $2
elif [ "$1" = "/" ]
then
	dividecalc $res $2
else
	error=1
	break
fi
shift 2
if [ $# = 0 ]
then
	break
fi
done
if [ "$error" != 1 ]
then
echo "Результат = $res"
else
	echo "Выражение не определено!"
fi


