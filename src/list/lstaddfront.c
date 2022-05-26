/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstaddfront.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:18:35 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/26 13:52:03 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstaddfront(t_list **head, t_list *new)
{
	t_list	*head1;

	head1 = *head;
	new->next = head1;
	*head = new;
	head1->previous = new;
}