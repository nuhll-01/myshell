#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 250

int main(int argc, char* argv[]) {

    const char* filename = argv[1];

    FILE* fd = fopen(filename, "r");

    if (fd == NULL) { 
        fprintf(stderr, "Operation Failed.\nUnable to open: \"%s\"\n", filename);
        return -1;
    } 

    int line_counter = 1;
    char line[1024];
    while (fgets(line, sizeof(line), fd)) { 
        line_counter++;
    }

    fseek(fd, 0, SEEK_SET);

    // error checking
    if (line_counter > 1000) { 
        fprintf(stderr, "Too many lines.\n");
    }

    if (line_counter > 5) { 
        char output_line[line_counter][MAX_SIZE];

        // traverse and the copy the line towards the destination array.
        int i = 0;
        while (fgets(line, sizeof(line), fd)) {
            strcpy(output_line[i], line);
            i++;
        }

        for (int i = line_counter - 6; i < line_counter; i++) { 
            printf("%s", output_line[i]);
        }

    } else {
        while (fgets(line, sizeof(line), fd)) {
            printf("%s", line);
        }
    }
    
    fclose(fd);

    return 0;
}