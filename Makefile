CC=clang++
FLAGS=-std=c++11
LINK=-lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=ball.o paddle.o game.o main.o
HEADERS=ball.h paddle.h game.h

all: break

clean:
	rm break

test:
	echo ""

$(OBJECTS): %.o: src/%.cpp $(addprefix src/,$(HEADERS))
	$(CC) $(FLAGS) -c $<

break: $(OBJECTS)
	$(CC) $(FLAGS) -o break $(LINK) $(OBJECTS) && \
	rm $(OBJECTS)
