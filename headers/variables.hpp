#pragma once

namespace GEngine{
    class Variables {
    public:
        Variables();  // Constructor to initialize default values

        // Accessor methods (getters)
        bool isPaused() const;
        bool isGameLost() const;
        int getScore() const;

        // Mutator methods (setters)
        void setPaused(bool state);
        void setGameLost(bool state);
        void addScore(int points);

    private:
        // Private variables
        bool paused;
        bool game_lost;
        int score;
    };
}
