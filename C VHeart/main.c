#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matlabRead.h"
#include "nodeTable.h"
int main()
{
    int numberofnodes = 0;

    readMatlabCSV("D:/github/VirtualHeart&Pacemaker/cases/EP_AVNRT/node_table.csv", &numberofnodes);
    // print node_table to check
    printNodeTable(&numberofnodes);

    return 0;
}
