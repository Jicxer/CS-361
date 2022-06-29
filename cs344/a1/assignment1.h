#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H


int main_menu();

int main_menu_filechoice();

int file_process(int);

void search_prefix_largest();

void search_prefix_smallest();

void search_specific(const char *file_name);

int processingFile(char* newestDirName);
#endif