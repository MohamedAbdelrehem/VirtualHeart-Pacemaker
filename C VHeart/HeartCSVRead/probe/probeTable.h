#ifndef PROBETABLE_H
#define PROBETABLE_H

#include "./../dataStructure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saveToProbeStruct(char *token, const int columnNo, const int rowNo);
void printProbeTable(const int *const numberofprobes);

#endif
