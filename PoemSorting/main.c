#include "headerfile.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE, "");
    struct stat s;
    const char *file_name = argv[1];
    int fd = open (argv[1], O_RDWR);
    if (fd == -1) {
        perror("Open failed on input file");
        _exit(1);
    }
    int status = fstat(fd, & s);
    int size = s.st_size;
    char *f = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    wchar_t wc = 0;
    int length = mbtowc(&wc, f, strlen(f));
	printf("%lc %d\n", wc, length);
    close(fd);

    
}