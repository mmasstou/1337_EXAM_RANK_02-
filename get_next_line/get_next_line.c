#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	tab[999999];
	char	buffer[1];
	char	*line;
	int		index;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab[index] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		tab[index] = buffer[0];
		tab[index + 1] = '\0';
		if (buffer[index] == '\n')
			break;
		index++;
	}
	if (tab[0] == '\0')
		return (NULL);
	line = (char *)malloc(sizeof(char) * index + 1);
	if (!line)
		return (NULL);
	index = 0;
	while (tab[index])
	{
		line[index] = tab[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

