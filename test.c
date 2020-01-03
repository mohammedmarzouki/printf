#include "ft_printf.h"
#include <stdio.h>

int main()
{
    printf("|%d|",printf("|%*.*s|-------",12,2,"123456789") - 9);
    return (0);
}