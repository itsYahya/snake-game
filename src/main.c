/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:32:45 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/23 20:14:25 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "snake.h"

int	main(void)
{
	t_data	data;
	
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 700, 700, "The Snake");
	mlx_loop(data.mlx);
	return (0);
}