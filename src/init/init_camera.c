/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:50:22 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/24 16:38:28 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

void	init_camera(t_camera *cam, t_user *user)
{
	int	tiles;

	tiles = (MINI_SIZE / MINI_TILE);
	cam->min.x = (int)user->player.pos.x - tiles / 2;
	cam->max.x = cam->min.x + tiles;
	cam->min.y = (int)user->player.pos.y - tiles / 2;
	cam->max.y = cam->min.y + tiles;
}
