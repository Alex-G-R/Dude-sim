#include "Game.h"

#include <iostream>

Game::Game(int w_width, int w_height, fr::FRSGUI& FRSGUI)
{
    W_WIDTH = w_width;
    W_HEIGHT = w_height;

    styleSheet(FRSGUI);
}

void Game::styleSheet(fr::FRSGUI &FRSGUI)
{
    // off_scene
    const auto off_scene_style = Style("off_scene", fr::ApplyBy::GROUP, 100, {
        {fr::KEY::POSITION, sf::Vector2f(100.f, 10000.f)}
    }, FRSGUI);

    // button_main
    const auto button_main_style = Style("button_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::SIZE, sf::Vector2f(400.f, 100.f)},
        {fr::KEY::POSITION, sf::Vector2f(W_WIDTH/2 - 400.f/2, 200.f)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color{34,35,26,255}},
        {fr::KEY::CHARACTER_SIZE, 36},
        {fr::KEY::TEXT_COLOR, sf::Color::White},
        {fr::KEY::OUTLINE_THICKNESS, 4.f},
        {fr::KEY::OUTLINE_COLOR, sf::Color{160, 160, 255, 255}},
    }, FRSGUI);

    // banner_main
    auto banner_main_style = Style("banner_main", fr::ApplyBy::GROUP, 1, {
            {fr::KEY::POSITION, sf::Vector2f(0.f , 0.f)},
            {fr::KEY::SIZE, sf::Vector2f(W_WIDTH, W_HEIGHT/12)},
            {fr::KEY::BACKGROUND_COLOR, sf::Color{255, 255, 255, 255}},
            {fr::KEY::CHARACTER_SIZE, 36},
            {fr::KEY::TEXT_COLOR, sf::Color::Black}
    }, FRSGUI);
}


void Game::startScene(fr::FRSGUI &FRSGUI)
{
    // Welcome text
    const auto banner = fr::UIElement::Builder(&FRSGUI)
    .setID("banner")
    .addGroups({"banner_main", "scene_one"})
    .setText("Dude-sim")
    .buildUIElement();

    // start button
    const auto start_game_btn = fr::Button::Builder(&FRSGUI)
    .setID("start_game_btn")
    .addGroup("button_main")
    .setText("Start Game")
    .buildButton();

    // button functionality
    start_game_btn->setOnClick([&FRSGUI]()
    {
        std::cout << "Start Game" << std::endl;
        FRSGUI.getButtonByID("start_game_btn")->addGroup("off_scene");

    });
}

void Game::gameScene(fr::FRSGUI &FRSGUI)
{

}

Game::~Game() = default;


