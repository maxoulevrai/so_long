/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:15:49 by maleca            #+#    #+#             */
/*   Updated: 2025/08/12 17:17:17 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H

# define TEST_H

# include "../mlx/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
}			t_data;

#endif