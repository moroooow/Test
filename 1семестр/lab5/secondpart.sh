#!/bin/bash
compileAndTest()
{
	echo "--------------"
	echo "-O3 -march=native "$1
	gcc -O3 -march=native$1 $2 -o $3
	time ./$3
	du -h $3
	rm $3
}
compileAndTest " -fipa-profile -flto" $1 test1
compileAndTest " -fipa-pure-const -flto" $1 test2
compileAndTest " -fipa-reference -flto" $1 test3
compileAndTest " -fipa-reference-addressable -flto" $1 test4
compileAndTest " -fprofile-generate" $1 test5
compileAndTest " -fprofile-use" $1 test5
compileAndTest " -fipa-profile -flto -fprofile-generate" $1 test6
compileAndTest " -fipa-profile -flto -fprofile-use" $1 test6

