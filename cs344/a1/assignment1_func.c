#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "assignment1.h"
#include <stdlib.h>
#include <time.h>



//=======================================================Prompts for user======================================================//
int main_menu(){
    int program_option;
    printf("1. Select a file to process: \n");
    printf("2. Exit Program\n\n");
    scanf("%d", &program_option);
    return program_option;
}

int main_menu_filechoice(){
    int choice;
    printf("Which file do you want to process?\n");
    printf("1. The largest file\n");
    printf("2. The smallest file\n");
    printf("3. Specify a file name\n");
    printf("Enter a choice from 1 to 3\n\n");
    scanf("%d", &choice);
    return choice;
}

int file_process(int fileprocess_option){
    
    char file_name[100];


    if (fileprocess_option == 1){
        printf("Finding the largest file with extension with prefix 'movie_'...\n");
        search_prefix_largest();
    }
    else if (fileprocess_option == 2){
        printf("Finding the smallest file with extension with prefix 'movie_'...\n");
        search_prefix_smallest();
    }
    else if(fileprocess_option == 3){
        printf("Enter the complete file name: \n");
        scanf("%s", file_name);
        search_specific(file_name);
    }
    return 0;
}

void search_prefix_largest(){
    long int size = 0;                                                          // Grab the number of bytes of the file
    char targetFileName[32] = "movie_";                                        // Prefix we're looking for
    char newestDirName[256];                                                    // Holds the name of the newest dir that contains prefix
    memset(newestDirName, '\0', sizeof(newestDirName));
    DIR* dirToCheck;                                                            // Holds the directory we're starting in
    struct dirent *fileInDir;                                                   // Holds the current subdir of the starting dir
    struct stat dirAttributes;                                                  // Holds information we've gained about subdir
    dirToCheck = opendir(".");                                                  // Open up the directory this program was run in
    if (dirToCheck > 0) {                                                       // Make sure the current directory could be opened
    while ((fileInDir = readdir(dirToCheck)) != NULL) {                         // Check each entry in dir
        if (strstr(fileInDir->d_name, targetFileName) != NULL) {               // If entry has prefix
            stat(fileInDir->d_name, &dirAttributes);                            // Get attributes of the entry
            if ((int)dirAttributes.st_size > size){
                size = dirAttributes.st_size;
                memset(newestDirName, '\0', sizeof(newestDirName));
                strcpy(newestDirName, fileInDir->d_name);
                printf("Found the new largest file in directory: %s with size of: %ld\n", fileInDir->d_name, size);
            }
        }
    }
}   

    
    printf("Now processing the chosen file named %s...\n", newestDirName);
    processingFile(newestDirName);
    closedir(dirToCheck); // Close the directory we opened
    // printf("Newest entry found is: %s\n", newestDirName);
    


}

void search_prefix_smallest(){
    // int newestDirTime = -1;                                                     // Modified timestamp of newest subdir examined
    long int size = 0;                                                          // Grab the number of bytes of the file
    char targetFileName[32] = "movie_";                                        // Prefix we're looking for
    char newestDirName[256];                                                    // Holds the name of the newest dir that contains prefix
    memset(newestDirName, '\0', sizeof(newestDirName));
    DIR* dirToCheck;                                                            // Holds the directory we're starting in
    struct dirent *fileInDir;                                                   // Holds the current subdir of the starting dir
    struct stat dirAttributes;                                                  // Holds information we've gained about subdir
    dirToCheck = opendir(".");                                                  // Open up the directory this program was run in
    if (dirToCheck > 0) {                                                       // Make sure the current directory could be opened
    while ((fileInDir = readdir(dirToCheck)) != NULL) {                         // Check each entry in dir
        if (strstr(fileInDir->d_name, targetFileName) != NULL) {               // If entry has prefix
            stat(fileInDir->d_name, &dirAttributes);                            // Get attributes of the entry
            if(size == 0){
                size = dirAttributes.st_size;
            }
            if ((int)dirAttributes.st_size < size){
                size = dirAttributes.st_size;
                memset(newestDirName, '\0', sizeof(newestDirName));
                strcpy(newestDirName, fileInDir->d_name);
                printf("Found the new smallest file in directory: %s with size of: %ld\n", fileInDir->d_name, size);
            }
        }
    }
}
    printf("Now processing the chosen file named %s...\n", newestDirName);
    processingFile(newestDirName);
    closedir(dirToCheck); // Close the directory we opened
    // printf("Newest entry found is: %s\n", newestDirName);
    
}

void search_specific(const char *file_name){
    int found = 0;
    char newestDirName[256];                                                    // Holds the name of the newest dir that contains prefix
    memset(newestDirName, '\0', sizeof(newestDirName));
    DIR* dirToCheck;                                                            // Holds the directory we're starting in
    struct dirent *fileInDir;                                                   // Holds the current subdir of the starting dir
    struct stat dirAttributes;                                                  // Holds information we've gained about subdir
    dirToCheck = opendir(".");                                                  // Open up the directory this program was run in
    if (dirToCheck > 0) {                                                       // Make sure the current directory could be opened
    while ((fileInDir = readdir(dirToCheck)) != NULL) {                            // Check each entry in dir
        if (strcmp(fileInDir->d_name, file_name) == 0) {                        // If entry has prefix
            stat(fileInDir->d_name, &dirAttributes);                            // Get attributes of the entry
            memset(newestDirName, '\0', sizeof(newestDirName));
            strcpy(newestDirName, fileInDir->d_name);
            printf("Found the specified file in directory: %s with size of: %d\n", fileInDir->d_name, (int)dirAttributes.st_size);
            found = 1;
        }


    }
}        
    if (found == 0){
        printf("The file %s was not found. Returning to file selection menu.\n", file_name);
        int choice = main_menu_filechoice();
        file_process(choice);
        return;
    }
    printf("Now processing the chosen file named %s...\n", newestDirName);
    processingFile(newestDirName);
    closedir(dirToCheck); // Close the directory we opened
    // printf("Newest entry found is: %s\n", newestDirName);

}

int processingFile(char* newestDirName){
    char userInfo [100];
    int r = rand() % 1000;
    printf("Passed file name: %s\n", newestDirName);
    printf("Random number is: %d\n", r);
    sprintf(userInfo, "chanjohn_933821369.%i", r);
    printf("Created new directory!\n");
    mkdir(userInfo,0750);
    puts(userInfo);

    FILE *inputFile = fopen(newestDirName, "r");

    return 0;
}