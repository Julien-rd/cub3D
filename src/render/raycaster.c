/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:47:08 by jromann           #+#    #+#             */
/*   Updated: 2026/03/17 15:03:17 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calculate_ray(t_user *user, int screen_x)
{
	t_dda	ray;
	
}

void	draw_ray(t_user *user)
{
	int row;

	ft_memset(user->tex.img.data, 0, SCREEN_HEIGHT * user->tex.img.line);
	row = 0;
	while (row < SCREEN_WIDTH)
	{
		calculate_ray(user, row);
		++row;
	}
}