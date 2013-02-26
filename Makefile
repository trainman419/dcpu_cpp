#CFLAGS=-save-temps
#CXXFLAGS=-save-temps

all: test

dcpu: dcpu.o

test: dcpu test.img
	./dcpu test.img

.PHONY: test
