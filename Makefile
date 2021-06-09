build:
	gcc -Wall -std=c99 ./src/*.c -o 

run:
	./game

clean:
	rm game	