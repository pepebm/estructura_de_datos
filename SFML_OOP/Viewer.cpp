#include "Viewer.h"
#include <iostream>
#include <string>

Viewer::Viewer(std::string window_title, std::string font_name, void (*menu)(std::string *)) : window(sf::VideoMode(800, 600), window_title), menu_thread(menu, &greeting)
{
    // change the position of the window (relatively to the desktop)
    window.setPosition(sf::Vector2i(700, 100));

    // Load the font
    font.loadFromFile(font_name);

    // Prepare all the drawable elements
    configure();

    greeting = "Nothing yet";
}

void Viewer::configure()
{
    // Configure the title object
    title.setFont(font);
    title.setCharacterSize(24);
    title.setColor(sf::Color::Blue);
    title.setPosition(sf::Vector2f(20, 10));

    // Configure the info object
    info.setFont(font);
    info.setCharacterSize(24);
    info.setColor(sf::Color::Green);
    info.setPosition(sf::Vector2f(20, 50));

    // Configure greeting text
    message.setFont(font);
    message.setCharacterSize(30);
    message.setColor(sf::Color::Red);
    message.setPosition(sf::Vector2f(100, 500));

    // Create a circle with a visible edge
    circle.setRadius(100);
    circle.setPointCount(32);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineThickness(20.f);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOrigin(circle.getRadius(), circle.getRadius());

}

void Viewer::windowListener()
{
    menu_thread.launch();

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    std::cout << "Window closed. Exiting the program." << std::endl;
                    exit(0);
                    break;
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::R)
                        circle.setRadius(100);
                    if (event.key.code == sf::Keyboard::Add)
                        speed+=10;
                    if (event.key.code == sf::Keyboard::Subtract)
                        speed-=10;
                    break;
                case sf::Event::MouseWheelMoved:
                    float radius = circle.getRadius();
                    if (event.mouseWheel.delta > 0 && radius < 300)
                    {
                        radius += scale_factor;
                        circle.setRadius(radius);
                    }
                    else if (event.mouseWheel.delta < 0 && radius > 0.5)
                    {
                        radius -= scale_factor;
                        circle.setRadius(radius);
                    }
                    break;
            }
        }

        mainDraw();
    }
}

void Viewer::mainDraw()
{
    // Keep track of the time elapsed since the last frame
    elapsed_time = clock.restart();
    total_time += elapsed_time;

    // Clean the window
    window.clear(sf::Color::White);

    // Draw all the elements
    drawTitle();
    drawAnimatedCircle();

    // Draw everything
    window.display();
}

void Viewer::drawTitle()
{
    // Change the text displayed
    title.setString("Time elapsed: " + std::to_string(total_time.asSeconds()));
    info.setString("Speed: " + std::to_string(speed) + "\nRadius: " + std::to_string(circle.getRadius()));
    message.setString(greeting);

    window.draw(title);
    window.draw(info);
    window.draw(message);
}

void Viewer::drawAnimatedCircle()
{
    // Create a moving animation
    circle.setPosition(sf::Vector2f(x_pos, y_pos));
    x_pos += speed * direction * elapsed_time.asSeconds();
    if (x_pos <= circle.getRadius() || x_pos >= window.getSize().x-circle.getRadius())
    {
        direction = direction * -1;
    }

    window.draw(circle);
}
