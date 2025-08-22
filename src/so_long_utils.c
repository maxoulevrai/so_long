/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:25:07 by maleca            #+#    #+#             */
/*   Updated: 2025/08/09 18:34:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_map *map)
{
	map->area = NULL;
	map->heigth = 0;
	map->width = 0;
	map->c_count = 0;
	map->e_pos.x = 0;
	map->e_pos.y = 0;
	map->p_pos.x = 0;
	map->p_pos.y = 0;
}

void	print_tab(char **zone)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (zone[i])
	{
		j = 0;
		while (zone[i][j])
		{
			printf("%c", zone[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
