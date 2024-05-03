#include "./nodePathLoaction.h"

node_path_location nodePathLocationTable[100];
extern node_path nodePathtable[100];
extern node_location nodeLocationTable[100];

void printNodePathLocationTable(const int *const numberofnodesPathes)
{
    // print path location table
    printf("Table of nodes Path Location:\n\n");

    for (int i = 0; i < *numberofnodesPathes; i++)
    {
        printf("entry_x: %f\t", nodePathLocationTable[i].entry_x);
        printf("entry_y: %f\t", nodePathLocationTable[i].entry_y);
        printf("exit_x: %f\t", nodePathLocationTable[i].exit_x);
        printf("exit_y: %f\n", nodePathLocationTable[i].exit_y);
    }
}

void saveToNodePathLocationStruct(const int *const numberofnodesPathes)
{ // use node nodepath to get entry and exit node index and use index from nodeLocationTable to get the x and y of the node that will be used to draw the line and save it using node_path_location struct
    for (int i = 0; i < *numberofnodesPathes; i++)
    {
        int entryIndex = nodePathtable[i].entry_node_index - 1;
        int exitIndex = nodePathtable[i].exit_node_index - 1;
        nodePathLocationTable[i].entry_x = nodeLocationTable[entryIndex].x;
        nodePathLocationTable[i].entry_y = nodeLocationTable[entryIndex].y;
        nodePathLocationTable[i].exit_x = nodeLocationTable[exitIndex].x;
        nodePathLocationTable[i].exit_y = nodeLocationTable[exitIndex].y;
    }
}