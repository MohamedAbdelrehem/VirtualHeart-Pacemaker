
#include "pacemakerParameters.h"

pacemaker_parameters pacemakerParametersTable[100];

void saveToPacemakerParametersStruct(char *token, const int columnNo, const int rowNo)
{
    switch (columnNo)
    {
    case 0:
        strcpy(pacemakerParametersTable[rowNo].name, token);
        break;
    case 1:
        pacemakerParametersTable[rowNo].min = atof(token);
        break;
    case 2:
        pacemakerParametersTable[rowNo].max = atof(token);
        break;
    case 3:
        pacemakerParametersTable[rowNo].value = atof(token);
        break;
    case 4:
        pacemakerParametersTable[rowNo].step = atof(token);
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
               pacemakerParametersTable[i].name,
               pacemakerParametersTable[i].min,
               pacemakerParametersTable[i].max,
               pacemakerParametersTable[i].value,
               pacemakerParametersTable[i].step);
    }
}