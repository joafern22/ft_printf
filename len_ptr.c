#include <unistd.h>

int     len_putnbr_hexa(int nbr, char format);
int     len_putstr(char *string);

int     len_ptr(void *ptr)
{
    return (len_putstr("0x") + len_putnbr_hexa((long)ptr, 'p'));
}