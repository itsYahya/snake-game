/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:32:45 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/26 16:43:50 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "snake.h"
#include <stdlib.h>

int	main(void)
{
	t_data	data;
	
	data.map = (char **)malloc(sizeof(char *) * HEIGHT);
	ft_init(&data);
	ft_setevents(&data);
	data.start = 0;
	data.collect = 0;
	data.score = 0;
	data.died = 0;
	data.d = 0;
	mlx_loop(data.mlx);
	return (0);
}