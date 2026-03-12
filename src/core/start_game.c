/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:26:56 by jromann           #+#    #+#             */
/*   Updated: 2026/03/12 16:46:47 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	game_loop(t_user *user)
{
	int	mouse_zone;

	if (user->key.w)
		move_forward(user);
	if (user->key.s)
		move_backward(user);
	if (user->key.a)
		move_left(user);
	if (user->key.d)
		move_right(user);
	if (user->key.arr_l)
		rotate_left(user);
	if (user->key.arr_r)
		rotate_right(user);
	mouse_zone = SCREEN_WIDTH / 4;
	if (user->key.mouse_pos > SCREEN_WIDTH / 2 + mouse_zone)
		rotate_right(user);
	if (user->key.mouse_pos < SCREEN_WIDTH / 2 - mouse_zone)
		rotate_left(user);
	draw_ray(user);
	mlx_put_image_to_window(user->mlx, user->mlx_win, user->tex.img.img, 0, 0);
	return (0);
}

void	start_game(t_user *user)
{
	set_up_hooks(user);
	mlx_loop_hook(user->mlx, game_loop, user);
	mlx_loop(user->mlx);
}
