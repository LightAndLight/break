CC=clang++
FLAGS=-std=c++11
LINK=-lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=paddle.o game.o main.o
HEADERS=paddle.h game.h

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
