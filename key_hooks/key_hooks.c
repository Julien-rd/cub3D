/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:43 by jromann           #+#    #+#             */
/*   Updated: 2026/03/11 16:14:49 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	close_hook(t_user *user)
{
	cleanup(user, SUCCESS, NULL);
	return (0);
}

int mouse_hook(int x, int y, t_user *user)
{
	(void)y;
	user->key.mouse_pos = x;
    return (0);
}

int mouse_left_win_hook(t_user *user)
{
	user->key.mouse_pos = SCREEN_WIDTH / 2;
	return (0);
}

static int	key_release_hook(int keycode, t_user *user)
{
	if (keycode == KEY_W)
		user->key.w = false;
	if (keycode == KEY_S)
		user->key.s = false;
	if (keycode == KEY_A)
		user->key.a = false;
	if (keycode == KEY_D)
		user->key.d = false;
	if (keycode == KEY_ARR_L)
		user->key.arr_l = false;
	if (keycode == KEY_ARR_R)
		user->key.arr_r = false;
	return (0);
}

static int	key_press_hook(int keycode, t_user *user)
{
	if (keycode == KEY_ESC)
		cleanup(user, SUCCESS, NULL);
	if (keycode == KEY_W)
		user->key.w = true;
	if (keycode == KEY_S)
		user->key.s = true;
	if (keycode == KEY_A)
		user->key.a = true;
	if (keycode == KEY_D)
		user->key.d = true;
	if (keycode == KEY_ARR_L)
		user->key.arr_l = true;
	if (keycode == KEY_ARR_R)
		user->key.arr_r = true;
	return (0);
}

void	set_up_hooks(t_user *user)
{
	mlx_hook(user->mlx_win, 6, 1L << 6, mouse_hook, user);
	mlx_hook(user->mlx_win, 8, 1L << 5, mouse_left_win_hook, user);
	mlx_hook(user->mlx_win, 2, 1L << 0, key_press_hook, user);
	mlx_hook(user->mlx_win, 3, 1L << 1, key_release_hook, user);
	mlx_hook(user->mlx_win, 17, 0, close_hook, user);
}
