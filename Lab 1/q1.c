// write a program to read input from user and store in the file
#include<stdio.h>
int main()
{
    char filename[100];
    char string_input[1000];
    FILE *file;

    printf("String to write into the file : ");
    scanf("%[^\n]s", string_input);

    printf("Enter name of the file to store input : ");
    scanf("%s", filename);

    file = fopen(filename, "w");

    fputs(string_input, file);
    fclose(file);

    printf("Data has been written into the file.\n");

}