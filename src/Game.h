#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>


class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    sf::CircleShape m_player;
};

#endif //GAME_H
