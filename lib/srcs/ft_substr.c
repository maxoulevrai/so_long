/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:43:05 by maleca            #+#    #+#             */
/*   Updated: 2025/05/09 19:43:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*dst;
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (!src)
		return (NULL);
	if (start >= src_len)
		return (ft_strdup(""));
	if (len > src_len - start)
		len = src_len - start;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	while (i < len && src[start])
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

// int	main(void)
// {
// 	char	*src = "0123456789";
// 	char	*dst;

// 	dst = ft_substr(src, 9, 10);
// 	printf("%s\n", dst);
// 	free(dst);
// 	return (0);
// }
