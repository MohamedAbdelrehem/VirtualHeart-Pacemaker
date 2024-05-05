
#ifndef PROBEPOSITION_H
#define PROBEPOSITION_H

#include "./../dataStructure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saveToProbePositionStruct(char *token, const int columnNo, const int rowNo);
void printProbePositionTable(const int *const numberofprobes);

#endif // PROBEPOSITION_H