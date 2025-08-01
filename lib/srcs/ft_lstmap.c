/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 03:43:00 by maleca            #+#    #+#             */
/*   Updated: 2025/05/20 16:33:04 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// void	del(void *element)
// {
// 	free(element);
// }

// void	*rotone(void *str)
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
// 	return (s);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (first)
			{
				new = first->next;
				(*del)(first->content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

// int main(void)
// {
// 	t_list		*elem;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*elem4;
// 	t_list		*list;
// 	char		*str = strdup("lorem");
// 	char		*str2 = strdup("ipsum");
// 	char		*str3 = strdup("dolor");
// 	char		*str4 = strdup("sit");

// 	elem = ft_lstnew(str);
// 	elem2 = ft_lstnew(str2);
// 	elem3 = ft_lstnew(str3);
// 	elem4 = ft_lstnew(str4);
// 	elem->next = elem2;
// 	elem2->next = elem3;
// 	elem3->next = elem4;
// 	list = ft_lstmap(elem, &rotone, &del);
// 	while (list)
// 	{
// 		printf("%s\n", (char *)list->content);
// 		list = list->next;
// 	}
// 	ft_lstclear(&list, &del);
// 	ft_lstclear(&elem, &del);
// 	return (0);
// }
