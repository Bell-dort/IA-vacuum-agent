//
// Created by Bell on 04/10/2022.
//

#include "../header/Actuators.h"

Actuators::Actuators(Environment *environment, int* vacPosX, int* vacPosY) : pEnv(environment), pVacuumPosX(vacPosX), pVacuumPosY(vacPosY) {
}

void Actuators::moveRight() {
    if (*pVacuumPosX < pEnv->getWidth()) {
        *pVacuumPosX = *pVacuumPosX + 1;
    }
}

void Actuators::moveLeft() {
    if (*pVacuumPosX > 0) {
        (*pVacuumPosX)--;
    }
}

void Actuators::moveDown() {
    if (*pVacuumPosY < pEnv->getHeight()) {
        (*pVacuumPosY)++;
    }
}

void Actuators::moveUp() {
    if (*pVacuumPosY > 0) {
        (*pVacuumPosY)--;
    }
}

void Actuators::pickUpJewel() {
    pEnv->getSquares()[*pVacuumPosX, *pVacuumPosY]->pickUpJewels();
    // TODO score perf ?
}

void Actuators::cleanSquare() {
    pEnv->getSquares()[*pVacuumPosX, *pVacuumPosY]->cleanDust();
    // TODO score perf ?
}