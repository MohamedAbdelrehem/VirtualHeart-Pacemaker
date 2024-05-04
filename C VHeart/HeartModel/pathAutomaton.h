#ifndef PATH_AUTOMATON_H_INCLUDED
#define PATH_AUTOMATON_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "./../HeartCSVRead/dataStructure.h"

bool *path_automaton(node_path *path, bool node_act_1, bool node_act_2);

#endif // PATH_AUTOMATON_H_INCLUDED
