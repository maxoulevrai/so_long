/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:39:00 by maleca            #+#    #+#             */
/*   Updated: 2025/08/02 02:05:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst && !new)
		return ;
	if (!*lst)
	{
		(*lst) = new;
		return ;
	}
	tmp = (*lst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

// int main(void)
// {
// 	t_list		*head;
// 	t_list		*elem;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*p;
// 	int		chiffre = malloc(sizeof(int));
// 	int		chiffre2 = malloc(sizeof(int));
// 	int		chiffre3 = malloc(sizeof(int));
// 	int		chiffre4 = malloc(sizeof(int));

// 	head = ft_lstnew(chiffre);
// 	elem = ft_lstnew(chiffre2);
// 	elem2 = ft_lstnew(chiffre3);
// 	elem3 = ft_lstnew(chiffre4);
// 	ft_lstadd_back(&head, elem);
// 	ft_lstadd_back(&head, elem2);
// 	ft_lstadd_back(&head, elem3);
// 	p = head;
// 	while (p)
// 	{
// 		printf("%s\n", (char *)p->content);
// 		p = p->next;
// 	}
// 	return (0);
// }