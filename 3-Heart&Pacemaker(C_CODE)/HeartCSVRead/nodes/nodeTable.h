#ifndef NODETABLE_H_
#define NODETABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../dataStructure.h"

void saveToNodeStruct(char *token, const int columnNo, const int rowNo);
void printNodeTable(const int *const numberofnodes);
#endif // NODETABLE_H_