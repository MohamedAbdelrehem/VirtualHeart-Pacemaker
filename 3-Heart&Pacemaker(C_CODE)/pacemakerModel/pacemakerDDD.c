#include "./pacemakerDDD.h"

void pacemaker_DDD(pacemaker_parameters *pace_para, bool A_get, bool V_get, int pace_inter)
{
    bool a_s = false;
    bool a_p = false;
    bool v_s = false;
    bool v_p = false;

    //
    if (pace_para[1].corresponding_output_signal == true || pace_para[3].corresponding_output_signal == true)
    {
        pace_para[0].current_Corresponding_timer = pace_para[0].default_corresponding_timer;
    }
    if (pace_para[0].current_Corresponding_timer > 0)
    {
        pace_para[0].current_Corresponding_timer = pace_para[0].current_Corresponding_timer - pace_inter;
        if (pace_para[0].current_Corresponding_timer == pace_para[1].default_corresponding_timer && pace_para[1].State_index == 1)
        {
            a_p = true;
        }
    }
    //
    switch (pace_para[1].State_index)
    {
    case 1:
        if (pace_para[0].corresponding_output_signal == true || pace_para[2].corresponding_output_signal == true)
        {
            pace_para[1].State_index = 2;
        }
        break;
    case 2:
        if (pace_para[1].current_Corresponding_timer > 0)
        {
            pace_para[1].current_Corresponding_timer = pace_para[1].current_Corresponding_timer - pace_inter;
        }
        else
        {
            if (pace_para[4].State_index == 1)
            {
                pace_para[1].current_Corresponding_timer = pace_para[1].default_corresponding_timer;
                v_p = true;
                pace_para[1].State_index = 1;
            }
            else
            {
                pace_para[1].current_Corresponding_timer = pace_para[1].current_Corresponding_timer - pace_inter;
            }
        }
        if (pace_para[3].corresponding_output_signal == true)
        {
            pace_para[1].current_Corresponding_timer = pace_para[1].default_corresponding_timer;
            pace_para[1].State_index = 1;
        }
        break;
    }

    //

    switch (pace_para[2].State_index)
    {
    case 1:
        if (A_get == true)
        {
            if (pace_para[1].State_index == 1)
            {
                a_s = true;
            }
        }
        if (pace_para[1].corresponding_output_signal == true || pace_para[3].corresponding_output_signal == true)
        {
            pace_para[2].State_index = 2;
        }
        break;
    case 2:
        if (pace_para[2].current_Corresponding_timer > 0)
        {
            pace_para[2].current_Corresponding_timer = pace_para[2].current_Corresponding_timer - pace_inter;
        }
        else
        {
            pace_para[2].current_Corresponding_timer = pace_para[2].default_corresponding_timer;
            pace_para[2].State_index = 1;
        }
        break;
    }
    switch (pace_para[3].State_index)
    {
    case 1:
        if (V_get == true)
        {
            v_s = true;
            pace_para[3].State_index = 2;
        }

        if (pace_para[1].corresponding_output_signal == true)
        {
            pace_para[3].State_index = 2;
        }
        break;
    case 2:
        if (pace_para[3].current_Corresponding_timer > 0)
        {
            pace_para[3].current_Corresponding_timer = pace_para[3].current_Corresponding_timer - pace_inter;
        }
        else
        {
            pace_para[3].current_Corresponding_timer = pace_para[3].default_corresponding_timer;
            pace_para[3].State_index = 1;
        }
        break;
    }

    // 5
    switch (pace_para[4].State_index)
    {
    case 1:
        if (pace_para[1].corresponding_output_signal == true || pace_para[3].corresponding_output_signal == true)
        {
            pace_para[4].State_index = 2;
        }
        break;
    case 2:
        if (pace_para[4].current_Corresponding_timer > 0)
        {
            pace_para[4].current_Corresponding_timer = pace_para[4].current_Corresponding_timer - pace_inter;
        }
        else
        {
            pace_para[4].current_Corresponding_timer = pace_para[4].default_corresponding_timer;
            if (pace_para[1].current_Corresponding_timer < 0)
            {
                v_p = true;
                pace_para[1].current_Corresponding_timer = pace_para[1].default_corresponding_timer;
            }
            pace_para[4].State_index = 1;
        }
        break;
    }
    //
    pace_para[0].corresponding_output_signal = a_p;
    pace_para[1].corresponding_output_signal = v_p;
    pace_para[2].corresponding_output_signal = a_s;
    pace_para[3].corresponding_output_signal = v_s;
    pace_para[4].corresponding_output_signal = false;
}