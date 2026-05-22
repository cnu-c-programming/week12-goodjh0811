#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    char line[100];
    int sum = 0;
    int num;
    char extra;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%d %c", &num, &extra) == 1) {
            sum += num;
        } else {
            fprintf(stderr, "invalid input %s", line);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
