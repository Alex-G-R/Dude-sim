#ifndef GAME_H
#define GAME_H

#include "../FRSGUI/FRSGUI.hpp"
#include "Player.h"

class Game {
public:
        Game(int w_width, int w_height, fr::FRSGUI& FRSGUI);
        int W_WIDTH;
        int W_HEIGHT;

        Player player;

        void start(fr::FRSGUI& FRSGUI);

        void styleSheet(fr::FRSGUI& FRSGUI);

        void createStartScene(fr::FRSGUI& FRSGUI);
        void showStartScene(fr::FRSGUI &FRSGUI);
        void hideStartScene(fr::FRSGUI &FRSGUI);

        void createCharacterCreationScene(fr::FRSGUI& FRSGUI);
        void showCharacterCreationScene(fr::FRSGUI &FRSGUI);
        void hideCharacterCreationScene(fr::FRSGUI &FRSGUI);


        ~Game();

private:


};



#endif //GAME_H
