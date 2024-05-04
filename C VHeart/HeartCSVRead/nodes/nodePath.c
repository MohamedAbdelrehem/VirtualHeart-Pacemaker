#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dataStructure.h"
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
    printf("Table of nodes Path:\n\n");
    for (int i = 0; i < *numberofnodes; i++)
    {
        printf("path_name: %-5s\t", nodePathtable[i].path_name);
        printf("path_state_index: %d\t", nodePathtable[i].path_state_index);
        printf("entry_node_index: %d\t", nodePathtable[i].entry_node_index);
        printf("exit_node_index: %d\t", nodePathtable[i].exit_node_index);
        printf("amplitude_factor: %d\t", nodePathtable[i].amplitude_factor);
        printf("forward_speed: %0.2f\t", nodePathtable[i].forward_speed);
        printf("backward_speed: %0.2f\t", nodePathtable[i].backward_speed);
        printf("forward_timer_current: %d\t", nodePathtable[i].forward_timer_current);
        printf("forward_timer_default: %d\t", nodePathtable[i].forward_timer_default);
        printf("backward_timer_current: %d\t", nodePathtable[i].backward_timer_current);
        printf("backward_timer_default: %d\t", nodePathtable[i].backward_timer_default);
        printf("path_length: %0.2f\t", nodePathtable[i].path_length);
        printf("path_slope: %0.2f\t", nodePathtable[i].path_slope);
        printf("\n");
    }
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}