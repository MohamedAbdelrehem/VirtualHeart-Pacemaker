
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./nodes/dataStructure.h"
#include "./matlabRead/matlabRead.h"
#include "./nodes/nodePath.h"
#include "./nodes/nodeTable.h"

#include "constants.h"
// include the SDL2 library
#include "MYsdlWindow.h"

//^ @MohamedAbdelrehem to @ahhassan88 : I have added the following variables as
// extern to be able to use them in the main file globally
extern node_def nodeTable[100];
extern node_path nodePathtable[100];

// number of nodes and pathes that will be read from the csv files
int numberofnodes = 0;
int numberofnodesPathes = 0;

// to check if the window is initialized or not

void printData();

// will run in main file to initialize the window with int argc, char *argv[]
int main(int argc, char *argv[])
{

  // function pointer to be passed to the readMatlabCSV function and used to
  // save the data to the nodeTable and nodePathTable (ANA GAMMED :D)
  void (*saveToStructFPointer)(char *, const int, const int);

  //~ Node Table Initialization
  saveToStructFPointer = &saveToNodeStruct;
  readMatlabCSV("D:/github/VirtualHeart&Pacemaker/2-MatlabToCSVOutput/EP_AVNRT/"
                "node_table.csv",
                &numberofnodes, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodeTable(&numberofnodes);

  //**--------------------------------------------------------------------------------**//

  //~ Path Table Initialization
  saveToStructFPointer = &saveToNodePathStruct;
  readMatlabCSV("D:/github/VirtualHeart&Pacemaker/2-MatlabToCSVOutput/EP_AVNRT/"
                "path_table.csv",
                &numberofnodesPathes, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodePathTable(&numberofnodesPathes);
  //**--------------------------------------------------------------------------------**//

  // //~ node location table initialization
  // saveToStructFPointer = &saveToNodeLocationStruct;
  // readMatlabCSV("D:/github/VirtualHeart&Pacemaker/2-MatlabToCSVOutput/EP_AVNRT/"
  //               "node_pos.csv",
  //               &numberofnodes, saveToStructFPointer);
  // //? print nodeTable to check
  // //? printNodeTable(&numberofnodes);

  //**--------------------------------------------------------------------------------**//
  //~ UI
  UI();
  //**--------------------------------------------------------------------------------**//

  //* print the node table and path table to check without the SDL
  // printData();
  return 0;
}

void printData()
{
  system("cls");
  while (1)
  {

    printNodeTable(&numberofnodes);
    printNodePathTable(&numberofnodesPathes);
    //
    printf("\033[0;0H");
  }
}