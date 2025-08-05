/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_basef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:46:51 by maleca            #+#    #+#             */
/*   Updated: 2025/08/02 01:59:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_basef(unsigned long long nb, char *base, size_t *count)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
		ft_putnbr_basef(nb / base_len, base, count);
	ft_putcharf(base[nb % base_len], count);
}

// int	main(int ac,  char **av)
// {
// 	size_t	count = 0;

// 	(void)ac;
// 	ft_putnbr_basef(atoi(av[1]), "0123456789abcdef", &count);
// 	return (0);
// }
