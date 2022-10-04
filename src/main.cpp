//
// Created by Bell on 28/09/2022.
//
#include "../header/Includes.h"

int main()
{
    Environment env;
    Square** desireSquares = Square::emptySquares(5, 5);
    VacuumAgent vacuumAgent(&env, 1, 1, desireSquares);

    std::thread envThread(&Environment::run, &env);
    env.getSquares()[0][0].addDust();
    env.getSquares()[0][0].addJewel();
    std::thread vacuumAgentThread(&VacuumAgent::run, &vacuumAgent);

    envThread.join();

}
