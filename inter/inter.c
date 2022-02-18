#include <unistd.h>

void ft_inter(char *s1, char *str2)
{
	char tab[255] = {0};
	int index;

	index = 0;
	while (str2[index])
	{
		tab[(int)str2[index]] = 1;
		index++;
	}
	index = 0;
	while (s1[index])
	{
		if (tab[(int)s1[index]] == 1)
		{
			write(1, &s1[index],1);
			tab[(int)s1[index]] = 2;
		}
		index++;
	}
	
}
int main(int argc, char *argv[])
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
}