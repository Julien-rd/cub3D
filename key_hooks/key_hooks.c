/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:43 by jromann           #+#    #+#             */
/*   Updated: 2026/03/11 12:02:17 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	close_hook(t_user *user)
{
	cleanup(user, SUCCESS, NULL);
	return (0);
}

static int	key_hook(int keycode, t_user *user)
{
	bool	moved;

	moved = 0;
	if (keycode == KEY_ESC)
		cleanup(user, SUCCESS, NULL);
	if (keycode == KEY_W)
		move_forward(user, &moved);
	if (keycode == KEY_S)
		move_backward(user, &moved);
	if (keycode == KEY_A)
		move_left(user, &moved);
	if (keycode == KEY_D)
		move_right(user, &moved);
	if (keycode == KEY_ARR_L)
		rotate_left(user, &moved);
	if (keycode == KEY_ARR_R)
		rotate_right(user, &moved);
	if (moved)
	{
		draw_ray(user);
		mlx_put_image_to_window(user->mlx, user->mlx_win, user->img, 0, 0);
	}
	return (0);
}

void	set_up_hooks(t_user *user)
{
	mlx_hook(user->mlx_win, 2, 1L << 0, key_hook, user);
	mlx_hook(user->mlx_win, 17, 1L << 17, close_hook, user);
}
