/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:00:01 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/05/23 21:31:41 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
#define SNAKE_H

#define WIDTH 900
#define HEIGHT 400

typedef enum e_type
{
	TP_PLAYER = 0,
	TP_COLL = 1,
	TP_GROUND = 2,
	TP_WALL = 3
}	t_type;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*imgs[4];
}	t_data;

void	ft_initimgs(t_data *data);
void	ft_init(t_data *data);

#endif