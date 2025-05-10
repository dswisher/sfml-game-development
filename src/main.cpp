
#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "SFML Application");
    window.setFramerateLimit(144);

    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition({100.f, 100.f});
    shape.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

