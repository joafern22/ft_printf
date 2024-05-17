#include <unistd.h>

int	ft_strlen(char *string);

int	len_putstr(char *s)
{
	int	len;
	
	len = ft_strlen(s);
	write(1, s,len);
	return (len);
} 
/*
int	main(){
	len_putstr("Hello World");
}*/