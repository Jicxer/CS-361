/* Program: catalog.cpp
** Author: Ivan Chan
** Date: 6/27/22
** Description: 
                Write a program that
                    Reads directory entries
                    Finds a file in the current directory based on user specified criteria
                    Reads and processes the data in the chosen file
                    Creates a directory
                    Creates new files in the newly created directory and writes processed data to these files
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "assignment1.h"

// const char* userInfo = "chanjohn_933821369";

int main() {
    srand(time(NULL));
    
    int valid, fileprocess_option;
    while(valid != 1){

        int program_option = main_menu();
        if (program_option == 1){
            // valid = 1;
            fileprocess_option = main_menu_filechoice();
            file_process(fileprocess_option);
        }
        else if(program_option == 2){
            exit(0);
        }
        else{
            printf("Please enter a valid option.\n");
            valid = 0;
        }
    }
    return 0;


    
}