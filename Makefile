TARGET = executable

all: $(TARGET)

$(TARGET):main.cpp
	g++ -Iheaders classes/main_menu_window.cpp classes/scene_manager.cpp classes/database.cpp classes/variables.cpp classes/renderer.cpp classes/sound_manager.cpp classes/game.cpp classes/collision.cpp classes/shape2D.cpp classes/text.cpp main.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -o $(TARGET)

run:$(TARGET)
	./$(TARGET)