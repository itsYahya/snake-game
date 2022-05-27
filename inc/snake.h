/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:00:01 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/27 14:28:27 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
#define SNAKE_H

#define WIDTH 70
#define HEIGHT 40

#include "list.h"

typedef enum e_type
{
	TP_PLAYER = 0,
	TP_COLL = 1,
	TP_GROUND = 2,
	TP_WALL = 3,
	TP_X = 4,
	TP_Y = 5,
}	t_type;

typedef struct s_data
{
	void	*mlx, *win, *imgs[4];
	int		x, y, xx, yy, d, *move, start, collect, score, died;
	char	**map, *str;
	t_type	type;
	t_list	*head;
	t_list	*last;
}	t_data;

void	ft_initimgs(t_data *data);
void	ft_init(t_data *data);
void	ft_setevents(t_data *data);
int		ft_movehead(t_data *data);
void	ft_putplayerinplace(t_data *data);
void	ft_newlast(t_data *data);
char	*ft_itoa(int number);
void	ft_clear(t_data *data);
void	show_alert(t_data *data);

#endif