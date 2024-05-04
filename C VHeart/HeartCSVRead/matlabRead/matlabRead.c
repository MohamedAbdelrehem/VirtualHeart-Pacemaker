#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matlabRead.h"

/**
 * Reads a CSV file in that exported from my MATLAB code.
 *
 * @param fileName The name of the CSV file to read.
 * @param numberOfRows Pointer to store in it's pointee the number of nodes in the CSV file.
 * @param saveToStructFPointer function pointer used to save the data to the any struct.
 * @return A matrix containing the data from the CSV file.
 */
int readMatlabCSV(const char *fileName, int *const numberOfRows, void (*saveToStructFPointer)(char *, const int, const int))
{

    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;

    // Open the CSV file
    file = fopen(fileName, "r");
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
            saveToStructFPointer(token, columnNo, rowNo);
            // Get the next token
            token = strtok(NULL, "\"");
            columnNo++;
        }
        rowNo++;
        // printf("\n");
    }
    *numberOfRows = rowNo;
    // Close the file
    fclose(file);
}