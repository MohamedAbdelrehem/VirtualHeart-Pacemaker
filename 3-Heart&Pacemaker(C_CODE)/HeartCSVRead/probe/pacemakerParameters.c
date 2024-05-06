
#include "pacemakerParameters.h"

pacemaker_parameters pacemakerParametersTable[100];

void saveToPacemakerParametersStruct(char *token, const int columnNo, const int rowNo)
{
    switch (columnNo)
    {
    case 0:
        strcpy(pacemakerParametersTable[rowNo].Component_name, token);
        break;
    case 1:
        pacemakerParametersTable[rowNo].State_index = atoi(token);
        break;
    case 2:
        pacemakerParametersTable[rowNo].current_Corresponding_timer = atoi(token);
        break;
    case 3:
        pacemakerParametersTable[rowNo].default_corresponding_timer = atoi(token);
        break;
    case 4:
        pacemakerParametersTable[rowNo].corresponding_output_signal = atoi(token);
        break;
    default:
        break;
    }
}

void printPacemakerParametersTable(const int *const numberofpacemaker)
{
    printf("Pacemaker Parameters Table\n");
    for (int i = 0; i < *numberofpacemaker; i++)
    {
        printf("Name: %s, Min: %f, Max: %f, Value: %f, Step: %f\n",
               pacemakerParametersTable[i].Component_name,
               pacemakerParametersTable[i].State_index,
               pacemakerParametersTable[i].current_Corresponding_timer,
               pacemakerParametersTable[i].default_corresponding_timer,
               pacemakerParametersTable[i].corresponding_output_signal);
    }
}