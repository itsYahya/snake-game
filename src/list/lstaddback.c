/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstaddback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:13:13 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/26 13:51:31 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstaddback(t_list *head, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(head);
	last->next = new;
	new->previous = last;
}