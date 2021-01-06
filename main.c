#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
 {
	char *line;
	int a;
	int fd;

	fd = open("text2.txt", O_RDONLY);
	a = get_next_line(fd, &line);
	printf("%s\n\n%d\n", line, a);
 }