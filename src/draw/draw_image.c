/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:44:11 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/07 15:03:44 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

static t_image	*get_texture(t_user *user, t_dda *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x >= 0)
			return (&user->tex.e);
		return (&user->tex.w);
	}
	else
	{
		if (ray->dir.y >= 0)
			return (&user->tex.s);
		return (&user->tex.n);
	}
}

static void	init_draw(t_user *user, t_dda *ray, t_draw *wall)
{
	int		line_height;
	double	wall_x;

	ft_bzero(wall, sizeof(t_draw));
	if (ray->perp_dist_wall == 0.0)
		ray->perp_dist_wall = 0.0001;
	line_height = (int)(SCREEN_HEIGHT / ray->perp_dist_wall);
	wall->start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall->start < 0)
		wall->start = 0;
	wall->end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (wall->end >= SCREEN_HEIGHT)
		wall->end = SCREEN_HEIGHT - 1;
	wall->tex = get_texture(user, ray);
	if (ray->side == 0)
		wall_x = ray->map.x + ray->perp_dist_wall * ray->dir.x;
	else
		wall_x = ray->map.y + ray->perp_dist_wall * ray->dir.y;
	wall_x -= floor(wall_x);
}

static void	draw_vertical(t_user *user, t_dda *ray, int x)
{
	t_draw	wall;
	int		y;

	y = 0;
	init_draw(user, ray, &wall);
	while (y < wall.start)
	{
		ft_put_pixel(x, y, user, user->ceiling.colour);
		y++;		
	}
	y = wall.end + 1;
	while (y < SCREEN_HEIGHT)
	{
		ft_put_pixel(x, y, user, user->floor.colour);
		y++;
	}
}

void	draw_image(t_user *user)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		draw_vertical(user, user->ray[x], x);
		x++;
	}
}
