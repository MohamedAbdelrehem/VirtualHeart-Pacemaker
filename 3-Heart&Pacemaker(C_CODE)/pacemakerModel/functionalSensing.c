#include "./functionalSensing.h"

//! why *
float *functional_sensing(node_location *node_pos, path_def *path_table, probe_position *probe_pos, probe_def *probe_table, float probe_amp[], int probe_table_size)
{

    float local_theta = 15;
    double far_theta = 80;
    static float egm_data[probe_table_size];
    double wave_front[2][2];
    int cur_timer;
    int def_timer;
    int count_size_3;
    double cur_dist;
    double ratio_def;

    for (int i = 0; i < probe_table_size; i++)
    {
        egm_data[i] = 0;

        //! TODO : @mohamed  to find way to read column in cell array in matlab that have variable size arrays
        //! temporary implementation
        int count_size = 0;
        for (int j = 0; j < 20; j++)
        {

            if (probe_table[i].corresponding_path[j] == -1)
            {
                break;
            }
            count_size++;
        }
        // int temp[count_size];
        int count_size_2 = 0;
        int act_local[count_size];
        probe_position act_probe[probe_table_size];

        for (int m = 0; m < count_size; m++)
        {
            act_local[m] = probe_table[i].corresponding_path[m];
        }

        /////        act_probe[i] = probe_pos[i];

        for (int j = 0; j < count_size; j++)
        {
            if (path_table[probe_table[i].corresponding_path[j]].path_state_index != 1)
            {
                act_local[count_size_2] = probe_table[i].corresponding_path[j];
                count_size_2++;
            }
        }

        node_location p1;
        node_location p2;
        for (int j = 0; j < count_size_2; j++)
        {

            p1 = node_pos[path_table[act_local[j]].entry_node_index];
            p2 = node_pos[path_table[act_local[j]].exit_node_index];
            count_size_3 = 0;

            switch (path_table[act_local[j]].path_state_index)
            {
            case 2:
                wave_front = [ p1(1) + (p2(1) - p1(1)) * (def_timer - cur_timer) / def_timer, ... p2(2) + (p1(2) - p2(2)) * cur_timer / def_timer ];
                cur_timer = path_table[act_local[j]].forward_timer_current;
                def_timer = path_table[act_local[j]].forward_timer_default;
                wave_front[0][0] = p1[0] + (p2[0] - p1[0]) * (def_timer - cur_timer) / def_timer;
                wave_front[0][1] = p2[1] + (p1[1] - p2[1]) * (cur_timer / def_timer);
                count_size_3++;
                break;
            case 3:

                cur_timer = path_table[act_local[j]].backward_timer_current;
                def_timer = path_table[act_local[j]].backward_timer_default;
                wave_front[0][0] = p1[0] + (p2[0] - p1[0]) * (cur_timer / def_timer);
                wave_front[0][1] = p2[1] + (p1[1] - p2[1]) * (def_timer - cur_timer) / def_timer;
                count_size_3++;

                break;
            case 5:
                cur_timer = path_table[act_local[j]].forward_timer_current;
                def_timer = path_table[act_local[j]].forward_timer_default;
                wave_front[0][0] = p1[0] + (p2[0] - p1[0]) * (def_timer - cur_timer) / def_timer;
                wave_front[0][1] = p2[1] + (p1[1] - p2[1]) * (cur_timer / def_timer);
                cur_timer = path_table[act_local[j]].backward_timer_current;
                def_timer = path_table[act_local[j]].backward_timer_default;
                wave_front[1][0] = p1[0] + (p2[0] - p1[0]) * (cur_timer / def_timer);
                wave_front[1][1] = p2[1] + (p1[1] - p2[1]) * (def_timer - cur_timer) / def_timer;
                count_size_3 += 2;
                ;

                break;
            default:
                wave_front[0][0] = INFINITY;
                wave_front[0][1] = INFINITY;
                count_size_3++;

                break;
            }
            for (k = 0; k < count_size_3, k++)
            {
                cur_dist = ((act_probe(2) - wave_front(k, 2)) ^ 2 + (act_probe(1) - wave_front(k, 1)) ^ 2) ^ .5;
                cur_dist = pow(pow((act_probe[i].y - wave_front[k][2]), 2) + pow((act_probe[i].x - wave_front[k][1]), 2), 0.5);
                ratio_def = gaussmf(cur_dist, local_theta, 0);
                egm_data[i] = i + (ratio_def * path_table[act_local[j]].amplitude_factor);
            }
        }

        int pacing_probe_ind[probe_table_size];
        int count_size_4 = 0;
        for (int j = 0; j < probe_table_size, j++)
        {
            if (probe_amp[j] != 0)
            {
                pacing_probe_ind[count_size_4] = j;
                count_size_4++;
            }
        }
        for (k = 0; k < count_size_4; k++)
        {
            cur_dist = pow(pow((act_probe[i].y - probe_pos[pacing_probe_ind[k]].y), 2) + pow((act_probe[i].x - probe_pos[pacing_probe_ind[k]].x), 2), 0.5);
            ratio_def = 0.7 * gaussmf(cur_dist, far_theta, 0);
            egm_data[i] = i + ratio_def * probe_amp[pacing_probe_ind[k]];
        }
    }
    return egm_data;
}

double gaussmf(double x, double sigma, double c)
{

    double y = exp(-(pow(x - c, 2)) / 2 * sigma * sigma);
    return y;
}