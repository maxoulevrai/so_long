/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:44:26 by maleca            #+#    #+#             */
/*   Updated: 2025/08/02 02:05:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list	*head;
	t_list	*nxt;

	head = ft_lstnew("alo");
	nxt = ft_lstnew("non");
	ft_lstadd_front(&head, nxt);
	printf("%s\n", (char *)head->content);
	printf("%s\n", (char *)head->next->content);
	free(head->next);
	free(head);
	return (0);
}
