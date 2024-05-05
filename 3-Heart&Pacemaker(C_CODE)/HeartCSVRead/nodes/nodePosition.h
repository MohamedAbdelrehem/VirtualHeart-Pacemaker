#ifndef NODEPOSITION_H_
#define NODEPOSITION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dataStructure.h"

void saveToNodeLocationStruct(char *token, const int columnNo, const int rowNo);
void printNodeLocationTable(const int *const numberofnodes);

#endif // NODEPOSITION_H_