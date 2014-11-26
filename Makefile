CC=clang++
FLAGS=-std=c++11
LINK=-lsfml-graphics -lsfml-window -lsfml-system
OBJECTS=game.o main.o
HEADERS=game.h

all: break

clean:
	rm break

$(OBJECTS): %.o: src/%.cpp src/$(HEADERS)
	$(CC) $(FLAGS) -c $<; \

break: $(OBJECTS)
	$(CC) $(FLAGS) -o break $(LINK) $(OBJECTS)
	rm $(OBJECTS)
