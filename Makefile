CC=clang++
FLAGS=-std=c++11
LINK=-lsfml-graphics -lsfml-window -lsfml-system

all: break

run: break
	./break

clean:
	rm break src/*.o

src/main.o: src/main.cpp
	cd src; \
	$(CC) $(FLAGS) -c main.cpp; \
	cd ../ \

break: src/main.o
	$(CC) $(FLAGS) -o break $(LINK) src/main.o
