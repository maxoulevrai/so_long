/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:32:31 by maleca            #+#    #+#             */
/*   Updated: 2025/08/02 02:05:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		size;

	size = 0;
	if (!lst)
		return (0);
	p = lst;
	while (p)
	{
		size++;
		p = p->next;
	}
	return (size);
}

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew("alors");
// 	t_list *node2 = ft_lstnew("alors");
// 	t_list *node3 = ft_lstnew("alors");

// 	ft_lstadd_front(&node3, node2);
// 	ft_lstadd_front(&node2, node1);
// 	printf("%d\n", ft_lstsize(node1));
// 	return (0);
// }
