#include "lib.h"

int ft_exit(char *str, int error_code)
{
	ft_write_n(1, str);
	exit(error_code);
}

