
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
        // decrement by 1
        nodeTable[rowNo].index_of_path_activate_the_node--;
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

    printf("Table of nodes:\n\n");
    for (int i = 0; i < *numberofnodes; i++)
    {
        printf("node_name: %-5s\t", nodeTable[i].node_name);
        printf("node_state_index: %-4d\t", nodeTable[i].node_state_index);
        printf("TERP_current: %-4d\t", nodeTable[i].TERP_current);
        printf("TERP_default: %-4d\t", nodeTable[i].TERP_default);
        printf("TRRP_current: %-4d\t", nodeTable[i].TRRP_current);
        printf("TRRP_default: %-4d\t", nodeTable[i].TRRP_default);
        printf("TREST_current: %-4d\t", nodeTable[i].TREST_current);
        printf("TREST_default: %-4d\t", nodeTable[i].TREST_default);
        printf("activation: %-3d\t", nodeTable[i].activation);
        printf("TERP_bounds: [%-4d, %-4d]\t", nodeTable[i].TERP_bounds[0], nodeTable[i].TERP_bounds[1]);
        printf("index_of_path_activate_the_node: %-4d\t", nodeTable[i].index_of_path_activate_the_node);
        printf("AV_node: %-4d\t", nodeTable[i].AV_node);
        printf("\n");
    }
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}