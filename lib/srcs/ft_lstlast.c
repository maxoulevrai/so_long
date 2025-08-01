/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:41:54 by maleca            #+#    #+#             */
/*   Updated: 2025/05/09 19:43:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew("et");
// 	t_list *node2 = ft_lstnew("la");
// 	t_list *node3 = ft_lstnew("alors");

// 	ft_lstadd_front(&node3, node2);
// 	ft_lstadd_front(&node2, node1);
// 	printf("%s\n", (char *)ft_lstlast(node1)->content);
// 	return (0);
// }
