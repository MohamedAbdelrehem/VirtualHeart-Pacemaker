
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heart_model.h"
#define NUM_OF_NODES 33
#define NUM_OF_PATHS 34
void delay(float seconds_num){

float milli_seconds = 1000 * seconds_num;
clock_t start_time = clock();
while(clock() < start_time + milli_seconds);

}

int main()
{
////
node_def node_table_test[] = {
        // Row 1
        {"SA",   1,   220, 220,  120,  120,  700, 700,  false, {150, 300}, 0, 2},
        // Row 2
        {"CT",   1,   220, 220, 120, 120, 9999, 9999,  false, {150, 360}, 0, 2},
        // Row 3
        {"AV",   1,   320, 320, 250, 250, 9999, 9999,  false, {350, 230}, 0, 1},
        // Row 4
        {"OS",   1,   320, 320, 120, 120, 9999, 9999,  false, {100, 200}, 0, 2},
        // Row 5
        {"His_p", 1,   320, 320, 120, 120, 9999, 9999,  false, {330, 440}, 0, 2},
        // Row 6
        {"His_m", 1,   320, 320, 120, 120, 9999, 9999,  false, {330, 440}, 0, 2},
        // Row 7
        {"His_d", 1,   320, 320, 120, 120, 9999, 9999,  false, {330, 440}, 0, 2},
        // Row 8
        {"Bach",  1,   320, 320, 120, 120, 9999, 9999,  false, {150, 360}, 0, 2},
        // Row 9
        {"LA_a",  1,   320, 320, 120, 120, 9999, 9999,  false, {150, 360}, 0, 2},
        // Row 10
        {"LA",    1,   320, 320, 120, 120, 9999, 9999,  false, {150, 360}, 0, 2},
        // Row 11
        {"RBB_m", 1,   320, 320, 120, 120, 9999, 9999,  false, {330, 440}, 0, 2},
        // Row 12
        {"RBB",   1,   320, 320, 120, 120, 9999, 9999,  false, {330, 440}, 0, 2},
        // Row 13
        {"LBB_m", 1,   320, 320, 120, 120, 9999, 9999,  false, {330, 440}, 0, 2},
        // Row 14
        {"LBB",   1,   320, 320, 120, 120, 9999, 9999,  false, {330, 440}, 0, 2},
        // Row 15
        {"RVA",   1,   320, 320, 120, 120, 9999, 9999,  false, {180, 290}, 0, 2},
        // Row 16
        {"LVA",   1,   320, 320, 120, 120, 9999, 9999,  false, {180, 290}, 0, 2},
        // Row 17
        {"RV_m",  1,   320, 320, 120, 120, 9999, 9999,  false, {180, 290}, 0, 2},
        // Row 18
        {"RV",    1,   320, 320, 120, 120, 9999, 9999,  false, {180, 290}, 0, 2},
        // Row 19
        {"LV_m",  1,   320, 320, 120, 120, 9999, 9999,  false, {180, 290}, 0, 2},
        // Row 20
        {"LV",    1,   320, 320, 120, 120, 9999, 9999,  false, {180, 290}, 0, 2},
        // Row 21
        {"CT_a",  1,   220, 220, 120, 120, 9999, 9999,  false, {150, 360}, 0, 2},
        // Row 22
        {"RA_a",  1,   320, 320, 120, 120, 9999, 9999,  false, {150, 360}, 0, 2},
        // Row 23
        {"RA",    1,   320, 320, 120, 120, 9999, 9999,  false, {150, 360}, 0, 2},
        // Row 24
        {"SEP_RV_m", 1,  320, 320, 120, 120, 9999, 9999, false, {150, 300}, 0, 2},
        // Row 25
        {"SEP_RV", 1,  320, 320, 120, 120, 9999, 9999, false, {150, 300}, 0, 2},
        // Row 26
        {"SEP_LV_m", 1, 320, 320, 120, 120, 9999, 9999, false, {150, 300}, 0, 2},
        // Row 27
        {"SEP_LV", 1, 320, 320, 120, 120, 9999, 9999, false, {150, 300}, 0, 2},
        // Row 28
        {"CS_LV", 1, 320, 320, 120, 120, 9999, 9999, false, {150, 300}, 0, 2},
        // Row 29
        {"CS_LA", 1, 320, 320, 120, 120, 9999, 9999, false, {150, 300}, 0, 2},
        // Row 30
        {"slow_b", 1, 320, 320, 200, 200, 9999, 9999, false, {250, 150}, 0, 1},
        // Row 31
        {"slow_a", 1, 320, 320, 300, 300, 9999, 9999, false, {250, 150}, 0, 1},
        // Row 32
        {"fast", 1, 320, 320, 10, 10, 9999, 9999, false, {500, 380}, 0, 1},
        // Row 33
        {"fast_b", 1, 320, 320, 10, 10, 9999, 9999, false, {500, 380}, 0, 1}
};
path_def path_table_test[] = {

    {"SA_CT_a", 1, 1, 21, 10, 1, 1, 57, 57, 57, 57, 56.859476f, 2.260870f},
    {"CT", 1, 21, 2, 10, 1, 1, 85, 85, 85, 85, 84.899941f, -3.727273f},
    {"slow_AV", 1, 30, 3, 5, 1, 1, 19, 19, 19, 19, 19.235384f, 1.527778f},
    {"SA_OS", 1, 1, 4, 5, 1, 1, 44, 44, 44, 44, 43.863424f, -1.066667f},
    {"fast_AV", 1, 33, 3, 5, 1, 1, 47, 47, 47, 47, 14.142136f, -7.0f},
    {"SA_Bach", 1, 1, 8, 5, 3.010502f, 3.010502f, 40, 40, 40, 40, 120.42010f, 0.445455f},
    {"Bach_LA_a", 1, 8, 9, 10, 1, 1, 68, 68, 68, 68, 68.183576f, 0.073529f},
    {"LA", 1, 9, 10, 10, 1, 1, 35, 35, 35, 35, 34.655447f, -0.960000f},
    {"AV_His", 1, 3, 5, 2, 1, 1, 47, 47, 47, 47, 46.690470f, 0.941176f},
    {"His_p", 1, 5, 6, 2, 2, 2, 16, 16, 16, 16, 32.062439f, 0.062500f},
    {"His_d", 1, 6, 7, 2, 2, 2, 20, 20, 20, 20, 39.698866f, -1.153846f},
    {"His_RBB", 1, 7, 11, 2, 2, 2, 36, 36, 36, 36, 72.422372f, -1.404762f},
    {"His_LBB", 1, 7, 13, 2, 2, 2, 37, 37, 37, 37, 74.518454f, -0.842105f},
    {"RBB", 1, 11, 12, 2, 4.254409f, 4.254409f, 20, 20, 20, 20, 85.088190f, -0.435897f},
    {"LBB", 1, 13, 14, 2, 3.826879f, 3.826879f, 20, 20, 20, 20, 76.537572f, -0.315068f},
    {"RBB_RV", 1, 12, 15, 10, 1, 1, 18, 18, 18, 18, 18.439089f, -1.166667f},
    {"LBB_LV", 1, 14, 16, 10, 1, 1, 19, 19, 19, 19, 18.681542f, -0.277778f},
    {"RV_LV", 1, 15, 16, 10, 2, 2, 17, 17, 17, 17, 34.885527f, 1.937500f},
    {"RV_m", 1, 15, 17, 10, 5.763029f, 5.763029f, 20, 20, 20, 20, 115.26057f, 0.149123f},
    {"LV_m", 1, 16, 19, 10, 4.589390f, 4.589390f, 20, 20, 20, 20, 91.787799f, -7.583333f},
    {"RV", 1, 17, 18, 10, 5.303301f, 5.303301f, 20, 20, 20, 20, 106.06602f, -0.548387f},
    {"LV", 1, 19, 20, 10, 3.944617f, 3.944617f, 20, 20, 20, 20, 78.892332f, -1.700000f},
    {"SA_RA_a", 1, 1, 22, 10, 1, 1, 40, 40, 40, 40, 40.0f, 0.0f},
    {"RA", 1, 22, 23, 10, 1, 1, 35, 35, 35, 35, 34.713110f, -1.130435f},
    {"SEP_RV", 1, 24, 25, 10, 2, 2, 56, 56, 56, 56, 111.72287f, -1.0f},
    {"SEP_RV_m", 1, 15, 24, 10, 2, 2, 57, 57, 57, 57, 113.84199f, -0.333333f},
    {"SEP_LV", 1, 26, 27, 10, 2, 2, 52, 52, 52, 52, 103.94710f, -1.013699f},
    {"SEP_LV_m", 1, 16, 26, 10, 2, 2, 47, 47, 47, 47, 94.413982f, -0.542169f},
    {"CS_LV", 1, 27, 28, 10, 2, 2, 39, 39, 39, 39, 78.568442f, 0.913793f},
    {"CS_LA", 1, 23, 29, 5, 2, 2, 59, 59, 59, 59, 117.59677f, 0.663265f},
    {"slow", 1, 31, 30, 10, 0.09f, 0.09f, 330, 330, 330, 330, 30.016662f, -30.0f},
    {"OS_slow", 1, 4, 31, 10, 2, 2, 13, 13, 13, 13, 25.0f, 1.333333f},
    {"OS_fast", 1, 4, 32, 10, 2, 2, 10, 10, 10, 10, 20.099751f, -10.0f},
    {"fast", 1, 32, 33, 10, 2, 2, 7, 7, 7, 7, 13.038405f, -13.0f}
};


for (int i = 0; i < NUM_OF_NODES; i++) {
        node_table_test[i].index_of_path_activate_the_node--;
    }
for (int i = 0; i < NUM_OF_PATHS; i++) {
path_table_test[i].entry_node_index--;
path_table_test[i].exit_node_index--;
    }

while(1){
            system("cls");
        heart_model(node_table_test,NUM_OF_NODES,path_table_test,NUM_OF_PATHS);

  for (int i = 0; i < NUM_OF_PATHS; i++) {
    printf("%s\t", path_table_test[i].path_name);
    printf("%d\t", path_table_test[i].path_state_index);
    printf("%d\t", path_table_test[i].entry_node_index);
    printf("%d\t", path_table_test[i].exit_node_index);
    printf("%d\t", path_table_test[i].amplitude_factor);
    printf("%.2f\t", path_table_test[i].forward_speed);
    printf("%.2f\t", path_table_test[i].backward_speed);
    printf("%d\t", path_table_test[i].forward_timer_current);
    printf("%d\t", path_table_test[i].forward_timer_default);
    printf("%d\t", path_table_test[i].backward_timer_current);
    printf("%d\t", path_table_test[i].backward_timer_default);
    printf("%.4f\t", path_table_test[i].path_length);
    printf("%.4f\n", path_table_test[i].path_slope);
  }

  printf("\n\n");
for (int i = 0; i < NUM_OF_NODES; i++) {
        printf("%-10s\t%d\t(%d,%d)\t(%d,%d)\t(%d,%d)\t%d\t(%d,%d)\t%d\t%d\n",
               node_table_test[i].node_name,
               node_table_test[i].node_state_index,
               node_table_test[i].TERP_current,
               node_table_test[i].TERP_default,
               node_table_test[i].TRRP_current,
               node_table_test[i].TRRP_default,
               node_table_test[i].TREST_current,
               node_table_test[i].TREST_default,
               node_table_test[i].activation,
               node_table_test[i].TERP_bounds[0],
               node_table_test[i].TERP_bounds[1],
               node_table_test[i].index_of_path_activate_the_node,
               node_table_test[i].AV_node);
    }

        delay(0.4);

}

    return 0;
}
