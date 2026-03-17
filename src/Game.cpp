#include "Game.h"

#include <iostream>

Game::Game(int w_width, int w_height, fr::FRSGUI& FRSGUI)
{
    W_WIDTH = w_width;
    W_HEIGHT = w_height;

    styleSheet(FRSGUI);
}

void Game::start(fr::FRSGUI& FRSGUI)
{
    createStartScene(FRSGUI);
    showStartScene(FRSGUI);
}

void Game::styleSheet(fr::FRSGUI &FRSGUI)
{
    // off_scene
    const auto off_scene_style = Style("off_scene", fr::ApplyBy::GROUP, 100, {
        {fr::KEY::POSITION, sf::Vector2f(100.f, 10000.f)}
    }, FRSGUI);

    // button_main
    const auto button_main_style = Style("button_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::BACKGROUND_COLOR, sf::Color{35,35,25,255}},
        {fr::KEY::TEXT_COLOR, sf::Color::White},
        {fr::KEY::OUTLINE_THICKNESS, 4.f},
        {fr::KEY::OUTLINE_COLOR, sf::Color{135, 135, 135, 255}},
    }, FRSGUI);

    // ID | start_game_button
    auto start_game_button_style = Style("start_game_button", fr::ApplyBy::ID, 1, {
        {fr::KEY::SIZE, sf::Vector2f(400.f, 100.f)},
        {fr::KEY::POSITION, sf::Vector2f(W_WIDTH/2 - 400.f/2, 200.f)},
        {fr::KEY::CHARACTER_SIZE, 36},
    }, FRSGUI);

    // banner_main
    auto banner_main_style = Style("banner_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::POSITION, sf::Vector2f(0.f , 0.f)},
        {fr::KEY::SIZE, sf::Vector2f(W_WIDTH, W_HEIGHT/12)},
        {fr::KEY::BACKGROUND_COLOR, sf::Color{255, 255, 255, 255}},
        {fr::KEY::CHARACTER_SIZE, 36},
        {fr::KEY::TEXT_COLOR, sf::Color::Black}
    }, FRSGUI);

    //input_main
    auto input_main_style = Style("input_main", fr::ApplyBy::GROUP, 1, {
        {fr::KEY::SIZE, sf::Vector2f(300.f, 80.f)},
        {fr::KEY::CHARACTER_SIZE, 36},
        {fr::KEY::TEXT_COLOR, sf::Color::White},
        {fr::KEY::BACKGROUND_COLOR, sf::Color{35,35,25,255}},
        {fr::KEY::OUTLINE_THICKNESS, 2.f},
        {fr::KEY::OUTLINE_COLOR, sf::Color{135, 135, 135, 255}},
        {fr::KEY::CURSOR_COLOR, sf::Color{165,165,165,255}}
    }, FRSGUI);

    // ID | name_input_field
    auto name_input_field_style = Style("name_input_field", fr::ApplyBy::ID, 1, {
        {fr::KEY::POSITION, sf::Vector2f(200.f, 260.f)},
    }, FRSGUI);

    // ID | confirm_button
    auto confirm_button_style = Style("confirm_button", fr::ApplyBy::ID, 2, {
        {fr::KEY::POSITION, sf::Vector2f(500.f, 260.f)},
        {fr::KEY::SIZE, sf::Vector2f(100.f, 80.f)},
        {fr::KEY::OUTLINE_THICKNESS, 2.f},
        {fr::KEY::CHARACTER_SIZE, 18},
    }, FRSGUI);
}

void Game::createStartScene(fr::FRSGUI &FRSGUI)
{
    // Welcome text
    const auto banner = fr::UIElement::Builder(&FRSGUI)
    .setID("banner")
    .addGroups({"banner_main", "off_scene"})
    .setText("Dude-sim")
    .buildUIElement();

    // start button
    const auto start_game_btn = fr::Button::Builder(&FRSGUI)
    .setID("start_game_button")
    .addGroups({"button_main", "off_scene"})
    .setText("Start Game")
    .buildButton();

    // button functionality
    start_game_btn->setOnClick([&FRSGUI, this]()
    {
        std::cout << "Start Game" << std::endl;
        hideStartScene(FRSGUI);

        createCharacterCreationScene(FRSGUI);
        showCharacterCreationScene(FRSGUI);
    });
}

void Game::createCharacterCreationScene(fr::FRSGUI &FRSGUI)
{
    const auto name_input_field = fr::Input::Builder(&FRSGUI)
    .setID("name_input_field")
    .addGroups({"input_main", "off_scene"})
    .isNumericalOnly(false)
    .setText("My name is?")
    .buildInput();

    const auto confirm_button = fr::Button::Builder(&FRSGUI)
    .setID("confirm_button")
    .addGroups({"button_main", "off_scene"})
    .setText("Confirm")
    .buildButton();

    // confirm button functionality
    confirm_button->setOnClick([&FRSGUI, this]()
    {
        std::cout << "Confirm player name" << std::endl;

        this->player.player_name = FRSGUI.getInputByID("name_input_field")->getDataAs<std::string>();
        std::cout << this->player.player_name << std::endl;

        hideCharacterCreationScene(FRSGUI);
    });
}



void Game::showStartScene(fr::FRSGUI &FRSGUI)
{
    FRSGUI.getUIElementByID("banner")->deleteGroup("off_scene");
    FRSGUI.getButtonByID("start_game_button")->deleteGroup("off_scene");
}

void Game::hideStartScene(fr::FRSGUI &FRSGUI)
{
    FRSGUI.getButtonByID("start_game_button")->addGroup("off_scene");
}

void Game::showCharacterCreationScene(fr::FRSGUI &FRSGUI)
{
    FRSGUI.getInputByID("name_input_field")->deleteGroup("off_scene");
    FRSGUI.getButtonByID("confirm_button")->deleteGroup("off_scene");
}

void Game::hideCharacterCreationScene(fr::FRSGUI &FRSGUI)
{
    FRSGUI.getInputByID("name_input_field")->addGroup("off_scene");
    FRSGUI.getButtonByID("confirm_button")->addGroup("off_scene");
}



Game::~Game() = default;


