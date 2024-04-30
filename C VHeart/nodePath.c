#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dataStructure.h"
#include "nodePath.h"

node_path nodePathtable[100];

void saveToNodePathStruct(char *token, const int columnNo, const int rowNo)
{
    // printf("rowNo: %d, columnNo: %d, token: %s\n", rowNo, columnNo, token);
    switch (columnNo)
    {
    case 0:
        strcpy(nodePathtable[rowNo].path_name, token);
        break;
    case 1:
        nodePathtable[rowNo].path_state_index = atoi(token);
        break;
    case 2:
        nodePathtable[rowNo].entry_node_index = atoi(token);
        break;
    case 3:
        nodePathtable[rowNo].exit_node_index = atoi(token);
        break;
    case 4:
        nodePathtable[rowNo].amplitude_factor = atoi(token);
        break;
    case 5:
        nodePathtable[rowNo].forward_speed = atof(token);
        break;
    case 6:
        nodePathtable[rowNo].backward_speed = atof(token);
        break;
    case 7:
        nodePathtable[rowNo].forward_timer_current = atoi(token);
        break;
    case 8:
        nodePathtable[rowNo].forward_timer_default = atoi(token);
        break;
    case 9:
        nodePathtable[rowNo].backward_timer_current = atoi(token);
        break;
    case 10:
        nodePathtable[rowNo].backward_timer_default = atoi(token);
        break;
    case 11:
        nodePathtable[rowNo].path_length = atof(token);
        break;
    case 12:
        nodePathtable[rowNo].path_slope = atof(token);
        break;
    default:
        break;
    }
}

// print nodepath struct
void printNodePathTable(const int *const numberofnodes)
{
    for (int i = 0; i < *numberofnodes; i++)
    {
        printf("path_name: %s\n", nodePathtable[i].path_name);
        printf("path_state_index: %d\n", nodePathtable[i].path_state_index);
        printf("entry_node_index: %d\n", nodePathtable[i].entry_node_index);
        printf("exit_node_index: %d\n", nodePathtable[i].exit_node_index);
        printf("amplitude_factor: %d\n", nodePathtable[i].amplitude_factor);
        printf("forward_speed: %f\n", nodePathtable[i].forward_speed);
        printf("backward_speed: %f\n", nodePathtable[i].backward_speed);
        printf("forward_timer_current: %d\n", nodePathtable[i].forward_timer_current);
        printf("forward_timer_default: %d\n", nodePathtable[i].forward_timer_default);
        printf("backward_timer_current: %d\n", nodePathtable[i].backward_timer_current);
        printf("backward_timer_default: %d\n", nodePathtable[i].backward_timer_default);
        printf("path_length: %f\n", nodePathtable[i].path_length);
        printf("path_slope: %f\n", nodePathtable[i].path_slope);
        printf("\n");
        }
}