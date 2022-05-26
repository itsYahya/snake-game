/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:49:08 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/26 14:07:41 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstnew(int x, int y)
{
	t_list	*new;
	t_cord	*content;
	
	new = (t_list *)malloc(sizeof(t_list));
	content = (t_cord *)malloc(sizeof(t_cord));
	if (!new)
		return (0);
	content->x = x;
	content->y = y;
	new->contenet = (t_cord *)content;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
