// TODO : use pointer to struct to pass the data to the functions instead of passing the struct itself to save memory

#include "./Settings.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constants
#include "./HeartCSVRead/constants.h"
// data structure
#include "./HeartCSVRead/dataStructure.h"
// read csv files
#include "./HeartCSVRead/matlabRead/matlabRead.h"
// nodes and pathes
#include "./HeartCSVRead/nodes/nodePath.h"
#include "./HeartCSVRead/nodes/nodeTable.h"
#include "./HeartCSVRead/nodes/nodePosition.h"
#include "./HeartCSVRead/nodes/nodePathLoaction.h"
// pacemaker
#include "./HeartCSVRead/probe/pacemakerParameters.h"
#include "./HeartCSVRead/probe/probeTable.h"
#include "./HeartCSVRead/probe/probePosition.h"

#if UION
// include the SDL2 library
#include "./UI/SDL/MYsdlWindow.h"
#else
#include "./UI/Terminal/TerminalUI.h"
#endif

// number of nodes and pathes that will be read from the csv files
int numberofnodes = 0;
int numberofnodesPathes = 0;
int numberofnodesLocation = 0;
int numberofpacemaker = 0;
int numberofprobes = 0;
int numberofprobesPosition = 0;

// to check if the window is initialized or not

// will run in main file to initialize the window with int argc, char *argv[]
int main(int argc, char *argv[])
{
  // system("clear");
  // function pointer to be passed to the readMatlabCSV function and used to
  // save the data to the nodeTable and nodePathTable (ANA GAMMED :D)
  void (*saveToStructFPointer)(char *, const int, const int);

  //&&----------------------------------* Virtual Heart *-----------------------------------------&&//

  //^^--------------------------------------* Nodes *---------------------------------------------^^//

  //**------------------------------------* Node Table *------------------------------------------**//
  //~ Node Table Initialization
  saveToStructFPointer = &saveToNodeStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/node_table.csv",
                &numberofnodes, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodeTable(&numberofnodes);
  //**--------------------------------* Node Location Table *-------------------------------------**//

  //~ node location table initialization
  saveToStructFPointer = &saveToNodeLocationStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/node_pos.csv",
                &numberofnodesLocation, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodeLocationTable(&numberofnodesLocation);

  //^^--------------------------------------* Pathes *---------------------------------------------^^//
  //**----------------------------------* Node Path Table *----------------------------------------**//

  //~ Path Table Initialization
  saveToStructFPointer = &saveToNodePathStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/path_table.csv",
                &numberofnodesPathes, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodePathTable(&numberofnodesPathes);
  //**--------------------------------* Node Path Location Table *--------------------------------**//

  //~node path table cordination initialization
  saveToNodePathLocationStruct(&numberofnodesPathes);
  //? print nodeTable to check
  //? printNodePathLocationTable(&numberofnodesPathes);

  //&&---------------------------------------* PACEMAKER *----------------------------------------&&//
  //^^---------------------------------------* parameters *---------------------------------------^^//
  //**----------------------------------* Pacemaker Parameters *----------------------------------**//

  //~pacemaker parameters initialization
  saveToStructFPointer = &saveToPacemakerParametersStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/pace_para.csv",
                &numberofpacemaker, saveToStructFPointer);

  //? print nodeTable to check
  //? printPacemakerParametersTable(&numberofpacemaker);

  //^^-----------------------------------------* Probes *-----------------------------------------^^//
  //**---------------------------------------* Probe Table *---------------------------------------**//

  //~probe table initialization
  saveToStructFPointer = &saveToProbeStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/probe_table.csv",
                &numberofprobes, saveToStructFPointer);

  //? print nodeTable to check
  //?printProbeTable(&numberofprobes);

  //**-------------------------------------* Probe Position *--------------------------------------**//

  //~probe position initialization
  saveToStructFPointer = &saveToProbePositionStruct;
  readMatlabCSV("./../2-MatlabToCSVOutput/EP_AVNRT/probe_pos.csv",
                &numberofprobesPosition, saveToStructFPointer);

  printf("Number of Probes: %d\n", numberofprobesPosition);
  //? print nodeTable to check
  //? printProbePositionTable(&numberofprobesPosition);

  //&&-------------------------------------------* UI *----------------------------------------------&&//
#if UION
  //~ UI
  mainUI();
#else
  //* print without the SDL
  printData();
#endif
  //**-----------------------------------------* The End *-------------------------------------------**//
  return 0;
}
