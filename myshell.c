/**********************************************************************************
*  Author: Erick                                                                  * 
*  Created: September 24, 2024                                                    * 
*                                                                                 * 
*  Simplified version of a UNIX commmand shell                                    * 
*                                                                                 *                                                                         
*  References/Citations:                                                          *
*       - https://www.tutorialspoint.com/c_standard_library/string_h.htm          * 
*       - https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm * 
*                                                                                 * 
*                                                                                 * 
*                                                                                 * 
*                                                                                 * 
*                                                                                 * 
*                                                                                 *     
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CAT "cat"
#define TAIL "tail"
#define EXIT "exit"
#define FAULTY_EXIT "Exit"
#define ARG_LIMIT 1

int main(int argc, char *argv[]) {
    
    // int character = 0;

    // for (int i = 0; i < argc; i++) { 
    //     character = atoi(argv[i]);
    //     if (character == 39) { 
    //         fprintf(stderr, "Operation Failed.");
    //         return -1;
    //     }
    // }

    if (argc > ARG_LIMIT) { 
        fprintf(stderr, "Usage: <./myshell>\n");
        return -1;
    }

    char input[100];
    char *token;
    
    while (strcmp(input, EXIT) != 0) { 
        printf("%s", "myshell> ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, FAULTY_EXIT) == 0) { 
            puts("Did you mean \'exit\'?");
        }        

        token = strtok(input, " ");
        
        if (strcmp(token, CAT) == 0) {
            pid_t pid = fork();
            
            if (pid == 0) {
                char *file1 = strtok(NULL, " ");
                char *file2 = strtok(NULL, " ");

                if (file2 != NULL) { 
                    char* args[] = {"./cat", file1, file2, NULL};
                    execvp(args[0], args); 
                    perror("execvp failed.");
                }

                char* args[] = {"./cat", file1, NULL};
                execvp(args[0], args); 
                perror("execvp failed.");
            } else {
                waitpid(pid, NULL, 0);
            }
        }

        if (strcmp(token, TAIL) == 0) { 
            pid_t tail_pid = fork();

            if (tail_pid == 0) {
                char *file1 = strtok(NULL, " ");
                char* args[] = {"./tail", file1, NULL};
                execvp(args[0], args);
                perror("execvp failed.");
            } else {
                waitpid(tail_pid, NULL, 0);
            }
        }
    }

    return 0;
}
