/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:59:49 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/27 17:02:09 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"
#include "events.h"
#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_movehead(t_data *data)
{
	int	x, y;
	static int counter = 0;
	
	if (data->died)
		return (0);
	if (counter == 800)
	{
		x = data->x;
		y = data->y;
		if (data->type == TP_X && ((data->x > 1 && data->d < 0) || (data->d > 0 && data->x < WIDTH - 2)))
		{
			x = data->x + (data->d);
		}
		else if (data->type == TP_Y && ((data->d < 0 && data->y > 4) || (data->d > 0 && data->y < HEIGHT - 2)))
		{
			y = data->y + (data->d);
		}
		if ((x == data->x && data->y == y && data->start) || (data->map[y][x] == 'P' && data->start))
		{
			data->died = 1;
			printf("you lost body!");
			sleep(2);
			ft_exit(data);
		}
		else if (data->start)
		{
			if ('C' == data->map[y][x])
			{
				data->collect++;
				data->score++;
				if (data->str)
					free(data->str);
				data->str = ft_itoa(data->score);
				ft_clear(data);
				mlx_string_put(data->mlx, data->win, 3 * 10, 1, 0, data->str);
			}
			mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_PLAYER], x * 10, y * 10);
			data->map[y][x] = 'P';
			data->x = x;
			data->y = y;
			ft_lstaddfront(&data->head, ft_lstnew(x, y));
			if (data->collect > 0)
			{
				ft_putplayerinplace(data);
				data->collect--;
			}
			else
				ft_newlast(data);
		}
		counter = 0;
	}
	counter++;
	return (0);
}

void	ft_newlast(t_data *data)
{
	int	y = data->last->contenet->y, x = data->last->contenet->x;
	t_list	*tmp;
	
	data->map[y][x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_GROUND], x * 10, y * 10);
	tmp = data->last->previous;
	free(data->last->contenet);
	free(data->last);
	data->last = tmp;
}

void	ft_clear(t_data *data)
{
	int	x = 1, y = 0;
	
	while (y < 3)
	{
		x = 1;
		while (x < 15)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_GROUND], x * 10, y * 10);
			x++;
		}
		y++;
	}
}
