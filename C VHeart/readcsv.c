#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct Node
{
    char node_name[10];
    int node_state_index;
    int TERP_current;  // suggestion using unsigned short
    int TERP_default;  // unsigned short
    int TRRP_current;  // unsigned short
    int TRRP_default;  // unsigned short
    int TREST_current; // unsigned short
    int TREST_default; // unsigned short
    int activation;
    int TERP_bounds[2];                  // unsigned short
    int index_of_path_activate_the_node; // unsigned short
    int AV_node;                         // suggestion using enum with two values

} node_def;

// array of node_def
node_def node_table[100];

int readMatlabCSV(const char *filename);
void save_to_node_table(char *token, int columnNo, int rowNo);

int main()
{
    readMatlabCSV("D:/github/VirtualHeart&Pacemaker/cases/EP_AVNRT/node_table.csv");
    // print node_table to check

    for (int i = 0; i < 30; i++)
    {
        printf("node_name: %s\n", node_table[i].node_name);
        printf("node_state_index: %d\n", node_table[i].node_state_index);
        printf("TERP_current: %d\n", node_table[i].TERP_current);
        printf("TERP_default: %d\n", node_table[i].TERP_default);
        printf("TRRP_current: %d\n", node_table[i].TRRP_current);
        printf("TRRP_default: %d\n", node_table[i].TRRP_default);
        printf("TREST_current: %d\n", node_table[i].TREST_current);
        printf("TREST_default: %d\n", node_table[i].TREST_default);
        printf("activation: %d\n", node_table[i].activation);
        printf("TERP_bounds: %d %d\n", node_table[i].TERP_bounds[0], node_table[i].TERP_bounds[1]);
        printf("index_of_path_activate_the_node: %d\n", node_table[i].index_of_path_activate_the_node);
        printf("AV_node: %d\n", node_table[i].AV_node);
        printf("\n");
    }

    return 0;
}

int readMatlabCSV(const char *filename)
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
            // Copy the token to the node_table
            // use switch case with columnNo to copy the token to the node_table
            save_to_node_table(token, columnNo, rowNo);
            // Get the next token
            token = strtok(NULL, "\"");
            columnNo++;
        }
        rowNo++;
        // printf("\n");
    }

    // Close the file
    fclose(file);
}

void save_to_node_table(char *token, int columnNo, int rowNo)
{
    // printf("rowNo: %d, columnNo: %d, token: %s\n", rowNo, columnNo, token);
    switch (columnNo)
    {
    case 0:
        strcpy(node_table[rowNo].node_name, token);
        break;
    case 1:
        node_table[rowNo].node_state_index = atoi(token);
        break;
    case 2:
        node_table[rowNo].TERP_current = atoi(token);
        break;
    case 3:
        node_table[rowNo].TERP_default = atoi(token);
        break;
    case 4:
        node_table[rowNo].TRRP_current = atoi(token);
        break;
    case 5:
        node_table[rowNo].TRRP_default = atoi(token);
        break;
    case 6:
        node_table[rowNo].TREST_current = atoi(token);
        break;
    case 7:
        node_table[rowNo].TREST_default = atoi(token);
        break;
    case 8:
        node_table[rowNo].activation = atoi(token);
        break;
    case 9:
        // sscanf take value from token and store it in node_table[rowNo].TERP_bounds[0] and node_table[rowNo].TERP_bounds[1] based on the format in 2nd argument
        sscanf(token, "[%d, %d]", &node_table[rowNo].TERP_bounds[0], &node_table[rowNo].TERP_bounds[1]);
        break;

    case 10:
        node_table[rowNo].index_of_path_activate_the_node = atoi(token);
        break;
    case 11:
        node_table[rowNo].AV_node = atoi(token);
        break;
    default:
        break;
    }
}