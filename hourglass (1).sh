#!/bin/bash
 
 
#Принимаем число
echo -n "Введите нечетное число: "
read x
 
#Определяем четное или не четное
ex=$(expr $x % 2)
if [ $ex == "0" ]
then
  # число четное
	echo "Нужно ввести не чётное число";
else
  # число не чётное, выводим треугольник
 
  # первый цикл для вывода каждой строки
	for (( i=0; i < $x ; i++ ))
	do
   # цикл, для вывода нужного кол-ва отступов
		for (( s=$i; s > 0; s-- ))
		do
		#ставимотступ (еслинужен)
			echo -n " "
		done
 
		# цикл для отрисовки звездочек по одной
		space=$(expr $x - $i)
		for (( a=$space; a > 0; a-- ))
		do
		#рисуем звездочку
			echo -n "* "
		done
		#ставим перенос строки
		echo ""
	done
	
	#второй треугольник
	n = 1 
	for (( i=2; i <= $x ; i++ ))
	do
		# цикл, для вывода нужного кол-ва отступов
		space=$(expr $x - $i)
		for (( s=$space; s > 0; s-- ))
		do
			#ставим отступ (если нужен)
			echo -n " "
		done
		
		if [ s=$(expr $space + 1) ] 
		then
			echo "* "
			
		
		else
			echo " "
		fi
		
		
	done
	
fi

