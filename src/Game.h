#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>


class Game {
public:
    Game();
    void run();

private:
    static const float PlayerSpeed;
    static const sf::Time TimePerFrame;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow m_window;
    sf::CircleShape m_player;

    bool m_isMovingUp = false;
    bool m_isMovingDown = false;
    bool m_isMovingLeft = false;
    bool m_isMovingRight = false;
};

#endif //GAME_H
