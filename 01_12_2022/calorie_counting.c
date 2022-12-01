#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

/**
 * @param argv  argv[1] relative input file path
 */
int main(int argc, char **argv) { 
    unsigned int entry_count = 0;
    int index, sdi, tdi, max, sd, td, calories_sum = 0;
    char buffer[MAX_INPUT_SIZE];
    FILE *fp;

    if(argc != 2) {
        printf("Invalid argument count: %d\n", argc);
        return 1;
    }

    fp = fopen(argv[1], "r");
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        calories_sum += atoi(buffer);        
        // printf("Read from file: %s\n", buffer);

        if (buffer[0] == '\n') {
            entry_count += 1;

            if (calories_sum > max) {
                index = entry_count;

                td = sd;
                sd = max;
                max = calories_sum;
            }   
            else if (calories_sum > sd) {
                sdi = entry_count;

                td = sd;
                sd = calories_sum;
            }  
                
            else if (calories_sum > td) {
                tdi = entry_count;
                td = calories_sum;
            }
        
            calories_sum = 0;
            continue;
        }
    }

    // printf("The amount of entries (non-whitespace) is: %d\n", entry_count);
    printf("The elf with the most caloric content is number: %d with %d calories\n", index, max);
    printf("The second elf with the most caloric content is number: %d with %d calories\n", sdi, sd);
    printf("The third elf with the most caloric content is number: %d with %d calories\n", tdi, td);

    printf("Sum of top three elves with the highest caloric content: %d\n", max + sd + td);

    return 0;
}