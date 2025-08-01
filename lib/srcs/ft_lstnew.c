/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:21:00 by maleca            #+#    #+#             */
/*   Updated: 2025/05/27 19:53:09 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = value;
	node->next = NULL;
	return (node);
}

// int	main(void)
// {
// 	t_list	*list;

// 	list = ft_lstnew("");
// 	printf("%s\n", (char *)list->content);
// 	printf("%s\n", (char *)list->next);
// 	free(list);
// 	return (0);
// }
