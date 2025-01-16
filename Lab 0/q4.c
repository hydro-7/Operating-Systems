// print the metadata of a given file 
// file metadata includes : file name, file size, file type, creation date, last modified, access perms, owner, location, attributes
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
    char filename[100];
    FILE *file;

    printf("Name of the file : ");
    scanf("%s", filename);

    struct stat fileStat;
    stat(filename, &fileStat);

    printf("File Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Number of Links: %ld\n", (long)fileStat.st_nlink);
    printf("File Owner: %d\n", fileStat.st_uid);
    printf("File Group: %d\n", fileStat.st_gid);
    printf("File Permissions: %o\n", fileStat.st_mode);
    printf("Last Modified: %s", ctime(&fileStat.st_mtime));

}