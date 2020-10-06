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

enum { START_CONST = 10 };

void Print_Result(char **p, int n);
int Straight_cmp(char *a, char *b);
void QuickSort(char **p, int left, int right, int (*cmp)(char *, char *));
void My_Qsort(char **p, int n, int (*cmp)(char *, char *));
char *File_Mapping(const char *file_name);
char **Pointers_Reading(char *text_pointer, size_t *i);
void Reset_File(char *text_pointer_tmp, size_t size);
int Reverse_Cmp(char *a, char *b);
bool Select_Type();
void Run_tests();
void test_Straight_cmp();
void assert_cmp (int a, int b);
void test_Straight_cmp();
void test_Reverse_Cmp();
void test_MyQsort();