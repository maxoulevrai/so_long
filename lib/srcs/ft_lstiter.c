/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:13:08 by maleca            #+#    #+#             */
/*   Updated: 2025/05/09 19:43:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// static void	del(void *ptr)
// {
// 	size_t			i;
// 	// char	*p;

// 	i = 0;
// 	// p = (char *)ptr;
// 	while (((char *)ptr)[i])
// 	{
// 		((char *)ptr)[i] = '\0';
// 		i++;
// 	}
// }

// static void	rotone(void *str)
// {
// 	size_t	i;
// 	char	*s;

// 	i = 0;
// 	s = (char *)str;
// 	while (s[i])
// 	{
// 		s[i] += 1;
// 		i++;
// 	}
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew(ft_strdup("et"));
// 	t_list *node2 = ft_lstnew(ft_strdup("no"));
// 	t_list *node3 = ft_lstnew(ft_strdup("alors"));

// 	ft_lstadd_back(&node1, node2);
// 	ft_lstadd_back(&node1, node3);
// 	ft_lstiter(node1, &rotone);
// 	printf("%s\n", (char *)node1->content);
// 	printf("%s\n", (char *)node2->content);
// 	printf("%s\n", (char *)node3->content);
// 	ft_lstclear(&node1, &del);
// 	return (0);
// }
