#ifndef GAME_H
#define GAME_H

#include "../FRSGUI/FRSGUI.hpp"


class Game {
public:
        Game(int w_width, int w_height, fr::FRSGUI& FRSGUI);
        int W_WIDTH;
        int W_HEIGHT;

        void styleSheet(fr::FRSGUI& FRSGUI);

        void startScene(fr::FRSGUI &FRSGUI);
        void gameScene(fr::FRSGUI &FRSGUI);


        ~Game();

private:


};



#endif //GAME_H
