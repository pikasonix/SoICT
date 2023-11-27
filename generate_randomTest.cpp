#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int numbers[MAX];
int main() {
    FILE *fp = fopen("input.txt", "a");
    for (int i = 0; i < MAX; i++)   numbers[i] = rand() % MAX;
    fprintf(fp, "%d\n", MAX);
    for (int i = 0; i < MAX; i++)   fprintf(fp, "%d\n", numbers[i]);
    fclose(fp);
}