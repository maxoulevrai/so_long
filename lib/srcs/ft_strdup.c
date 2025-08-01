/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:54:53 by maleca            #+#    #+#             */
/*   Updated: 2025/05/09 19:43:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	i;

	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// int	main(void)
// {
// 	char	*dst;

// 	dst = ft_strdup("bomjour");
// 	printf("%s\n", dst);
// 	free(dst);
// 	return (0);
// }
