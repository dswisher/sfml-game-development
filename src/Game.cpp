
#include "Game.h"

Game::Game()
    : m_window(sf::VideoMode({1920u, 1080u}), "SFML Application")
{
    m_window.setFramerateLimit(144);

    m_player.setRadius(40.f);
    m_player.setPosition({100.f, 100.f});
    m_player.setFillColor(sf::Color::Cyan);
}


void Game::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}


void Game::processEvents()
{
    while (const std::optional event = m_window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            m_window.close();
        }
    }
}


void Game::update()
{
}


void Game::render()
{
    m_window.clear();
    m_window.draw(m_player);
    m_window.display();
}
