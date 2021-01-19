#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
 {
	char *line;
	int a;
	int fd;

	fd = open("test.txt", O_RDONLY);
	a = get_next_line(fd, &line);
    while (a == 1)
    {
        printf("%s\n\n%d\n", line, a);
        a = get_next_line(fd, &line);
    }
 }