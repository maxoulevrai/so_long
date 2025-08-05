/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:52:12 by maleca            #+#    #+#             */
/*   Updated: 2025/08/05 23:36:50 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map_cpy, int x, int y, int info[2])
{
	if (map_cpy[y][x] == 'E')
		info[1] = 1;
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'E')
		return ;
	if (map_cpy[y][x] == 'C')
		info[0]--;
	map_cpy[y][x] = 'F';
	flood_fill(map_cpy, x + 1, y, info);
	flood_fill(map_cpy, x - 1, y, info);
	flood_fill(map_cpy, x, y + 1, info);
	flood_fill(map_cpy, x, y - 1, info);
}
