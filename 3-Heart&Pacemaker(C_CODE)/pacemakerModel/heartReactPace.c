#include "./heartReactPace.h"

void heart_react_pace(probe_def *probe_table, node_path *path_table, probe_position *probe_pos, node_location *node_pos, float probe_amp, int probe_table_size)
{
    static float last_amp[probe_table_size];
    static int count_entered = 0;

    if (count_entered == 0)
    {

        memcpy(&last_amp, probe_amp, probe_table_size);
    }
    int count_size = 0;
    int pacing_ind[probe_table_size];
    for (int i = 0; i < probe_table_size; i++)
    {
        if (probe_amp[i] - last_amp[i] > 0)
        {
            pacing_ind[count_size] =
                count_size++;
        }
    }
    memcpy(&last_amp, probe_amp, probe_table_size);

    int cur_path;
    probe_position p0;
    node_location p1;
    float l, a;
    float b;
    float c, d, ratio_calc;

    for (int i = 0; i < count_size; i++)
    {
        cur_path = probe_table[pacing_ind[i]].corresponding_path[0];
        p0 = probe_pos[pacing_ind[i]];
        p1 = node_pos[path_table[cur_path].entry_node_index];

        l = pow(pow((p1.x - p0.x), 2) + pow((p1.y - p0.y), 2), 0.5);
        a = path_table[pacing_ind[i]].path_slope;
        b = -1;
        c = p1.y - (a * p1.x);
        d = abs((a * p0.x) + (b * p0.y) + c) / pow((a * a) + (b * b), 0.5);
        ratio_calc = pow((l * l) - (d * d), 0.5) / path_table[pacing_ind[i]].path_length;

        switch (path_table[cur_path].path_state_index)
        {
        case 1:
            path_table[cur_path].path_state_index = 5;
            path_table[cur_path].forward_timer_current = round(ratio_calc * path_table[cur_path].forward_timer_default);
            path_table[cur_path].backward_timer_current = round((1 - ratio_calc) * path_table[cur_path].backward_timer_default) + 1;
            break;
        case 2:
            if (ratio_calc > path_table[cur_path].forward_timer_current / path_table[cur_path].forward_timer_default)
            {
                path_table[cur_path].forward_timer_current = round(ratio_calc * path_table[cur_path].forward_timer_default);
            }
            break;
        case 3:
            if (ratio_calc > path_table[cur_path].backward_timer_current / path_table[cur_path].backward_timer_default)
            {
                path_table[cur_path].backward_timer_current = round(ratio_calc * path_table[cur_path].backward_timer_default);
            }
            break;
        case 4:
            break;
        case 5:
            if (ratio_calc > path_table[cur_path].forward_timer_current / path_table[cur_path].forward_timer_default)
            {
                path_table[cur_path].forward_timer_current = round(ratio_calc * path_table[cur_path].forward_timer_default);
            }
            else if (ratio_calc > path_table[cur_path].backward_timer_current / path_table[cur_path].backward_timer_default)
            {
                path_table[cur_path].backward_timer_current = round(ratio_calc * path_table[cur_path].backward_timer_default);
            }
            break;
        }
    }

    count_entered++;
}