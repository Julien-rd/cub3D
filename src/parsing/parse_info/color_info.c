/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:01:41 by jromann           #+#    #+#             */
/*   Updated: 2026/04/27 15:02:07 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_2dlen(t_user *user, char **colors)
{
	size_t	i;

	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (free2d(colors), exit_game(user, ERROR,
				"Invalid colour: not 3 rgb values specified"));
}

static char	**prepare_color_info(t_user *user, size_t pos)
{
	char	**colors;
	char	**trim_colors;
	size_t	i;

	i = 0;
	if (check_commas(&user->info[pos][1]) == -1)
		exit_game(user, ERROR, "Invalid colour: too many commas detected");
	colors = ft_split(&user->info[pos][1], ',');
	if (!colors)
		exit_game(user, PERROR, "color_info");
	check_2dlen(user, colors);
	trim_colors = (char **)ft_calloc(sizeof(char *), 4);
	if (!trim_colors)
		return (free2d(colors), exit_game(user, PERROR, "color_info"), NULL);
	while (colors[i])
	{
		trim_colors[i] = ft_strtrim(colors[i], " ");
		if (!trim_colors[i])
			return (free2d(trim_colors), free2d(colors), exit_game(user, PERROR,
					"color_info"), NULL);
		i++;
	}
	return (free2d(colors), trim_colors);
}

static void	validate_colors(t_user *user, char **colors)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (colors[row])
	{
		col = 0;
		while (colors[row][col])
		{
			if (!ft_isdigit(colors[row][col]))
				return (free2d(colors), exit_game(user, ERROR,
						"Invalid colour: non-digit char found in number"));
			col++;
		}
		row++;
	}
}

static void	convert_colors(t_user *user, char **colors, char flag)
{
	if (flag == 'F')
	{
		user->floor.red = s_atoi(colors[0]);
		user->floor.green = s_atoi(colors[1]);
		user->floor.blue = s_atoi(colors[2]);
		if (user->floor.red == -1 || user->floor.blue == -1
			|| user->floor.green == -1)
			return (free2d(colors), exit_game(user, ERROR,
					"Invalid colour: F rgb not in range[0,255] or missing"));
	}
	if (flag == 'C')
	{
		user->ceiling.red = s_atoi(colors[0]);
		user->ceiling.green = s_atoi(colors[1]);
		user->ceiling.blue = s_atoi(colors[2]);
		if (user->ceiling.red == -1 || user->ceiling.blue == -1
			|| user->ceiling.green == -1)
			return (free2d(colors), exit_game(user, ERROR,
					"Invalid colour: C rgb not in range[0,255] or missing"));
	}
}

void	color_info(t_user *user, char flag, size_t pos)
{
	char	**colors;

	colors = prepare_color_info(user, pos);
	validate_colors(user, colors);
	convert_colors(user, colors, flag);
	free2d(colors);
}
