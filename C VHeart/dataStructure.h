#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
typedef struct Node
{
    char node_name[10];
    int node_state_index;
    int TERP_current;  // suggestion using unsigned short
    int TERP_default;  // unsigned short
    int TRRP_current;  // unsigned short
    int TRRP_default;  // unsigned short
    int TREST_current; // unsigned short
    int TREST_default; // unsigned short
    int activation;
    int TERP_bounds[2];                  // unsigned short
    int index_of_path_activate_the_node; // unsigned short
    int AV_node;                         // suggestion using enum with two values

} node_def;

// array of node_def
node_def node_table[100];

#endif // DATASTRUCTURE_H