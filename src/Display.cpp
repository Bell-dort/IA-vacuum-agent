//
// Created by Bell on 30/09/2022.
//

#include "../header/Display.h"
void Display::consoleRender(Environnement env) {
    int envHeight = env.getHeight();
    int envWidth= env.getWidth();
    Square** envSquares = env.getSquares();
    std::string tempLine("");

    for (int i(0); i < envHeight; i++) {
        tempLine += "|";
        for (int j = 0; j < envWidth; ++j) {
            tempLine += "D:" + std::to_string(envSquares[i][j].getNbDust()) + " J:" + std::to_string(envSquares[i][j].getNbJewel()) + "|";
        }
        std::cout << tempLine << std::endl;
        tempLine = "";
    }
}