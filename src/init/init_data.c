/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 11:38:38 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/27 15:38:51 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

static void	free_rays(t_user *user, int i)
{
	while (i >= 0)
	{
		free(user->ray[i]);
		i--;
	}
	free(user->ray);
	user->ray = NULL;
}

void	init_data(t_user *user)
{
	int	i;

	i = 0;
	ft_bzero(user, sizeof(t_user));
	user->start_dir = 'D';
	user->floor.red = -1;
	user->floor.blue = -1;
	user->floor.green = -1;
	user->ceiling.red = -1;
	user->ceiling.blue = -1;
	user->ceiling.green = -1;
	user->key.mouse_pos = SCREEN_WIDTH / 2;
	user->ray = ft_calloc(SCREEN_WIDTH, sizeof(t_dda *));
	if (!user->ray)
		exit_game(user, PERROR, "Init_data failure");
	while (i < SCREEN_WIDTH)
	{
		user->ray[i] = ft_calloc(1, sizeof(t_dda));
		if (!user->ray[i])
		{
			free_rays(user, i);
			exit_game(user, PERROR, "Init_data failure");
		}
		i++;
	}
}
