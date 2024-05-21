#include <unistd.h>

static int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

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