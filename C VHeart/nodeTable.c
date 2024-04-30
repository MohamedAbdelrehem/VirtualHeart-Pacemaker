#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./dataStructure.h"
#include "./nodeTable.h"

node_def nodeTable[100];

void saveToNodeStruct(char *token, const int columnNo, const int rowNo)
{
    // printf("rowNo: %d, columnNo: %d, token: %s\n", rowNo, columnNo, token);
    switch (columnNo)
    {
    case 0:
        strcpy(nodeTable[rowNo].node_name, token);
        break;
    case 1:
        nodeTable[rowNo].node_state_index = atoi(token);
        break;
    case 2:
        nodeTable[rowNo].TERP_current = atoi(token);
        break;
    case 3:
        nodeTable[rowNo].TERP_default = atoi(token);
        break;
    case 4:
        nodeTable[rowNo].TRRP_current = atoi(token);
        break;
    case 5:
        nodeTable[rowNo].TRRP_default = atoi(token);
        break;
    case 6:
        nodeTable[rowNo].TREST_current = atoi(token);
        break;
    case 7:
        nodeTable[rowNo].TREST_default = atoi(token);
        break;
    case 8:
        nodeTable[rowNo].activation = atoi(token);
        break;
    case 9:
        // sscanf take value from token and store it in nodeTable[rowNo].TERP_bounds[0] and nodeTable[rowNo].TERP_bounds[1] based on the format in 2nd argument
        sscanf(token, "[%d, %d]", &nodeTable[rowNo].TERP_bounds[0], &nodeTable[rowNo].TERP_bounds[1]);
        break;

    case 10:
        nodeTable[rowNo].index_of_path_activate_the_node = atoi(token);
        break;
    case 11:
        nodeTable[rowNo].AV_node = atoi(token);
        break;
    default:
        break;
    }
}

void printNodeTable(const int *const numberofnodes)
{
    for (int i = 0; i < *numberofnodes; i++)
    {
        printf("node_name: %s\n", nodeTable[i].node_name);
        printf("node_state_index: %d\n", nodeTable[i].node_state_index);
        printf("TERP_current: %d\n", nodeTable[i].TERP_current);
        printf("TERP_default: %d\n", nodeTable[i].TERP_default);
        printf("TRRP_current: %d\n", nodeTable[i].TRRP_current);
        printf("TRRP_default: %d\n", nodeTable[i].TRRP_default);
        printf("TREST_current: %d\n", nodeTable[i].TREST_current);
        printf("TREST_default: %d\n", nodeTable[i].TREST_default);
        printf("activation: %d\n", nodeTable[i].activation);
        printf("TERP_bounds: [%d, %d]\n", nodeTable[i].TERP_bounds[0], nodeTable[i].TERP_bounds[1]);
        printf("index_of_path_activate_the_node: %d\n", nodeTable[i].index_of_path_activate_the_node);
        printf("AV_node: %d\n", nodeTable[i].AV_node);
        printf("\n");
    }
}