/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:35:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/13 13:39:06 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player(t_user *user)
{
	double	new_x;
	double	new_y;
	double	dir_x;
	double	dir_y;

	dir_x = user->key.w - user->key.s;
	dir_y = user->key.d - user->key.a;
	new_x = user->player_pos.x + (dir_x * user->dir_vec.x * MOVE_S);
	new_x += (dir_y * user->plane_vec.x * MOVE_S);
	new_y = user->player_pos.y + (dir_x * user->dir_vec.y  * MOVE_S);
	new_y += (dir_y * user->plane_vec.y * MOVE_S);
	if (!check_collision(user, new_x, user->player_pos.y))
		user->player_pos.x = new_x;
	if (!check_collision(user, user->player_pos.x, new_y))
		user->player_pos.y = new_y;
	if (user->key.arr_l)
		rotate_left(user);
	if (user->key.arr_r)
		rotate_right(user);
}
