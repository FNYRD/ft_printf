#include <ctype.h>	
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
    char **matriz;
	int	i;

	matriz = ft_split("hola,que,tal", ',');
	if (!matriz)
		return (0);
	i = -1;
	while (matriz[++i])
		printf("indice: %d\nContenido:%s\n", i, matriz[i]);
	i = -1;
	while (matriz[++i])
	{
		free(matriz[i]);
	}
	free(matriz);
	return (0);
}