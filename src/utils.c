/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:00:42 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/26 15:42:01 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_initimgs(t_data *data)
{
	int	var;
	data->imgs[TP_PLAYER] = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm", &var, &var);
	data->imgs[TP_COLL] = mlx_xpm_file_to_image(data->mlx, "assets/colct.xpm", &var, &var);
	data->imgs[TP_GROUND] = mlx_xpm_file_to_image(data->mlx, "assets/ground.xpm", &var, &var);
	data->imgs[TP_WALL] = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm", &var, &var);
}

void	ft_putplayerinplace(t_data *data)
{
	int	x, y, xx, yy;
	static int	start = 1;
	
	x = -1;
	while (x < 1 || x > WIDTH - 2)
		x = rand() % WIDTH;
	y = -1;	
	while (y < 4 || y > HEIGHT - 2)
		y = rand() % HEIGHT;
	if (start)
	{
		data->x = x;
		data->y = y;
		data->yy = y;
		data->xx = x;
		data->map[y][x] = 'P';
		data->head = ft_lstnew(x, y);
		data->last = data->head;
		start = 0;
	}
	xx = -1;
	while (xx < 1 || xx > WIDTH - 2 || xx == data->x)
		xx = rand() % WIDTH;
	yy = -1;	
	while (yy < 4 || yy > HEIGHT - 2 || data->map[yy][xx] == 'P')
		yy = rand() % HEIGHT;
	data->map[yy][xx] = 'C';
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_COLL], xx * 10, yy * 10);
}

void	ft_putimgs(t_data *data)
{
	int	index, i;

	index = 0;
	while (index < HEIGHT)
	{
		i = 0;
		data->map[index] = (char *)malloc(sizeof(char) * WIDTH);
		while (i < WIDTH)
		{
			if (index == 3 || index == HEIGHT - 1 || i == 0 || i == WIDTH - 1)
			{
				mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_WALL], i * 10, index * 10);
				data->map[index][i] = '1';
			}
			else
			{
				mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_GROUND], i * 10, index * 10);
				data->map[index][i] = '0';
			}
			i++;
		}
		index++;
	}
	ft_putplayerinplace(data);
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_PLAYER], data->x * 10, data->y * 10);
}

void	ft_init(t_data *data)
{
	data->mlx = mlx_init();
	ft_initimgs(data);
	data->win = mlx_new_window(data->mlx, WIDTH * 10, HEIGHT * 10, "The Snake");
	ft_putimgs(data);
}

int	ft_countdeg(int number)
{
	int	index = 1;

	while (number >= 10)
	{
		index++;
		number /= 10;
	}
	return (index);
}

void	ft_looper(char *table, int index, int number)
{
	if (number >= 10)
		ft_looper(table, index - 1, number / 10);
	table[index] = number % 10 + '0';
}

char	*ft_itoa(int number)
{
	int		count;
	char	*table;

	count = ft_countdeg(number);
	table = (char *)malloc(sizeof(char) * count);
	table[count] = 0;
	ft_looper(table, count - 1, number);
	return (table);
}
