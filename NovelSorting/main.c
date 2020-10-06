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
    char *text_pointer = File_Mapping(argv[1]), *text_pointer_tmp = text_pointer;
    size_t size = 0;
    char **array_of_pointers = Pointers_Reading(text_pointer, &size);
    if (Select_Type()) {
        My_Qsort(array_of_pointers, size + 1, Straight_cmp);
    } else {
        My_Qsort(array_of_pointers, size + 1, Reverse_Cmp);
    }
    Print_Result(array_of_pointers, size);
    Reset_File(text_pointer_tmp, size);
    free(array_of_pointers);
    return 0;

}