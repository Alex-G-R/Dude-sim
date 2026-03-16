#include "src/Game.h"

int main()
{
    // Global variables
    constexpr int W_WIDTH = 800;
    constexpr int W_HEIGHT = 600;

    /* init */
    const auto WINDOW = std::make_shared<sf::RenderWindow>(
        sf::VideoMode({W_WIDTH, W_HEIGHT}),
        "Dude-sim | Alex Grabski"
        );
    fr::FRSGUI FRSGUI(WINDOW);
    Game Game(W_WIDTH, W_HEIGHT, FRSGUI);

    Game.startScene(FRSGUI);

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