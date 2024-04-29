#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matlabRead.h"
#include "nodeTable.h"

int readMatlabCSV(const char *filename, int *numberofnodes)
{

    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;

    // Open the CSV file
    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    int rowNo = 0;

    // Read each line of the file
    while (fgets(line, sizeof(line), file))
    {
        int columnNo = 0;
        // Extract tokens between quotes
        token = strtok(line, "\"");
        while (token != NULL)
        {
            if (token[0] == ',')
            {
                token = strtok(NULL, "\"");
                continue;
            }
            // Print the token
            // printf("%s  ", token);
            // Copy the token to the nodeTable
            // use switch case with columnNo to copy the token to the nodeTable
            saveToNodeStruct(token, columnNo, rowNo);
            // Get the next token
            token = strtok(NULL, "\"");
            columnNo++;
        }
        rowNo++;
        // printf("\n");
    }
    *numberofnodes = rowNo;
    // Close the file
    fclose(file);
}