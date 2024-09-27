#include <stdio.h>

#define MAX_SIZE 1024

int main(int argc, char* argv[]) {

    const char* filename = argv[1];

    FILE* fd = fopen(filename, "r");

    if (fd == NULL) { 
        fprintf(stderr, "Operation Failed.\nUnable to open: \"%s\"\n", filename);
        return -1;
    }

    char line[MAX_SIZE];
    while (fgets(line, sizeof(line), fd)) { 
        printf("%s", line);
    }

    fclose(fd);

    puts("");

    if (argc > 2) { 
        const char* filename = argv[2];

        FILE* fd = fopen(filename, "r");

        if (fd == NULL) { 
            fprintf(stderr, "Operation Failed.\nUnable to open: \"%s\"\n", filename);
            return -1;
        }

        char line[MAX_SIZE];
        while (fgets(line, sizeof(line), fd)) { 
            printf("%s", line);
        }

        fclose(fd);
    }

    return 0;
}