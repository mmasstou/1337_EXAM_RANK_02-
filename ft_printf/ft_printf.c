#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>


typedef struct ft_printf
{
	va_list args;
	int		tl;
}		_printf;


int 	ft_printf(const char *format, ... );
void	ft_putchar(int c, _printf *tab);
int		manage_format(_printf *tab, const char *format , int index);
void	ft_puthex(unsigned int nbr , _printf *tab);
void  	ft_putnbr(int nb, _printf *tab);
void 	puthexa(_printf *tab);
void 	putstr(_printf *tab);
void 	putnbr(_printf *tab);

int ft_printf(const char *format, ... )
{
	_printf *tab;
	int		index;


	tab = (_printf *)malloc(sizeof(_printf));
	if (!tab)
		return (0);
	va_start(tab->args,format);
	index = -1;
	while (format[++index])
	{
		if (format[index] == '%')
			index = manage_format(tab, format, index + 1);
		else
			ft_putchar(format[index], tab);
	}
	va_end(tab->args);
	index = tab->tl;
	free(tab);
	return (index);
}

int	manage_format(_printf *tab, const char *format , int index)
{
	if (format[index] == 's')
		putstr(tab);
	else if (format[index] == 'd')
		putnbr(tab);
	else if (format[index] == 'x')
		puthexa(tab);
	return (index);
}

void ft_putchar(int c, _printf *tab)
{
	tab->tl += write(1, &c,1);
}

void putstr(_printf *tab)
{
	char *str;

	str = va_arg(tab->args, char *);
	while (*str)
		ft_putchar(*str++, tab);
}

void 	putnbr(_printf *tab)
{
	int nbr;

	nbr = va_arg(tab->args, int);
	ft_putnbr(nbr, tab);
}

void puthexa(_printf *tab)
{
	unsigned int nb;

	nb = va_arg(tab->args, unsigned int);
	ft_puthex(nb, tab);
}

void  ft_putnbr(int nb, _printf *tab)
{
	unsigned int n;
	if (nb < 0)
	{
		ft_putchar('-', tab);
		n = (unsigned int)(nb * -1);
	}
	else 
	{
		n = (unsigned int)nb;
	}
	if (n >= 10)
		ft_putnbr(n / 10, tab);
	ft_putchar( n % 10 + 48, tab);
}


void ft_puthex(unsigned int nbr , _printf *tab)
{
	if (nbr > 16)
	{
		ft_puthex(nbr / 16, tab);
		ft_puthex(nbr % 16, tab);
	}
	else
	{
		if (nbr > 10)
			ft_putchar(nbr + 48, tab);
		else 
			ft_putchar((nbr - 10) + 'a', tab);
	}
}

int main()
{
	ft_printf("%d\n",2147483647);
}