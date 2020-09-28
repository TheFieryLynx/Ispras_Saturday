#include "head.h"

int main(int argc, char const *argv[])
{
    setlocale (LC_ALL, "ru_RU.UTF-8");
    unsigned char *f;
    int size;
    struct stat s;
    const char *file_name = argv[1];
    int fd = open (argv[1], O_RDWR);

    int status = fstat(fd, & s);
    size = s.st_size;

    f = (char *) mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    const char *str = "Привет";
	wchar_t buf[100];
	mbstowcs(buf, str, sizeof buf / sizeof *buf - 1);
	printf("%s, %ls\n", str, buf);
    return 0;
}