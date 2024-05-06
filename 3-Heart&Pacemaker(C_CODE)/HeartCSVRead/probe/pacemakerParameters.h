#ifndef PACEMAKERPARAMETERS_H
#define PACEMAKERPARAMETERS_H

#include "./../dataStructure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saveToPacemakerParametersStruct(char *token, const int columnNo, const int rowNo);
void printPacemakerParametersTable(const int *const numberofpacemaker);

#endif // PACEMAKERPARAMETERS_H