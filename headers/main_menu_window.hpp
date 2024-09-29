#pragma once
#include "scene_manager.hpp"
class MainMenuWindow {
public:
    MainMenuWindow(
        Renderer& renderer,
        Variables& variables,
        Shape2D& shape,
        Text& text,
        Collision& collision,
        Database& db,
        SoundManager& soundManager,
        CurrentState& currentState
    );
    void run();
};