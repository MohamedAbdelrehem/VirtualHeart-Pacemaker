#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./dataStructure.h"
#include "./nodeTable.h"

void saveToNodeStruct(char *token, const int columnNo, const int rowNo)
{
    // printf("rowNo: %d, columnNo: %d, token: %s\n", rowNo, columnNo, token);
    switch (columnNo)
    {
    case 0:
        strcpy(node_table[rowNo].node_name, token);
        break;
    case 1:
        node_table[rowNo].node_state_index = atoi(token);
        break;
    case 2:
        node_table[rowNo].TERP_current = atoi(token);
        break;
    case 3:
        node_table[rowNo].TERP_default = atoi(token);
        break;
    case 4:
        node_table[rowNo].TRRP_current = atoi(token);
        break;
    case 5:
        node_table[rowNo].TRRP_default = atoi(token);
        break;
    case 6:
        node_table[rowNo].TREST_current = atoi(token);
        break;
    case 7:
        node_table[rowNo].TREST_default = atoi(token);
        break;
    case 8:
        node_table[rowNo].activation = atoi(token);
        break;
    case 9:
        // sscanf take value from token and store it in node_table[rowNo].TERP_bounds[0] and node_table[rowNo].TERP_bounds[1] based on the format in 2nd argument
        sscanf(token, "[%d, %d]", &node_table[rowNo].TERP_bounds[0], &node_table[rowNo].TERP_bounds[1]);
        break;

    case 10:
        node_table[rowNo].index_of_path_activate_the_node = atoi(token);
        break;
    case 11:
        node_table[rowNo].AV_node = atoi(token);
        break;
    default:
        break;
    }
}

void printNodeTable(const int *const numberofnodes)
{
    for (int i = 0; i < *numberofnodes; i++)
    {
        printf("node_name: %s\n", node_table[i].node_name);
        printf("node_state_index: %d\n", node_table[i].node_state_index);
        printf("TERP_current: %d\n", node_table[i].TERP_current);
        printf("TERP_default: %d\n", node_table[i].TERP_default);
        printf("TRRP_current: %d\n", node_table[i].TRRP_current);
        printf("TRRP_default: %d\n", node_table[i].TRRP_default);
        printf("TREST_current: %d\n", node_table[i].TREST_current);
        printf("TREST_default: %d\n", node_table[i].TREST_default);
        printf("activation: %d\n", node_table[i].activation);
        printf("TERP_bounds: [%d, %d]\n", node_table[i].TERP_bounds[0], node_table[i].TERP_bounds[1]);
        printf("index_of_path_activate_the_node: %d\n", node_table[i].index_of_path_activate_the_node);
        printf("AV_node: %d\n", node_table[i].AV_node);
        printf("\n");
    }
}