#ifndef GAME_H
#define GAME_H

#include "../FRSGUI/FRSGUI.hpp"


class Game {
public:
        Game(int w_width, int w_height, fr::FRSGUI& FRSGUI);
        int W_WIDTH;
        int W_HEIGHT;

        void start(fr::FRSGUI& FRSGUI);

        void styleSheet(fr::FRSGUI& FRSGUI);
        void createStartScene(fr::FRSGUI& FRSGUI);

        void showStartScene(fr::FRSGUI &FRSGUI);
        void hideStartScene(fr::FRSGUI &FRSGUI);


        ~Game();

private:


};



#endif //GAME_H
