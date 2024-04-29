#ifndef HEART_MODEL_H_INCLUDED
#define HEART_MODEL_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "node_automaton.h"
#include "path_automaton.h"

void heart_model(node_def *nodeTable, int size_node_table, path *path_table, int size_path_table)
{

    node_def temp_node;
    path temp_path;

    path temp_path_node[size_path_table];
    int totalsize = sizeof(temp_path_node);
    memcpy(&temp_path_node, path_table, totalsize);
    int path_ind[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int term_ind;
    for (int i = 0; i < size_node_table; i++)
    {
        for (int j = 0; j < size_path_table, j++)
        {
            if (no)
                if (path[j].entry_node_index == ++i)
                {
                    path_ind[j] = j;
                    term_ind[j] = 1;
                }
            if (path[j].exit_node_index == ++i)
            {
                path_ind[j] = j;
                term_ind[j] = 1;
            }
        }
    }
}

#endif // HEART_MODEL_H_INCLUDED
