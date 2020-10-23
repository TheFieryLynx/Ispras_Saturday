#include "headerfile.h"

/**
 * Function that prints sorted text to new result.txt file 
 * @param p - array_of_pointers
 * @param n - size of array_of_pointers
 * @return void
 */

void Print_Result(char **p, int n, char *filepath) 
{
    FILE *file = fopen(filepath, "w");
    if (!file) {
        _exit(1);
    }
    for (int i = 0; i <= n; i++) {
        fprintf(file, "%s\n", p[i]);
    }
}

/**
 * Function that compares two char* pointers. Sort by beginning of lines.
 * @param a - first pointer
 * @param b - second pointer
 * @return if a > b returns 1, else - 0
 */ 

int Straight_cmp(char *a, char *b)
{
    wchar_t wc_1 = 0, wc_2 = 0;
    int length_1 = 0, length_2 = 0;
    do {
        length_1 = mbtowc(&wc_1,  a, MB_CUR_MAX);
        length_2 = mbtowc(&wc_2,  b, MB_CUR_MAX);
        
        while (!iswalpha(wc_1) && wc_1 != '\0') {
            a += length_1;
            length_1 = mbtowc(&wc_1,  a, MB_CUR_MAX);
            
        } 
        while (!iswalpha(wc_2) && wc_2 != '\0') {
            b += length_2;
            length_2 = mbtowc(&wc_2,  b, MB_CUR_MAX);
            
        }
        a += length_1;
        b += length_2;
    } while (wc_1 == wc_2 && (wc_2 != '\0' || wc_1 != '\0'));
    if (wc_1 > wc_2) {
        return 1;
    } else if (wc_1 == wc_2) {
        return 0;
    } else {
        return -1;
    }
} 

/**
 * Checks if char is first byte of the wchar_t
 * @param c - char that is checked
 * @return bool: True if byte is first
 */


bool check_byte_is_first(char c) 
{
    if (c & (1 << 7) && !(c & (1 << 6))) {
        return false;
    }
    return true;
}

/**
 * Sets i on the right wchar 
 * @param p - pointer on line
 * @param wc - wchar_t variable were to read symbol
 * @param i - index of the char in the line
 */

bool If_Pointer_On_Alpha(char *p, wchar_t *wc, int *i)
{
    wchar_t wc_tmp;
    mbtowc(&wc_tmp,  p + *i, MB_CUR_MAX);
    --*i;
    if (iswalpha(wc_tmp)) {
        *wc = wc_tmp;
        return true;
    } 
    return false;
}

/**
 * Sets pointer on char;
 * @param p - pointer on line
 * @param i - index of the char in the line
 */

void Set_Pointer_On_Char(char *p, int *i)
{
    while (*i >= 0 && !check_byte_is_first(p[*i])) {
        --*i;
    }
}

/**
 * Function that compares two char* pointers. Sort by end of lines.
 * @param a - first pointer
 * @param b - second pointer
 * @return if a > b returns 1, else - 0
 */ 

int Reverse_Cmp(char *a, char *b) 
{
    wchar_t wc_1 = 0, wc_2 = 0;
    int i_a = strlen(a), i_b = strlen(b);
    do {
        wc_1 = 0, wc_2 = 0;
        while (i_a >= 0) {
            Set_Pointer_On_Char(a, &i_a);
            if (If_Pointer_On_Alpha(a, &wc_1, &i_a)) {
                break;
            }
        }
        while (i_b >= 0) {
            Set_Pointer_On_Char(b, &i_b);
            if (If_Pointer_On_Alpha(b, &wc_2, &i_b)) {
                break;
            }
        }
    } while (wc_1 == wc_2 && wc_1 != 0);
    if (wc_1 > wc_2) {
        return 1;
    } else if (wc_1 == wc_2) {
        return 0;
    } else {
        return -1;
    }
}

/**
 * Standard recursive Qsort algorithm
 * @param p - array_of_pointers
 * @param left - left side of sorting array
 * @param right - right side of sorting array
 * @return void
 */

void QuickSort(char **p, int left, int right, int (*cmp)(char *, char *))
{
    char *comp = p[(left + right) / 2];
    char *tmp;
    int i = left, j = right;
    while (i <= j) {
        while(cmp(comp, p[i]) == 1 && i < right){
            i++;
        }
        while(cmp(p[j], comp) == 1 && j > left){
            j--;
        }
        if (i <= j){
            tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
            i++, j--;
        }
    }
    if (left < j) {
        QuickSort(p, left, j, cmp);
    }
    if (i < right) {
        QuickSort(p, i, right, cmp);
    }
}

/**
 * Function that calls qsort algorithm
 * @param p - array_of_pointers
 * @param n - size of array_of_pointers
 * @return void
 */

void My_Qsort(char **p, int n, int (*cmp)(char *, char *))
{
    QuickSort(p, 0, n - 1, cmp);
}

/**
 * Creates reflection of the input file
 * @param file_name - name of the input file
 * @return f reflection on input file
 */

char *File_Mapping(const char *file_name, int *fd, size_t *size) 
{
    struct stat s;
    *fd = open (file_name, O_RDWR);
    if (*fd == -1) {
        fprintf(stderr, "Open failed on input file");
        _exit(1);
    }

    int status = fstat(*fd, &s);
    *size = s.st_size; 
    char *f = mmap(0, *size, PROT_READ | PROT_WRITE, MAP_PRIVATE, *fd, 0);
    if (errno || f == NULL) {
        fprintf(stderr, "error\n");
        _exit(1);
    }
    return f;
}

/**
 * Function that creates array_of_pointers
 * @param text_pointer - mmap reflection on input file
 * @param i - future size of the array_of_pointers
 * @return p array_of_pointers
 */

char **Pointers_Reading(char *text_pointer, size_t *i)
{
    wchar_t wc = 0;
    int length = 0;
    size_t n = START_CONST;
    char **p = calloc(n, sizeof(*p));
    if (!p) {
        _exit(1);
    }
    p[0] = text_pointer;
    while(length = mbtowc(&wc, text_pointer, strlen(text_pointer))) {
        text_pointer += length;
        if (wc == '\n') {
            p[++*i] = text_pointer;
            *(text_pointer - length) = '\0';
        }
        if (*i == n - 1) {
            n *= 2;
            char **buf = p;
            p = realloc(buf, n * sizeof(*p));
            if (!p) {
                free(p);
            }
        }
    }
    return p;
}

/**
 * Parses cmd line by keys:
 * -alph : in alphabetic order
 * -rhm : in rhyme order
 * -orig : creates file with original text
 * -all : creates all types of sorted file
 */

bool Cmd_Read(bool *print_type, int argc, char const *argv[]) 
{
    bool ret = false;
    for (int i = 1; i < argc - 1; ++i) {
        if (strcmp(argv[i], _CMD_ALPHABETIC_) == 0) {
            ret = true;
            print_type[0] = true;
        } else if (strcmp(argv[i], _CMD_RHYME_) == 0) {
            ret = true;
            print_type[1] = true;
        } else if (strcmp(argv[i], _CMD_ORIGIN_) == 0) {
            ret = true;
            print_type[2] = true;
        } else if (strcmp(argv[i], _CMD_ALL_) == 0) {
            ret = true;
            print_type[3] = true;
        } else {
            fprintf(stderr, "ERROR: Unknown command line parameter\n");
            _exit(1);
        }
    }
    return ret;
}