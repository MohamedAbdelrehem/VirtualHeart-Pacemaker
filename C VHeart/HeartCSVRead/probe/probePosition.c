#include "probePosition.h"

probe_position probePositionTable[100];

void saveToProbePositionStruct(char *token, const int columnNo, const int rowNo)
{
    switch (columnNo)
    {
    case 0:
        probePositionTable[rowNo].x = atof(token);

        break;
    case 1:
        probePositionTable[rowNo].y = atof(token);

        break;
    default:
        break;
    }
}

void printProbePositionTable(const int *const numberofprobes)
{
    printf("\n\nProbe Position Table\n");
    printf("--------------------------------------------------\n");
    printf("Probe Name\tX\tY\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < *numberofprobes; i++)
    {
        printf("%d\t\t%.2f\t%.2f\n", i + 1, probePositionTable[i].x, probePositionTable[i].y);
    }
    printf("--------------------------------------------------\n");
}