#include "../Settings.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// used to get if the key hit while printing the data
#include <conio.h> /* getch() and kbhit() */

#include "./dataStructure.h"
#include "./matlabRead/matlabRead.h"
#include "./nodes/nodePath.h"
#include "./nodes/nodeTable.h"
#include "./nodes/nodePosition.h"
#include "./nodes/nodePathLoaction.h"

#include "constants.h"
#if UION
// include the SDL2 library
#include "MYsdlWindow.h"
#endif
//^ @MohamedAbdelrehem to @ahhassan88 : I have added the following variables as
// extern to be able to use them in the main file globally
extern node_def nodeTable[100];
extern node_path nodePathtable[100];
extern node_location nodeLocationTable[100];
extern node_path_location nodePathLocationTable[100];

// number of nodes and pathes that will be read from the csv files
int numberofnodes = 0;
int numberofnodesPathes = 0;
int numberofnodesLocation = 0;

// to check if the window is initialized or not

void printData(void);
void menu(void);
// will run in main file to initialize the window with int argc, char *argv[]
int main(int argc, char *argv[])
{

  // function pointer to be passed to the readMatlabCSV function and used to
  // save the data to the nodeTable and nodePathTable (ANA GAMMED :D)
  void (*saveToStructFPointer)(char *, const int, const int);

  //~ Node Table Initialization
  saveToStructFPointer = &saveToNodeStruct;
  readMatlabCSV("D:/github/VirtualHeart&Pacemaker/2-MatlabToCSVOutput/EP_AVNRT/node_table.csv",
                &numberofnodes, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodeTable(&numberofnodes);

  //**--------------------------------------------------------------------------------**//

  //~ Path Table Initialization
  saveToStructFPointer = &saveToNodePathStruct;
  readMatlabCSV("D:/github/VirtualHeart&Pacemaker/2-MatlabToCSVOutput/EP_AVNRT/path_table.csv",
                &numberofnodesPathes, saveToStructFPointer);
  //? print nodeTable to check
  //? printNodePathTable(&numberofnodesPathes);
  //**--------------------------------------------------------------------------------**//

  //~ node location table initialization
  saveToStructFPointer = &saveToNodeLocationStruct;
  readMatlabCSV("D:/github/VirtualHeart&Pacemaker/2-MatlabToCSVOutput/EP_AVNRT/node_pos.csv",
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

void printData()
{
  system("cls");
  char choice;
  menu();
  printf("Enter your choice: ");

  scanf(" %c", &choice);

  // TODO: take input from the user to print the data with switch case and go back to the main menu when the user press q
  system("cls");
  while (1)
  {
    menu();

    switch (choice)
    {

    case '1':
      printNodeTable(&numberofnodes);
      break;
    case '2':
      printNodePathTable(&numberofnodesPathes);
      break;
    case '3':
      printNodeLocationTable(&numberofnodes);
      break;
    case '4':
      printNodePathLocationTable(&numberofnodesPathes);
      break;
    case 'q':
    case 'Q':
      return; // Exit the function
    default:
      printf("Invalid choice. Please try again.\n");
    }
    if (kbhit())
    {
      choice = getch();
      system("cls");
    }
    //? to print the data in the same place by moving the cursor to the top left
    printf("\033[0;0H");
  }
}

void menu(void)
{
  printf("          |  \\ \\ | |/ /\n");
  printf("          |  |\\ `' ' /\n");
  printf("          |  ;'aorta \\      / , pulmonary\n");
  printf(" superior | |   (  `-.;_,-' '-' ,\n");
  printf("vena cava | `,   `-._       _,-'_\n");
  printf("          |,-`.    `.)    ,<_,-'_, pulmonary\n");
  printf("         ,'    `.   /   ,'  `;-' _,  veins\n");
  printf("        ;        `./   /`,    \\-'\n");
  printf("        | right   /   |  ;\\   |\n");
  printf("        | atrium ;_,._|_,  `, ' \\\n");
  printf("        |        \\    \\ `       `, \n");
  printf("        `      __ `    \\   left  ;,\n");
  printf("         \\   ,'  `      \\,  ventricle\n");
  printf("          \\_(            ;,      ;;\n");
  printf("          |  \\           `;,     ;;\n");
  printf(" inferior |  |`.          `;;,   ;'\n");
  printf("vena cava |  |  `-.        ;;;;,;'\n");
  printf("          |  |    |`-.._  ,;;;;;'\n");
  printf("          |  |    |   | ``';;;'  FL\n");
  printf("                  aorta\n\n");

  printf("** Make sure Terminal is full screen and font size is small** \n\n");

  printf("1. Print Node Table\n");
  printf("2. Print Node Path Table\n");
  printf("3. Print Node Location Table\n");
  printf("4. Print Node Path Location Table\n");
  printf("q. Quit\n");
}