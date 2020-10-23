#include "headerfile.h"

/**
 * This program is line-by-line sorting of any .txt file
 * As an example you can sort a novel by Alexander Pushkin - Eugene Onegin
 * File with the novel is in Docs folder.
 * Name of the .txt file: Onegin.txt
 *
 * @param text_pointer - Return value of File_Mapping function. 
 * @param text_pointer_tmp - the same pointer as text_pointer
 * @param File_Mapping - Function that creates mmap display char *
 * @param size - Size of array_of_pointers
 * @param array_of_pointers - Array of pointers to the beginning of lines
 * @param Pointers_Reading - Function that creates array_of_pointers to the beginning of lines
 * @param My_Qsort - Function that calls qsort algorithm
 * @param Print_Result - Function that prints sorted text to new result.txt file
 * @param Reset_File - Returns source file to its original state
 * @return Program exit status
 */

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE, "");
    Run_tests();
    int fd;
    size_t size = 0, length;
    if (argc < 1) {
        fprintf(stderr, "Command line error.");
        _exit(1);
    }
    bool print_type[4] = { false, false, false, false };
    if (Cmd_Read(print_type, argc, argv)) {
        char *text_pointer = File_Mapping(argv[argc - 1], &fd, &length), *text_pointer_tmp = text_pointer;
        char **array_of_pointers = Pointers_Reading(text_pointer, &size), **tmp_array = NULL;
        if (print_type[2] || print_type[3]) {
            tmp_array = array_of_pointers;
            Print_Result(tmp_array, size, _FILEPATH_ORIGIN_);
        }
        if (print_type[0] || print_type[3]) {
            tmp_array = array_of_pointers;
            My_Qsort(tmp_array, size + 1, Straight_cmp);
            Print_Result(tmp_array, size, _FILEPATH_ALPHABETIC_);
        }
        if (print_type[1] || print_type[3]) {
            tmp_array = array_of_pointers;
            My_Qsort(tmp_array, size + 1, Reverse_Cmp);
            Print_Result(tmp_array, size, _FILEPATH_RHYME_);
        }
        free(array_of_pointers);
        if (munmap(text_pointer_tmp, length) == -1) {
            _exit(1);
        }
        if (close(fd) == -1) {
            _exit(1);
        }
    }
    return 0;
}