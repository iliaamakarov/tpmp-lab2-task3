# Makefile

build: src/main.c
	gcc src/main.c -o executable

clean:
	del $(wildcard *.exe)
