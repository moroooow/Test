#!/bin/bash
compileAndTest()
{
	echo "-----------------"
	echo $1
	gcc $1 $2 -o $3 -lm
	time ./$3
	du -h $3
	rm $3
}
compileAndTest -O0 $1 test0
compileAndTest -Os $1 tests
compileAndTest -O1 $1 test1
compileAndTest -O2 $1 test2
compileAndTest -O3 $1 test3
compileAndTest "-O2 -march=native" $1 test2mn
compileAndTest "-O3 -march=native" $1 test3mn
compileAndTest "-O2 -march=native -funroll-loops" $1 test2mnfl
compileAndTest "-O3 -march=native -funroll-loops" $1 test3mnfl
