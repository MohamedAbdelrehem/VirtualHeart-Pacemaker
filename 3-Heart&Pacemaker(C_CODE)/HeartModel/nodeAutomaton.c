#include "nodeAutomaton.h"

void node_automaton(node_def *node, int path_ind[], int size_path, int term_ind[], node_path *path)
{
    bool temp_act = false;
    float random_fraction = (float)rand() / TMP_MAX;

    if ((*node).activation == true)
    {
        int temp[2] = {(*node).TERP_bounds[0], (*node).TERP_bounds[1]};
        switch ((*node).node_state_index)
        {
        case 1:
            (*node).TERP_default = temp[1];
            (*node).TERP_current = (*node).TERP_default + round((random_fraction - 0.5) * 0 * (*node).TERP_default);
            for (int i = 0; i < size_path; i++)
            {
                // entry node ==1, Exit node ==0
                if (term_ind[i] == 1)
                {
                    path[path_ind[i]].forward_timer_default = round((1 + (random_fraction - 0.5) * 0) * (path[path_ind[i]].path_length / path[path_ind[i]].forward_speed));
                }
                else
                {
                    path[path_ind[i]].backward_timer_default = round((1 + (random_fraction - 0.5) * 0) * (path[path_ind[i]].path_length / path[path_ind[i]].backward_speed));
                }
            }
            (*node).TREST_current = round((*node).TREST_default * (1 + (random_fraction - 0.5) * 0));
            (*node).node_state_index = 2;
            break;
        case 2:
            (*node).TERP_default = temp[0];
            for (int i = 0; i < size_path; i++)
            {
                if (term_ind[i] == 1)
                {
                    path[path_ind[i]].forward_timer_default = round((1 + (random_fraction - 0.5) * 0) * (path[path_ind[i]].path_length / path[path_ind[i]].forward_speed) * ((*node).AV_node + 1));
                }
                else
                {
                    path[path_ind[i]].backward_timer_default = round((1 + (random_fraction - 0.5) * 0) * (path[path_ind[i]].path_length / path[path_ind[i]].backward_speed) * 3);
                }
            }
            (*node).TERP_current = round((1 + (random_fraction - 0.5) * 0 * (*node).TERP_default));
            break;
        case 3:
        {
            float ratioe = (*node).TRRP_current / (*node).TRRP_default;
            if ((*node).AV_node == 1)
            {
                (*node).TERP_default = temp[1] + round((1 + (random_fraction - 0.5) * 0) * (1 - pow((1 - ratioe), 3)) * (temp[0] - temp[1]));
            }
            else
            {
                (*node).TERP_default = temp[0] + round((1 + (random_fraction - 0.5) * 0) * (1 - pow(ratioe, 3)) * (temp[1] - temp[0]));
            }
            (*node).TERP_current = round((1 + (random_fraction - 0.5) * 0 * (*node).TERP_default));
            for (int i = 0; i < size_path; i++)
            {
                if ((*node).AV_node == 1)
                {
                    if (term_ind[i] == 1)
                    {
                        path[path_ind[i]].forward_timer_default = round((1 + (random_fraction - 0.5) * 0) * (path[path_ind[i]].path_length / path[path_ind[i]].forward_speed) * (1 + (ratioe * 3)));
                    }
                    else
                    {
                        path[path_ind[i]].backward_timer_default = round((1 + (random_fraction - 0.5) * 0) * (path[path_ind[i]].path_length / path[path_ind[i]].backward_speed) * (1 + (ratioe * 3)));
                    }
                }
                else
                {
                    if (term_ind[i] == 1)
                    {
                        path[path_ind[i]].forward_timer_default = round((1 + (random_fraction - 0.5) * 0) * (path[path_ind[i]].path_length / path[path_ind[i]].forward_speed) * (1 + (pow(ratioe, 2) * 3)));
                    }
                    else
                    {
                        path[path_ind[i]].backward_timer_default = round((1 + (random_fraction - 0.5) * 0) * (path[path_ind[i]].path_length / path[path_ind[i]].backward_speed) * (1 + (pow(ratioe, 2) * 3)));
                    }
                }
            }
            (*node).TRRP_current = round((1 + (random_fraction - 0.5) * 0 * (*node).TRRP_default));
            (*node).node_state_index = 2;
            break;
        }
        }
    }
    else
    {
        switch ((*node).node_state_index)
        {
        case 1:
            if ((*node).TREST_current == 0)
            {
                (*node).node_state_index = 2;
                (*node).TREST_current = round((1 + (random_fraction - 0.5) * 0) * (*node).TREST_default);
                temp_act = true;
            }
            else
            {
                (*node).TREST_current--;
            }
            break;
        case 2:
            if ((*node).TERP_current == 0)
            {
                (*node).node_state_index = 3;
                (*node).TERP_current = round((1 + (random_fraction - 0.5) * 0) * (*node).TERP_default);
            }
            else
            {
                (*node).TERP_current--;
            }
            break;
        case 3:
            if ((*node).TRRP_current == 0)
            {
                (*node).node_state_index = 1;
                (*node).TRRP_current = round((1 + (random_fraction - 0.5) * 0) * (*node).TRRP_default);
            }
            else
            {
                (*node).TRRP_current--;
            }
            break;
        }
    }

    //    node_def temp;
    //    temp = (*node);
    (*node).activation = temp_act;
}