
#include "Game.h"

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);


Game::Game()
    : m_window(sf::VideoMode({1920u, 1080u}), "SFML Application")
{
    m_player.setRadius(40.f);
    m_player.setPosition({100.f, 100.f});
    m_player.setFillColor(sf::Color::Cyan);
}


void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (m_window.isOpen())
    {
        processEvents();

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

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
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                m_window.close();
            }
            else
            {
                handlePlayerInput(keyPressed->code, true);
            }
        }
        else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
        {
            handlePlayerInput(keyReleased->code, false);
        }
    }
}


void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);

    if (m_isMovingUp)
    {
        movement.y -= PlayerSpeed;
    }
    if (m_isMovingDown)
    {
        movement.y += PlayerSpeed;
    }
    if (m_isMovingLeft)
    {
        movement.x -= PlayerSpeed;
    }
    if (m_isMovingRight)
    {
        movement.x += PlayerSpeed;
    }

    m_player.move(movement * deltaTime.asSeconds());
}


void Game::render()
{
    m_window.clear();
    m_window.draw(m_player);
    m_window.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Key::W)
    {
        m_isMovingUp = isPressed;
    }
    else if (key == sf::Keyboard::Key::S)
    {
        m_isMovingDown = isPressed;
    }
    else if (key == sf::Keyboard::Key::A)
    {
        m_isMovingLeft = isPressed;
    }
    else if (key == sf::Keyboard::Key::D)
    {
        m_isMovingRight = isPressed;
    }
}
