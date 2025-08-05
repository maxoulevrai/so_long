/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:00:49 by maleca            #+#    #+#             */
/*   Updated: 2025/08/02 02:05:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined_args;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	i = -1;
	j = 0;
	joined_args = NULL;
	if (!s1 && !s2)
		return (NULL);
	joined_args = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined_args)
		return (NULL);
	while (s1[++i] && *s1)
		joined_args[i] = s1[i];
	while (s2[j])
		joined_args[i++] = s2[j++];
	joined_args[i] = '\0';
	free((char *)s1);
	return (joined_args);
}

// int	main(void)
// {
// 	char	*dst;
// 	char	*s1 = "my favorite animal is";
// 	char	*s2 = " ";
// 	char	*s3 = "the nyancat";

// 	dst = ft_strjoin(ft_strjoin(s1, s2), s3);
// 	printf("%s\n", dst);
// 	free(dst);
// 	return (0);
// }
