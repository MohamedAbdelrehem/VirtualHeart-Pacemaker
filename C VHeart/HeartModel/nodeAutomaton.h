#ifndef NODE_AUTOMATON_H_INCLUDED
#define NODE_AUTOMATON_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "./../HeartCSVRead/dataStructure.h"

void node_automaton(node_def *node, int path_ind[], int size_path, int term_ind[], node_path *path);

#endif // NODE_AUTOMATON_H_INCLUDED
