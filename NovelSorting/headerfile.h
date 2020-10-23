#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/io.h>
#include <sys/mman.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <wctype.h>
#include <stdbool.h>
#include <assert.h>

#define _CMD_RHYME_ "-rhm"
#define _CMD_ALPHABETIC_ "-alph"
#define _CMD_ORIGIN_ "-orig"
#define _CMD_ALL_ "-all"
#define _FILEPATH_ALPHABETIC_ "Output/Alphbetic.txt"
#define _FILEPATH_RHYME_ "Output/Rhyme.txt"
#define _FILEPATH_ORIGIN_ "Output/Original.txt"

enum { START_CONST = 10 };

void Print_Result(char **p, int n, char *filepath);
int Straight_cmp(char *a, char *b);
void QuickSort(char **p, int left, int right, int (*cmp)(char *, char *));
void My_Qsort(char **p, int n, int (*cmp)(char *, char *));
char *File_Mapping(const char *file_name, int *fd, size_t *size);
char **Pointers_Reading(char *text_pointer, size_t *i);
void Reset_File(char *text_pointer_tmp, size_t size);
bool Cmd_Read(bool *print_type, int argc, char const *argv[]);
int Reverse_Cmp(char *a, char *b);
int Select_Type();
void Run_tests();
void test_Straight_cmp();
void assert_cmp (int a, int b);
void test_Straight_cmp();
void test_Reverse_Cmp();
void test_MyQsort();