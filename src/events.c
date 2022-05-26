/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:17:33 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/25 14:18:40 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

void	ft_setevents(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop_hook(data->mlx, ft_movehead, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
}

int	ft_exit(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	key_hook(int button, t_data *data)
{
	if ((button == 123 || button == 124) && (data->type == TP_Y || !data->start))
	{
		data->d = 1;
		if (button == 123)
			data->d = -1;
		data->type = TP_X;
	}
	else if ((button == 125 || button == 126) && (data->type == TP_X || !data->start))
	{
		data->d = 1;
		if (button == 126)
			data->d = -1;
		data->type = TP_Y;
	}
	else if (button == 53)
		ft_exit(data);
	data->start = 1;
	return (0);
}