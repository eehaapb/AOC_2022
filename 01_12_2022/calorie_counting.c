#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

/**
 * @param argv  argv[1] relative input file path
 */
int main(int argc, char **argv) { 
    unsigned int entry_count = 0;
    int index, max, calories_sum = 0;
    char buffer[MAX_INPUT_SIZE];
    FILE *fp;

    fp = fopen(argv[1], "r");
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (buffer[0] == '\n') {
            entry_count += 1;

            if (calories_sum > max) {
                index = entry_count;
                max = calories_sum;

            }

            calories_sum = 0;
            continue;
        }

        // printf("Read from file: %s\n", buffer);

        calories_sum += atoi(buffer);
    }

    // printf("The amount of entries (non-whitespace) is: %d\n", entry_count);
    printf("The elf with the most caloric content is number: %d with %d calories\n",index, max);
    return 0;
}