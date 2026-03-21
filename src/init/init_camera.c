/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:50:22 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/21 11:50:40 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dda.h"

void	init_camera(t_camera *cam, t_user *user)
{
	cam->min.x = user->player.pos.x - VIEW_LENGTH;
	cam->max.x = user->player.pos.x + VIEW_LENGTH;
	cam->min.y = user->player.pos.y - VIEW_LENGTH;
	cam->max.y = user->player.pos.y + VIEW_LENGTH;
}
