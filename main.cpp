#include <iostream>
#include "FRSGUI/FRSGUI.hpp"

int main()
{
    /* Initialize SFML redner window, create a pointer to window */
    constexpr int W_WIDTH = 800;
    constexpr int W_HEIGHT = 600;
    const auto WINDOW = std::make_shared<sf::RenderWindow>(
        sf::VideoMode({W_WIDTH, W_HEIGHT}),
        "Dude-sim | Alex Grabski"
        );

    /* init FRSGUI */
    fr::FRSGUI FRSGUI(WINDOW);


    /* Welcome text and start button */
    const auto banner = fr::UIElement::Builder(&FRSGUI)
    .setID("Banner")
    .addGroups({"Banner_main", "scene_one"})
    .setText("Dude-sim")
    .buildUIElement();
    // Create style
    auto banner_main_style = Style("Banner_main", fr::ApplyBy::GROUP, 1, {
            {fr::KEY::POSITION, sf::Vector2f(W_WIDTH/2 - W_WIDTH/2 , 0.f)},
            {fr::KEY::SIZE, sf::Vector2f(W_WIDTH, W_HEIGHT/12)},
            {fr::KEY::BACKGROUND_COLOR, sf::Color{255, 255, 255, 255}},
            {fr::KEY::CHARACTER_SIZE, 36},
            {fr::KEY::TEXT_COLOR, sf::Color::Black}
    }, FRSGUI);


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