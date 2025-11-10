#include "ft_printf.h"

void    ft_manager(const char *data, int precision, int width, int flag, char type)
{
    (void)type;
    if (data == 0 && precision == 0)
        data = "";
    if (flag == 0)
        ft_putminzero(data, width, flag);
    else if (flag == 1)
        ft_putminzero(data, width, flag);
    else if (flag == 2)
        ft_dotcase(data, width, precision, 1);
    else if (flag == 3)
        ft_dotcase(data, width, precision, 0);
}
// este codigo funciona bien con numeros.
// crear casos especiales para char, char * y x-X