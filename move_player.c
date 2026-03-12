/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:35:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/12 16:35:41 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	move_player(t_user *user)
{
	int	new_x;
	int	new_y;
	int	move_x;
	int	move_y;

	move_x = user->key.w - user->key.s;
	move_y = user->key.d - user->key.a;
	new_x = user->player_pos.x *move_x + user->player_pos.y * move_x;
	new_y = user->player_pos.x *move_y + user->player_pos.y * move_y;
	if (!check_collision(user, new_x, new_y))
	{
		user->player_pos.x = new_x;
		user->player_pos.y = new_y;
	}
	if (user->key.arr_l)
		rotate_left(user);
	if (user->key.arr_r)
		rotate_right(user);
}
