#ifndef HEART_MODEL_H_INCLUDED
#define HEART_MODEL_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include<math.h>
#include "node_automaton.h"
#include "path_automaton.h"

void heart_model(node_def *node_table ,int size_node_table, path *path_table,int size_path_table){

node_def temp_node[size_node_table];
path temp_path[size_path_table];

path temp_path_node[size_path_table];
int totalsize = sizeof(temp_path_node);
memcpy(&temp_path_node,path_table,totalsize);
int path_ind[20]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int term_ind;
int count_size;
bool temp_act[size_node_table];
int index_difference_entry;
int index_difference_exit;
int index_difference_path_activate_node;
for(int i=0;i<size_node_table;i++){
        count_size=0;
        index_difference_path_activate_node = node_table[i].index_of_path_activate_the_node-1;
    for(int j=0;j<size_path_table,j++){
                  index_difference_entry =     path[j].entry_node_index-1;
                      index_difference_exit =     path[j].exit_node_index-1;

            if(index_difference_path_activate_node != j){
              if(path[j].entry_node_index == i){
                path_ind[j]= j;
                term_ind[j]=1;

                }
            if(path[j].exit_node_index == i){
                path_ind[j]= j;
                term_ind[j]=2;

            }

            }

    }
    for(int m=0;m<=20;m++){
        if(path_ind[m]==-1){
            break;
        }else{
        count_size++;
        }
    }
    node_table[i].index_of_path_activate_the_node = -1;
    temp_node[i] = node_automaton(temp_node[i],path_ind,count_size,term_ind,temp_path_node);
    temp_act[i]= node_table[i].activation;

}
bool *node_act;
for(int i=0;i<=size_path_table;i++){
                        index_difference_entry =   path[i].entry_node_index-1;
                      index_difference_exit =   path[i].exit_node_index-1;

    *node_act = path_automaton(path_table[i],node_table[index_difference_entry].activation,node_table[index_difference_exit].activation);
temp_path[i] = path_table[i];
    if(node_table[path_table[i].entry_node_index].node_state_index !=2){
            temp_act[index_difference_entry] = temp_act[index_difference_entry] || node_act[0];
            if(node_act[0]== true){
                temp_node[index_difference_entry].index_of_path_activate_the_node=  i;
            }

    }else{
        temp_act[index_difference_entry] = false;
        node_table[index_difference_entry].TERP_current = node_table[index_difference_entry].TERP_default;
    }
        if(node_table[index_difference_exit].node_state_index !=2){
            temp_act[index_difference_exit] = temp_act[index_difference_exit] || node_act[1];
            if(node_act[1]== true){
                temp_node[index_difference_exit].index_of_path_activate_the_node=  i;
            }

    }else{
        temp_act[index_difference_exit] = false;
        node_table[index_difference_exit].TERP_current = node_table[index_difference_exit].TERP_default;
    }

}
for(int i=0;i<size_node_table;i++){
    node_table[i]= temp_node[i];
    node_table[i].activation = temp_act[i];
    node_table[i].index_of_path_activate_the_node++;

}
///////i will try to put some count inside the loop to count the number it enters the if then i can know size of array
// and i can try it in path_ind above too
int ind[20];
int count_size_2=0;

for(int i=0;i<size_path_table;i++){
    if(temp_path_node[i].forward_timer_default != temp_path[i].forward_timer_default){
        ind[i]=i;
        count_size_2++;
    }
}

for (int i=0;i<count_size_2,i++){
    temp_path[ind[i]].forward_timer_default = temp_path_node[ind[i]].forward_timer_default;
    if(temp_path_node[ind[i]].path_state_index ==1){
        temp_path[ind[i]].forward_timer_current = temp_path[ind[i]].forward_timer_default;
    }
}
count_size_2=0;
for(int i=0;i<size_path_table;i++){
    if(temp_path_node[i].backward_timer_default != temp_path[i].backward_timer_default){
        ind[i]=i;
        count_size_2++;
    }
}
for (int i=0;i<count_size_2,i++){
    temp_path[ind[i]].backward_timer_default = temp_path_node[ind[i]].backward_timer_default;
    if(temp_path_node[ind[i]].path_state_index ==1){
        temp_path[ind[i]].backward_timer_current = temp_path[ind[i]].backward_timer_default;
    }
}


}


#endif // HEART_MODEL_H_INCLUDED
