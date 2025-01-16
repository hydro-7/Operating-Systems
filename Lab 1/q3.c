// Implement the copy file command in C
// Basically copy the contents from one file and write them onto another

#include<stdio.h>
int main()
{
    char filename1[100], filename2[100];

    printf("Name of file 1 : ");
    scanf("%s", filename1);

    printf("Name of file 2 : ");
    scanf("%s", filename2);

    FILE *file1, *file2;
    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "w");

    printf("Reading contents of file 1...\n");

    char ch, file1_contents[1000];
    int ite = 0;
    while ((ch = fgetc(file1)) != EOF) {
        file1_contents[ite++] = ch;
    }
    file1_contents[ite] = '\0';

    printf("Writing contents of file 1 onto file 2.. \n");

    fputs(file1_contents, file2);
    fclose(file1);
    fclose(file2);

    return 0;
}