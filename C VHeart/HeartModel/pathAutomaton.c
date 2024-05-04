#include "pathAutomaton.h"

bool *path_automaton(node_path *path, bool node_act_1, bool node_act_2)
{
    static bool temp_act[2];
    temp_act[0] = false;
    temp_act[1] = false;

    switch ((*path).path_state_index)
    {
    case 1:
        if (node_act_1 == true)
        {
            (*path).path_state_index = 2;
        }
        else if (node_act_2 == true)
        {
            (*path).path_state_index = 3;
        }
        break;
    case 2:
        if (node_act_2 == true)
        {
            (*path).path_state_index = 5;
        }
        else
        {
            if ((*path).forward_timer_current == 0)
            {
                (*path).forward_timer_current = (*path).forward_timer_default;
                temp_act[1] = true;
                (*path).path_state_index = 4;
            }
            else
            {
                (*path).forward_timer_current--;
            }
        }
        break;
    case 3:
        if (node_act_1 == true)
        {
            (*path).path_state_index = 5;
        }
        else
        {
            if ((*path).backward_timer_current == 0)
            {
                (*path).backward_timer_current = (*path).backward_timer_default;
                temp_act[0] = true;
                (*path).path_state_index = 4;
            }
            else
            {
                (*path).backward_timer_current--;
            }
        }
        break;
    case 4:
        (*path).path_state_index = 1;
        break;
    case 5:
        if ((*path).backward_timer_current == 0)
        {
            (*path).backward_timer_current = (*path).backward_timer_default;
            temp_act[0] = true;
            (*path).path_state_index = 4;
            return temp_act;
        }
        if ((*path).forward_timer_current == 0)
        {
            (*path).forward_timer_current = (*path).forward_timer_default;
            temp_act[1] = true;
            (*path).path_state_index = 4;
            return temp_act;
        }
        float calc1 = abs(1 - ((*path).forward_timer_current / (*path).forward_timer_default) - ((*path).backward_timer_current / (*path).backward_timer_default));
        float calc2 = 0.9 / fmin((*path).forward_timer_default, (*path).backward_timer_default);
        if (calc1 < calc2)
        {
            (*path).backward_timer_current = (*path).backward_timer_default;
            (*path).forward_timer_current = (*path).forward_timer_default;
            (*path).path_state_index = 4;
        }
        else
        {
            (*path).forward_timer_current--;
            (*path).backward_timer_current--;
        }
        break;
    }
    return temp_act;
}