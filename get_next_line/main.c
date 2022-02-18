#include "get_next_line.h"
int main()
{
	int fd;
	char *line;

	fd  = open("get_next_line.c", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s",line);
} 