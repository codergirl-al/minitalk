/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:16:29 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/12 20:45:54 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** @brief append a node to a linked list.
**
** @param lst:  the memory address of the pointer pointing
** to the start of linked list.
** @param back: the node to be appended
*/
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*lista;

	if (lst)
	{
		if (*lst)
		{
			lista = ft_lstlast(*lst);
			lista -> next = new_node;
		}
		else
			*lst = new_node;
	}
}