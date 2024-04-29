#ifndef STURCTURES_H_INCLUDED
#define STURCTURES_H_INCLUDED


typedef struct Node{
 char node_name[10];
 int node_state_index;//suggestion  using enum with three values
 int TERP_current;//suggestion using unsigned short
 int TERP_default;//unsigned short
 int TRRP_current;//unsigned short
 int TRRP_default;//unsigned short
 int TREST_current;//unsigned short
 int TREST_default;//unsigned short
 bool activation;
 int TERP_bounds[2];//unsigned short
 int index_of_path_activate_the_node;//unsigned short
 int AV_node;//suggestion using enum with two values

}node_def;

typedef struct Path{//same suggestion as above mostly all of the int can be  short and path_state_index can be enum
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
}path;



#endif // STURCTURES_H_INCLUDED
