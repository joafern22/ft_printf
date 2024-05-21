#include <unistd.h>

static void	write_nbr(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

static int	int_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	len_putnbr_unsigned(unsigned int nbr, char format)
{
	int	len;
	
	len = int_len(nbr);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr > 9)
	{
		len_putnbr_unsigned(nbr / 10, format);
		write_nbr(nbr % 10);
	}
	else if (nbr > 0)
		write_nbr(nbr);
	return (len);
}