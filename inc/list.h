/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:49:48 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/26 14:07:59 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

typedef	struct s_cord
{
	int	x;
	int	y;
}	t_cord;


typedef struct s_list
{
	t_cord			*contenet;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

t_list	*ft_lstnew(int x, int y);
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	ft_lstaddback(t_list *head, t_list *new);
void	ft_lstaddfront(t_list **head, t_list *new);

#endif