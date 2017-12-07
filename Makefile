all: main.c
	gcc -o semaphoria main.c

run: all
	./semaphoria -c 4
	./semaphoria -v
	./semaphoria -c 3
	./semaphoria -v
	./semaphoria -r
