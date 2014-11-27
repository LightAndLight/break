CC=clang++
FLAGS=-std=c++11
LINK=-lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=bounded.o ball.o paddle.o game.o main.o
HEADERS=bounded.h ball.h paddle.h game.h

all: break

clean:
	rm break *.o

test:
	echo ""

$(OBJECTS): %.o: src/%.cpp $(addprefix src/,$(HEADERS))
	$(CC) $(FLAGS) -c $<

break: $(OBJECTS)
	$(CC) $(FLAGS) -o break $(LINK) $(OBJECTS)
