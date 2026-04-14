/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:22:16 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/14 12:45:27 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

static void	draw_ray(t_user *user, double angle)
{
	t_vector	paint;
	t_coord		map;
	int			map_height;

	map_height = 0;
	while (user->map[map_height])
		map_height++;
	paint.x = MINI_OFFSET + MINI_SIZE / 2;
	paint.y = MINI_OFFSET + MINI_SIZE / 2;
	while (1)
	{
		paint.x += cos(angle);
		paint.y += sin(angle);
		map.x = ((int)paint.x - MINI_OFFSET) / MINI_TILE;
		map.y = ((int)paint.y - MINI_OFFSET) / MINI_TILE;
		if (map.y < 0 || map.y >= map_height || map.x < 0
			|| map.x >= (int)ft_strlen(user->map[map.y]))
			break ;
		if (user->map[map.y][map.x] == '1')
			break;
		ft_put_pixel((int)paint.x, (int)paint.y,user, GREEN);
	}
}

void	draw_fov(t_user *user)
{
	int		i;
	double	p_angle;
	double	ray_angle;
	double	fov;
	double step;

	i = 0;
	fov = (FOV * PI) / 180;
	while(i < SCREEN_WIDTH)
	{
		step = i * (fov / SCREEN_WIDTH);
		p_angle = atan2(user->player.dir.y, user->player.dir.x);
		ray_angle = p_angle - (fov / 2) + step;
		draw_ray(user, ray_angle);
		i++;
	}
}
