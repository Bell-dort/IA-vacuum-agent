//
// Created by Bell on 28/09/2022.
//
#include "../header/Includes.h"

int main()
{
    Environnement env;
    std::thread envThread(&Environnement::run, env);

    envThread.join();

}
