/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:02:30 by maleca            #+#    #+#             */
/*   Updated: 2025/08/05 23:48:09 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include "mlx/mlx.h"
# include "lib/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
}			t_data;

typedef struct s_point {
	int	x;
	int	y;
}				t_point;


int		main(int ac, char **av);
void	so_long(char **av);

char	**parse(char **av);
char	**open_and_duplicate(char **av);
void	flood_fill(char **map_cpy, int x, int y, int info[2]);

void	error(char *err_msg);
void	close_error(char *err_msg, int fd);
void	free_error(char *err_msg, char **map);

#endif