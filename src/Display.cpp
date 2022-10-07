//
// Created by Bell on 30/09/2022.
//

#include "../header/Display.h"
Display::Display(Environment *env, VacuumAgent *vacuum, float frequency): pEnv(env), pVacuum(vacuum), m_frequency(frequency) {}

void Display::run() {
    while (1) {
        consoleRender();
        sleep(1/m_frequency);
    }
}

void Display::consoleRender() {
    int envHeight = pEnv->getHeight();
    int envWidth= pEnv->getHeight();
    Square** envSquares = pEnv->getSquares();
    std::string tempLine("");

    std::cout << std::endl;
    for (int i(0); i < envHeight; i++) {
        tempLine += "|";
        for (int j = 0; j < envWidth; ++j) {
            if (pVacuum->isPosition(j, i)) {
                tempLine += "*";
            } else {
                tempLine += " ";
            }
            tempLine +=  "D:" + std::to_string(envSquares[j][i].getNbDust()) + " J:" + std::to_string(envSquares[j][i].getNbJewel()) + "|";
        }
        std::cout << tempLine << std::endl;
        tempLine = "";
    }
    std::cout << std::endl;

}