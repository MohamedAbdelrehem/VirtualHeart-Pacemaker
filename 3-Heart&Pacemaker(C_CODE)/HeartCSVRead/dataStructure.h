#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

//^^--------------------------------------* Nodes *-----------------------------------------------^^//
//**------------------------------------* Node Table *--------------------------------------------**//
typedef struct Node
{
    char node_name[10];
    int node_state_index;
    int TERP_current;
    int TERP_default;
    int TRRP_current;
    int TRRP_default;
    int TREST_current;
    int TREST_default;
    int activation;
    int TERP_bounds[2];
    int index_of_path_activate_the_node;
    int AV_node;

} node_def;

//**--------------------------------* Node Location Table *--------------------------------------**//
typedef struct NodeLocation
{
    float x;
    float y;
} node_location;
//^^--------------------------------------* Pathes *---------------------------------------------^^//
//**----------------------------------* Node Path Table *----------------------------------------**//
typedef struct Path
{
    char path_name[10];
    int path_state_index;
    int entry_node_index;
    int exit_node_index;
    int amplitude_factor;
    float forward_speed;
    float backward_speed;
    int forward_timer_current;
    int forward_timer_default;
    int backward_timer_current;
    int backward_timer_default;
    float path_length;
    float path_slope;
} node_path;
//**--------------------------------* Node Path Location Table *---------------------------------**//
typedef struct NodePathLocation
{
    float entry_x;
    float entry_y;
    float exit_x;
    float exit_y;
} node_path_location;

//&&---------------------------------------* PACEMAKER *-----------------------------------------&&//

//^^----------------------------------------* Probes *-------------------------------------------^^//
//**---------------------------------* Pacemaker Parameters *------------------------------------**//
typedef struct PacemakerParameters
{
    char name[10];
    float min;
    float max;
    float value;
    float step;
} pacemaker_parameters;

//**--------------------------------------* Probe Table *----------------------------------------**//
typedef struct Probe
{
    char probe_name[10];
    int probe_bounds[10];
} probe_def;

//**--------------------------------------* Probe Position *--------------------------------------**//
typedef struct ProbePosition
{
    float x;
    float y;
} probe_position;
#endif