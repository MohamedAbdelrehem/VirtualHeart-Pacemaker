#ifndef STURCTURES_H_INCLUDED
#define STURCTURES_H_INCLUDED


typedef struct Node{
 char node_name[10];
 int node_state_index;
 int TERP_current;
 int TERP_default;
 int TRRP_current;
 int TRRP_default;
 int TREST_current;
 int TREST_default;
 bool activation;
 int TERP_bounds[2];
 int index_of_path_activate_the_node;
 int AV_node;

}node_def;

typedef struct Path{
char path_name[10];
int path_state_index;
int entry_node_index;
int exit_node_index;
int amplitude_factor;
float forward_speed;
float backward_speed;
int forward_timer_current;//
int forward_timer_default;
int backward_timer_current;
int backward_timer_default;
float path_length;
float path_slope;
}path_def;



#endif // STURCTURES_H_INCLUDED