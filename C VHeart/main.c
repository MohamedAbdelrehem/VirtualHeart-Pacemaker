#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matlabRead.h"
#include "nodeTable.h"
#include "nodePath.h"
#include "dataStructure.h"

//^ @MohamedAbdelrehem to @ahhassan88 : I have added the following variables as extern to be able to use them in the main file globally
extern node_def nodeTable[100];
extern node_path nodePathtable[100];

void main()
{
    // number of nodes and pathes that will be read from the csv files
    int numberofnodes = 0;
    int numberofnodesPathes = 0;
    // function pointer to be passed to the readMatlabCSV function and used to save the data to the nodeTable and nodePathTable (ANA GAMMED :D)
    void (*saveToStructFPointer)(char *, const int, const int);

    //~ Node Table Initialization
    saveToStructFPointer = &saveToNodeStruct;
    readMatlabCSV("D:/github/VirtualHeart&Pacemaker/cases/EP_AVNRT/node_table.csv", &numberofnodes, saveToStructFPointer);
    //? print nodeTable to check
    //?printNodeTable(&numberofnodes);

    //**--------------------------------------------------------------------------------**//

    //~ Path Table Initialization
    saveToStructFPointer = &saveToNodePathStruct;
    readMatlabCSV("D:/github/VirtualHeart&Pacemaker/cases/EP_AVNRT/path_table.csv", &numberofnodesPathes, saveToStructFPointer);
    //? print nodeTable to check
    //?printNodePathTable(&numberofnodesPathes);
    //**--------------------------------------------------------------------------------**//

    while (1)
    {
        /* code */
    }
}

// This is a simple typing club like CLI-program which is written in C using the ncurses library and it's under development right now.