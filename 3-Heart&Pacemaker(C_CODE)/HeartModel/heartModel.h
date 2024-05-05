#ifndef HEART_MODEL_H_INCLUDED
#define HEART_MODEL_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "./nodeAutomaton.h"
#include "./pathAutomaton.h"
#include "./../HeartCSVRead/dataStructure.h"

void heart_model(node_def *node_table, int size_node_table, node_path *path_table, int size_path_table);

#endif // HEART_MODEL_H_INCLUDED
