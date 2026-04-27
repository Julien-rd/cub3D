/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_validate_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:56:37 by jromann           #+#    #+#             */
/*   Updated: 2026/04/27 15:02:07 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_and_validate_map(char *input, t_user *user)
{
	size_t	iter;

	iter = map_exists(input, user);
	check_empty_lines(&input[iter], input, user);
	user->info = ft_split(input, '\n');
	user->map = ft_split(&input[iter], '\n');
	free(input);
	if (user->map == NULL || user->info == NULL)
		exit_game(user, PERROR, "create_and_validate_map");
	valid_map(user);
}
