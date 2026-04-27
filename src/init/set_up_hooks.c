/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:54:43 by jromann           #+#    #+#             */
/*   Updated: 2026/04/27 15:02:07 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_up_hooks(t_user *user)
{
	mlx_hook(user->mlx_win, 6, 1L << 6, mouse_hook, user);
	mlx_hook(user->mlx_win, 8, 1L << 5, mouse_left_win_hook, user);
	mlx_hook(user->mlx_win, 2, 1L << 0, key_press_hook, user);
	mlx_hook(user->mlx_win, 3, 1L << 1, key_release_hook, user);
	mlx_hook(user->mlx_win, 17, 0, close_hook, user);
}
