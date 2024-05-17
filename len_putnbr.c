#include <unistd.h>
#include <stdio.h>

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

int	len_putnbr(long nbr)
{
	int	len;
	
	len = int_len(nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	else if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr > 9)
	{
		len_putnbr(nbr / 10);
		write_nbr(nbr % 10);
	}
	else if (nbr > 0)
		write_nbr(nbr);
	return (len);
}
/*
int main(){
	printf("%d\n", len_putnbr(-2147483648));
}
*/
