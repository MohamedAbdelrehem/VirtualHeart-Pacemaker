char buffer[1024];
        int row = 0;
        int column = 0;
        int i = 0;

        while (fgets(buffer, 1024, fp))
        {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char *value = strtok(buffer, ",");

            while (value)
            {
                // Column 1
                if (column == 0)
                {
                    printf("Time : ");
                }

                // Column 2
                if (column == 1)
                {
                    printf("EGM1 : ");
                }

                // Column 3
                if (column == 2)
                {
                    printf("EGM2 : ");
                }

                printf("%s", value);
                value = strtok(NULL, ",");
                column++;
            }

            printf("\n");
        }

        // Close the file
        fclose(fp);
        