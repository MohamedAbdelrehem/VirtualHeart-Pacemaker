#ifndef NodePath_H_
#define NodePath_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dataStructure.h"

void saveToNodePathStruct(char *token, const int columnNo, const int rowNo);
void printNodePathTable(const int *const numberofnodes);

#endif // NodePath_H_