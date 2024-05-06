#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../dataStructure.h"
#include "./probeTable.h"

probe_def probeTable[100];

void saveToProbeStruct(char *token, const int columnNo, const int rowNo)
{
    switch (columnNo)
    {
    case 0:
        strcpy(probeTable[rowNo].probe_name, token);
        break;
    case 1:
        // printf("Probe bounds: %c\n", token[0]);
        // Remove brackets from token
        if (token[0] == '[')
        {

            memmove(token, token + 1, strlen(token));
            token[strlen(token) - 1] = '\0';

            // Tokenize string by commas
            char *ptr;
            int i = 0;
            ptr = strtok(token, ",");
            while (ptr != NULL)
            {
                probeTable[rowNo].corresponding_path[i] = atoi(ptr);
                ptr = strtok(NULL, ",");
                i++;
            }

            // Fill remaining elements with -1
            for (; i < 10; i++)
            {
                probeTable[rowNo].corresponding_path[i] = -1;
            }
        }
        else
        {
            probeTable[rowNo].corresponding_path[0] = atoi(token);
            for (int i = 1; i < 10; i++)
            {
                probeTable[rowNo].corresponding_path[i] = -1;
            }
        }
        break;
    default:
        break;
    }
}

void printProbeTable(const int *const numberofprobes)
{
    printf("Table of probes:\n\n");
    for (int i = 0; i < *numberofprobes; i++)
    {
        printf("x: %-5s\t", probeTable[i].probe_name);
        printf("y: [");
        for (int j = 0; j < 10; j++)
        {
            if (probeTable[i].corresponding_path[j] != -1)
            {
                printf("%d", probeTable[i].corresponding_path[j]);
                if (j < 9 && probeTable[i].corresponding_path[j + 1] != -1)
                {
                    printf(", ");
                }
            }
        }
        printf("]\n");
    }
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}
