TARGET = executable

all: $(TARGET)

$(TARGET):main.cpp
	g++ -Iheaders classes/renderer.cpp classes/shape.cpp classes/text.cpp main.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system -o $(TARGET)

run:$(TARGET)
	./$(TARGET)