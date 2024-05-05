#include "./TerminalUI.h"

extern node_def nodeTable[100];
extern node_path nodePathtable[100];
extern probe_def probeTable[100];

// number of nodes and pathes used to print the data
extern int numberofnodes;
extern int numberofnodesPathes;
extern int numberofnodesLocation;
extern int numberofprobes;

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
        // cyan color
        printf("\033[36m");

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
        case '5':
            printProbeTable(&numberofprobes);
            break;
        case '6':
            printf("Trest current: %d\n", nodeTable[0].TREST_current);
            break;
        case 'q':
        case 'Q':
        case 27:    // ASCII code for escape key
            return; // Exit the function
        default:
            // red color
            printf("\033[31m");
            printf("\nInvalid choice. Please try again.\n");
            printf("\033[0m");
        }
        if (kbhit())
        {
            choice = getch();
            system("cls");
        }
        //? to print the data in the same place by moving the cursor to the top left
        printf("\033[0;0H");

        //~ Heart model function to update the node_table and path_table
        heart_model(nodeTable, numberofnodes, nodePathtable, numberofnodesPathes);
    }
}

void menu(void)
{
    // make the text red and blinking
    printf("\033[31m");
    printf("\033[5m");
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

    printf("\033[0m");
    printf("1. Print Node Table\n");
    printf("2. Print Node Path Table\n");
    printf("3. Print Node Location Table\n");
    printf("4. Print Node Path Location Table\n");
    printf("5. Print Probe Table\n");
    printf("6. Print Trest current in real time\n");
    printf("q. Quit\n");
}
