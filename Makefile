TARGET = executable

all: $(TARGET)

$(TARGET):main.cpp
	g++ -Iheaders classes/draw_shape.cpp main.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system -o $(TARGET)

run:$(TARGET)
	./$(TARGET)