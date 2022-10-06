//
// Created by Bell on 04/10/2022.
//

#ifndef IA_VACUUM_AGENT_ACTION_H
#define IA_VACUUM_AGENT_ACTION_H
namespace Actions {
    enum Action {
        RIGHT,
        LEFT,
        UP,
        DOWN,
        PICK,
        CLEAN
    };

    static const Action All[] = {RIGHT, LEFT, UP, DOWN, PICK, CLEAN};
}


#endif //IA_VACUUM_AGENT_ACTION_H
