/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:19:41 by maleca            #+#    #+#             */
/*   Updated: 2025/08/15 20:50:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, t_point *point, int color)
{
	char	*dst;

	dst = data->addr + (point->y * data->line_length +
		point->x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
