#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main()
{
	printf("%d abcd %s %13d %013d\n", 13, "abcd", 13, 14);
	ft_printf("%d abcd %s %13d %013d\n", 13, "abcd", 13, 14);
	return (0);
}
