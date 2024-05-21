#include <unistd.h>
#include <stdio.h>

static int	write_hexa(unsigned int nbr, char *base)
{
	int len;

	len = 0;
	if (nbr >= 16)
	{
		len = write_hexa(nbr / 16, base);
		write (1, &base[nbr % 16], 1);
	}
	else if (nbr < 16)
		write (1, &base[nbr], 1);
	len++;
    return (len);
}

int     len_putnbr_hexa(int nbr, char format)
{
	char *	base;
	unsigned int	u;
    int len;

    len = 0;
	base = "0123456789abcdef";
    if (format == 'X')
        base = "0123456789ABCDEF";
	if (nbr < 0)
	{
		write (1, "-", 1);
		u = -nbr;
		len++;
	}
	if (nbr > 0)
		u = nbr;
	if (nbr == 0)
    {
		write (1, &base[0], 1);
        return (1);
    }
	else if (u > 0)
		len += write_hexa(u, base);
    return (len);
}
/*
int main()
{
    printf("%d\n", len_putnbr_hexa(-2147483648, 'x'));
}*/
