//
// Created by Bell on 04/10/2022.
//

#include "../header/Actuators.h"

Actuators::Actuators(Environment *environment) : env(environment) {}

void Actuators::moveRight() {
    int vacuumX = env->getVacuumX();

    if (vacuumX < env->getWidth()) {
        env->setVacuumX( vacuumX + 1);
    }
}

void Actuators::moveLeft() {
    int vacuumX = env->getVacuumX();

    if (vacuumX > 0) {
        env->setVacuumX(vacuumX - 1).
    }
}

void Actuators::moveDown() {
    int vacuumY = env->getVacuumY();

    if (vacuumY < env->getHeight()) {
        env->setVacuumY(vacuumY + 1);
    }
}

void Actuators::moveUp() {
    int vacuumY = env->getVacuumY();

    if (vacuumY > 0) {
        env->setVacuumY(vacuumY - 1);
    }
}

void Actuators::pickUpJewel() {
    env->getSquares()[env->getVacuumX(), env->getVacuumY()]->pickUpJewels();
    // TODO score perf ?
}

void Actuators::cleanSquare() {
    env->getSquares()[env->getVacuumX(), env->getVacuumY()]->cleanDust();
    // TODO score perf ?
}