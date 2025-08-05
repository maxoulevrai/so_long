/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:25:42 by maleca            #+#    #+#             */
/*   Updated: 2025/08/02 02:05:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// void	del(void *ptr)
// {
// 	size_t			i;
// 	char	*p;

// 	i = 0;
// 	p = (char *)ptr;
// 	while (((char *)ptr)[i])
// 	{
// 		((char *)ptr)[i] = '\0';
// 		i++;
// 	}
// }

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !(*del))
		return ;
	(*del)(lst->content);
	free(lst);
}

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew(ft_strdup("et"));
// 	t_list *node2 = ft_lstnew(ft_strdup("no"));
// 	t_list *node3 = ft_lstnew(ft_strdup("alors"));

// 	ft_lstadd_front(&node3, node2);
// 	ft_lstadd_front(&node2, node1);
// 	ft_lstdelone(node2, del);
// 	printf("%s\n", (char *)node1->content);
// 	// printf("%s\n", (char *)node2->content);
// 	printf("%s\n", (char *)node3->content);
// 	return (0);
// }
