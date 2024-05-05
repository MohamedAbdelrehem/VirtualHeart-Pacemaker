
#ifndef TERMINALUI_H
#define TERMINALUI_H

#include <stdio.h>
#include <string.h>
// used to get if the key hit while printing the data
#include <conio.h> /* getch() and kbhit() */
#include <stdbool.h>
#include <stdlib.h>

#include "./../../HeartCSVRead/nodes/nodePath.h"
#include "./../../HeartCSVRead/nodes/nodeTable.h"
#include "./../../HeartCSVRead/nodes/nodePosition.h"
#include "./../../HeartCSVRead/nodes/nodePathLoaction.h"
#include "./../../HeartCSVRead/probe/probeTable.h"

#include "./../../HeartModel/heartModel.h"
#include "./../../HeartCSVRead/dataStructure.h"

void printData(void);
void menu(void);

#endif // TERMINALUI_H