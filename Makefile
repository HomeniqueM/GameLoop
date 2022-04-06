build:
	gcc -Wall -std=c99 ./src/*.c -lSDL2 -lX11 -lXrandr -o game

run: build
	./game

clean:
	rm game	