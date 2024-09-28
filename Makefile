TARGET = executable

all: $(TARGET)

$(TARGET):main.cpp
	g++ -Iheaders classes/game.cpp classes/database.cpp classes/variables.cpp classes/renderer.cpp classes/collision.cpp classes/shape2D.cpp classes/text.cpp main.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system -o $(TARGET)

run:$(TARGET)
	./$(TARGET)