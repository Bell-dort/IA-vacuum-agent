//
// Created by Bell on 28/09/2022.
//
#include "../header/Includes.h"

int main()
{
    Environment env(0.5);
    Square** desireSquares = Square::emptySquares(5, 5);
    std::thread envThread(&Environment::run, &env);

    VacuumAgent vacuumAgent(&env, 2, 2, desireSquares, 0.8);
    std::thread vacuumAgentThread(&VacuumAgent::run, &vacuumAgent);

    Display display(&env, &vacuumAgent, 1);
    std::thread displayThread(&Display::run, &display);

    envThread.join();
    vacuumAgentThread.join();
    displayThread.join();

    return 0;
}
