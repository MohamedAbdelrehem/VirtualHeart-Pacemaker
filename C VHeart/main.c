#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matlabRead.h"
#include "nodeTable.h"

int main()
{
    int numberofnodes = 0;
    int numberofnodesPathes = 0;

    // node table
    readMatlabCSV("D:/github/VirtualHeart&Pacemaker/cases/EP_AVNRT/node_table.csv", &numberofnodes);
    // print nodeTable to check
    printNodeTable(&numberofnodes);
    // path table
    // readMatlabCSV("D:/github/VirtualHeart&Pacemaker/cases/EP_AVNRT/path_table.csv", &numberofnodesPathes);

    return 0;
}
