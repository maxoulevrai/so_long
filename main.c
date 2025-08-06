/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:03:38 by maleca            #+#    #+#             */
/*   Updated: 2025/08/06 22:58:14 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char **av)
{
	char **map;

	map = parse(av);
	
}

int	main(int ac, char **av)
{
	if (ac < 2)
		print_error("Too few arguments");
	if (ac > 2)
		print_error("Too many arguments");
	open_and_check(av);
}
