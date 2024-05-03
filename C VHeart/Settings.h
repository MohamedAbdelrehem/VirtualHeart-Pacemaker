/*this file contains the settings of the application*/
/*Makefile have the following command to compile and run the application with the UI feature enabled:
/*      make buildUI
/*      make buildNoUI
*/
#define TRUE 1
#define FALSE 0

#ifndef SETTINGS_H
#define SETTINGS_H

// This macro represents the state of the UI.
// When UION is set to TRUE, it indicates that the UI feature is enabled.
//&use "make buildUI" with TRUE
// When UION is set to FALSE, it indicates that the UI feature is disabled and terminal tables.
//&use "make buildNoUI" with FALSE
#define UION FALSE

// This macro represents the state of the screen size.
// When SCREENSIZE is set to 0, it indicates that the screen size is 1024x720.
// When SCREENSIZE is set to 1, it indicates that the screen size is 1500x900.
// When SCREENSIZE is set to 2, it indicates that the screen size is 1920x1080.
#define SCREENSIZE 2

#endif // SETTINGS_H