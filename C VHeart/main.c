// TODO : use pointer to struct to pass the data to the functions instead of passing the struct itself to save memory

#include "./Settings.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./HeartCSVRead/constants.h"
#include "./HeartCSVRead/dataStructure.h"
#include "./HeartCSVRead/matlabRead/matlabRead.h"
#include "./HeartCSVRead/nodes/nodePath.h"
#include "./HeartCSVRead/nodes/nodeTable.h"
#include "./HeartCSVRead/nodes/nodePosition.h"
#include "./HeartCSVRead/nodes/nodePathLoaction.h"

#if UION
// include the SDL2 library
#include "./UI/SDL/MYsdlWindow.h"
#else
#include "./UI/Terminal/TerminalUI.h"
#endif

extern node_def nodeTable[100];

// number of nodes and pathes that will be read from the csv files
int numberofnodes = 0;
int numberofnodesPathes = 0;
int numberofnodesLocation = 0;

// to check if the window is initialized or not

// will run in main file to initialize the window with int argc, char *argv[]
int main(int argc, char *argv[])
{

  // function pointer to be passed to the readMatlabCSV function and used to
  // save the data to the nodeTable and nodePathTable (ANA GAMMED :D)
  void (*saveToStructFPointer)(char *, const int, const int);

  //~ Node Table Initialization
  saveToStructFPointer = &saveToNodeStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/node_table.csv",
                &numberofnodes, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodeTable(&numberofnodes);

  //**--------------------------------------------------------------------------------**//

  //~ Path Table Initialization
  saveToStructFPointer = &saveToNodePathStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/path_table.csv",
                &numberofnodesPathes, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodePathTable(&numberofnodesPathes);
  //**--------------------------------------------------------------------------------**//

  //~ node location table initialization
  saveToStructFPointer = &saveToNodeLocationStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/node_pos.csv",
                &numberofnodesLocation, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodeLocationTable(&numberofnodesLocation);

  //~node path table cordination initialization
  saveToNodePathLocationStruct(&numberofnodesPathes);
#if UION
  //**--------------------------------------------------------------------------------**//
  //~ UI
  mainUI();
#endif
  //**--------------------------------------------------------------------------------**//

#if !UION
  //* print the node table and path table to check without the SDL
  printData();

#endif
  return 0;
}
