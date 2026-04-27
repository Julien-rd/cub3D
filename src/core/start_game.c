/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:26:56 by jromann           #+#    #+#             */
/*   Updated: 2026/04/27 15:02:07 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

int	game_loop(t_user *user)
{
	move_player(user);
	ft_bzero(user->tex.img.data, SCREEN_HEIGHT * user->tex.img.line);
	get_rays(user);
	draw_image(user);
	mlx_put_image_to_window(user->mlx, user->mlx_win, user->tex.img.img, 0, 0);
	return (0);
}

void	start_game(t_user *user)
{
	set_up_hooks(user);
	mlx_loop_hook(user->mlx, game_loop, user);
	mlx_loop(user->mlx);
}
