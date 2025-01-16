// write a program to read input from file and display the output
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    char ch;
    FILE *file;

    printf("Enter the filename to read from: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    printf("Contents of the file :\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
    return 0;
}
