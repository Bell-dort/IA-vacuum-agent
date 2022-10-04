//
// Created by Bell on 28/09/2022.
//
#include "../header/Includes.h"

int main()
{
    Environment env;
    VacuumAgent vacuumAgent(&env);

    std::thread envThread(&Environment::run, env);
    std::thread vacuumAgentThread(&VacuumAgent::run, vacuumAgent);

    envThread.join();

}
