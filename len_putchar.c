#include <unistd.h>

int	len_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
