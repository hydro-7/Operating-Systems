#include<stdio.h>

int main() {
    char ch;
    char filename[100];
    FILE *file;

    scanf("%s", filename);

    file = fopen(filename, "r");

    while((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);

    // file = fopen(filename, "wb"); // to delete contents of the file
    // fclose(file);

}