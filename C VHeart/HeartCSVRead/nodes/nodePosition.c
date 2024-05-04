#include "nodePosition.h"

node_location nodeLocationTable[100];

void saveToNodeLocationStruct(char *token, const int columnNo, const int rowNo)
{

    switch (columnNo)
    {
    case 0:
        nodeLocationTable[rowNo].x = atof(token);
        break;
    case 1:
        nodeLocationTable[rowNo].y = atof(token);
        break;
    default:
        break;
    }
}

// print node location struct
void printNodeLocationTable(const int *const numberofnodes)
{

    printf("Table of Node Locations\n\n");
    for (int i = 0; i < *numberofnodes; i++)
    {
        printf("Node %d: x = %.2f, y = %.2f\n", i, nodeLocationTable[i].x, nodeLocationTable[i].y);
    }
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}
