# generated by ~/michael.trigoboff/bin/creat_makefile.py

# C++ compiler flags
include ~michael.trigoboff/bin/makeflags_g++

asgmt03:	stock.o date.o hashmap.o hashmap.h

stock.o:	stock.h

date.o:		date.h

hashmap.o:	hashmap.h

.PHONY: x
x:			# clean the directory
			rm -f *.o asgmt03
