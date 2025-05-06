/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:18:10 by lenakach          #+#    #+#             */
/*   Updated: 2025/05/06 13:34:28 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	*f_test(void *ptr)
{
	unsigned char	*str = (unsigned char *)ptr;
	unsigned char	*copy = ft_strdup((char *)str);
	int				i;

	i = 0;
	if (!copy)
		return (NULL);
	while (copy[i])
	{
		if (copy[i] >= 'a' && copy[i] <= 'z')
			copy[i] = copy[i] + 32;
		i++;
	}
	return (copy);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

/*int	main(void)
{
	t_list	*head;

	t_list	*elem1 = malloc(sizeof(t_list));
	elem1->content = ft_strdup("Hello");
	elem1->next = NULL;

	t_list	*elem2 = malloc(sizeof(t_list));
	elem2->content = ft_strdup("Salam");
	elem2->next = NULL;

	ft_lstadd_front(&head, elem1);
	ft_lstadd_front(&head, elem2);

	t_list	*res = ft_lstmap(head, f_test, del_test);

	while (res)
	{
		printf("%s", (unsigned char *)res->content);
		res = res->next;
	}
	return (0);
}*/
