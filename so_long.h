/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:02:30 by maleca            #+#    #+#             */
/*   Updated: 2025/08/08 22:51:14 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include "mlx/mlx.h"
# include "lib/libft.h"

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
}			t_data;

typedef struct s_map
{
	char		**area;
	size_t		heigth;
	size_t		width;
	t_point		e_pos;
	t_point		p_pos;
	int			c_count;
}				t_map;

int		main(int ac, char **av);
void	so_long(char **av);

t_map	*parse(char **av);
t_map	*open_and_duplicate(char **av);
int		is_char_valid(t_map *area);
int		is_map_enclosed(t_map *area);
int		is_map_solvable(t_map *area, int map_content[2]);
	
void	print_error(char *err_msg);
void	print_close_error(char *err_msg, int fd);
void	print_free_error(char *err_msg, t_map *area);

void	print_tab(char **zone);

#endif