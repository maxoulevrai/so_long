/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:15:06 by maleca            #+#    #+#             */
/*   Updated: 2025/08/12 21:35:25 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "test.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init;

	win = mlx_new_window(mlx, 1920, 1080, "Ayo");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF000);
	mlx_put_image_to_window(mlx, win, img.img, 5, 5);
	mlx_loop(mlx);
	return (0);
}