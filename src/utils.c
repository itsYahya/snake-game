/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:00:42 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/23 21:27:10 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"
#include "mlx.h"

void	ft_initimgs(t_data *data)
{
	int	var;
	data->imgs[TP_PLAYER] = mlx_xpm_file_to_image(data->mlx, "/Users/yel-mrab/Desktop/snake-game/assets/player.xpm", &var, &var);
	data->imgs[TP_COLL] = mlx_xpm_file_to_image(data->mlx, "/Users/yel-mrab/Desktop/snake-game/assets/colct.xpm", &var, &var);
	data->imgs[TP_GROUND] = mlx_xpm_file_to_image(data->mlx, "/Users/yel-mrab/Desktop/snake-game/assets/ground.xpm", &var, &var);
	data->imgs[TP_WALL] = mlx_xpm_file_to_image(data->mlx, "/Users/yel-mrab/Desktop/snake-game/assets/wall.xpm", &var, &var);
}

void	ft_putimgs(t_data *data)
{
	int	index;
	int	i;
	int	width;
	int	height;

	width = WIDTH / 10;
	height = HEIGHT / 10;
	index = 0;
	while (index < width)
	{
		i = 0;
		while (i < height)
		{
			if (index == 0 || index == width - 1 || i == 0 || i == height - 1)
				mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_WALL], index * 10, i * 10);
			else
				mlx_put_image_to_window(data->mlx, data->win, data->imgs[TP_GROUND], index * 10, i * 10);
			i++;
		}
		index++;
	}
}

void	ft_init(t_data *data)
{
	data->mlx = mlx_init();
	ft_initimgs(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "The Snake");
	ft_putimgs(data);
}