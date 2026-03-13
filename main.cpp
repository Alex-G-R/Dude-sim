#include <iostream>
#include "FRSGUI/FRSGUI.hpp"

int main()
{
    /* Initialize SFML redner window, create a pointer to window */
    constexpr int W_WIDTH = 800;
    constexpr int W_HEIGHT = 600;
    const auto WINDOW = std::make_shared<sf::RenderWindow>(sf::VideoMode({W_WIDTH, W_HEIGHT}), "Dude-sim");

    /* init FRSGUI */
    fr::FRSGUI FRSGUI(WINDOW);


    /* SFML render loop */
    while (WINDOW->isOpen())
    {
        /* Pool events, if event = close, break the loop if any other pass it to the FRSGUI to handle*/
        while (const std::optional<sf::Event> event = WINDOW->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                WINDOW->close();
                break;
            }
            FRSGUI.dispatchEvent(event);
        }
        WINDOW->clear();

        /* rendering */



        /* Render GUI by FRSGUI */
        FRSGUI.Render();
        /* SFML display function */
        WINDOW->display();
    }


    return 0;
}