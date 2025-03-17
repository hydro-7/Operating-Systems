#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>

int main() {
    char filename[100];
    FILE *file;

    fopen(filename, "r");

    struct stat fileStats;
    stat(filename, &fileStats);

    // fileStats.st_size -> size in bytes
    // fileStats.st_nlink -> number of links
    // fileStats.st_uid -> file owner
    // fileStats.st_gid -> file group
    // fileStats.st_mode -> file permissions
    // ctime(&fileStats.st_mtime) -> last modified
}