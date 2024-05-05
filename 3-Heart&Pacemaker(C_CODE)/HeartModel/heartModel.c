#include "heartModel.h"

/**
 * @brief This function is used to model the heart by using the node and path automaton
 *
 * @param node_table
 * @param size_node_table
 * @param path_table
 * @param size_path_table
 */
void heart_model(node_def *node_table, int size_node_table, node_path *path_table, int size_path_table)
{

    node_def temp_node[size_node_table];
    node_path temp_path[size_path_table];
    node_path temp_path_node[size_path_table];
    int totalsize = sizeof(temp_path_node);
    // memcpy is used to copy the content of one structure to another
    memcpy(&temp_path_node, path_table, totalsize);
    memcpy(&temp_path, path_table, totalsize);
    int path_ind[size_path_table];
    int term_ind[size_path_table];
    int count_j;
    bool temp_act[size_node_table];

    for (int i = 0; i < size_node_table; i++)
    {

        count_j = 0;

        for (int j = 0; j < size_path_table; j++)
        {

            if (node_table[i].index_of_path_activate_the_node != j)
            {
                if (path_table[j].entry_node_index == i)
                {
                    path_ind[count_j] = j;
                    term_ind[count_j] = 1;

                    count_j++;
                }

                if (path_table[j].exit_node_index == i)
                {
                    path_ind[count_j] = j;
                    term_ind[count_j] = 2;
                    count_j++;
                }
            }
        }

        node_table[i].index_of_path_activate_the_node = -1;

        temp_node[i] = node_table[i];

        node_automaton(&temp_node[i], path_ind, count_j, term_ind, temp_path_node);

        temp_act[i] = temp_node[i].activation;
    }

    bool *node_act;

    for (int i = 0; i < size_path_table; i++)
    {

        node_act = path_automaton(&temp_path[i], node_table[path_table[i].entry_node_index].activation, node_table[path_table[i].exit_node_index].activation);
        if (node_table[path_table[i].entry_node_index].node_state_index != 2)
        {

            temp_act[path_table[i].entry_node_index] = temp_act[path_table[i].entry_node_index] || node_act[0];
            if (node_act[0] == true)
            {

                temp_node[path_table[i].entry_node_index].index_of_path_activate_the_node = i;
            }
        }
        else
        {

            temp_act[path_table[i].entry_node_index] = false;
            node_table[path_table[i].entry_node_index].TERP_current = node_table[path_table[i].entry_node_index].TERP_default;
        }

        if (node_table[path_table[i].exit_node_index].node_state_index != 2)
        {

            temp_act[path_table[i].exit_node_index] = temp_act[path_table[i].exit_node_index] || node_act[1];
            if (node_act[1] == true)
            {

                temp_node[path_table[i].exit_node_index].index_of_path_activate_the_node = i;
            }
        }
        else
        {

            temp_act[path_table[i].exit_node_index] = false;
            node_table[path_table[i].exit_node_index].TERP_current = node_table[path_table[i].exit_node_index].TERP_default;
        }
    }

    for (int i = 0; i < size_node_table; i++)
    {
        node_table[i] = temp_node[i];
        node_table[i].activation = temp_act[i];
    }

    for (int i = 0; i < size_path_table; i++)
    {
        if (temp_path_node[i].forward_timer_default != temp_path[i].forward_timer_default)
        {
            temp_path[i].forward_timer_default = temp_path_node[i].forward_timer_default;
            if (temp_path_node[i].path_state_index == 1)
            {
                temp_path[i].forward_timer_current = temp_path[i].forward_timer_default;
            }
        }
        if (temp_path_node[i].backward_timer_default != temp_path[i].backward_timer_default)
        {
            temp_path[i].backward_timer_default = temp_path_node[i].backward_timer_default;
            if (temp_path_node[i].path_state_index == 1)
            {
                temp_path[i].backward_timer_current = temp_path[i].backward_timer_default;
            }
        }
    }

    for (int i = 0; i < size_path_table; i++)
    {

        path_table[i] = temp_path[i];
    }
}
