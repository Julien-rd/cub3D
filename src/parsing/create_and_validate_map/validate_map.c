/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:41:57 by jromann           #+#    #+#             */
/*   Updated: 2026/04/27 19:01:04 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_char(char c)
{
	if (c != '1' && c != ' ')
		return (1);
	else
		return (0);
}

static int	should_be_a_wall(t_user *user, size_t x, size_t y)
{
	size_t	line_len_above;
	size_t	line_len_below;
	int		ret;

	ret = valid_char(user->map[y][x]);
	if (x == 0 || y == 0)
		return (ret);
	if (user->map[y + 1] == NULL || user->map[y][x + 1] == '\0')
		return (ret);
	line_len_above = ft_strlen(user->map[y - 1]);
	line_len_below = ft_strlen(user->map[y + 1]);
	if ((line_len_above > x && user->map[y - 1][x] == ' ')
		|| (line_len_below > x && user->map[y + 1][x] == ' '))
		return (ret);
	if (line_len_above <= x || line_len_below <= x)
		return (ret);
	if (user->map[y][x - 1] == ' ' || user->map[y][x + 1] == ' ')
		return (ret);
	return (0);
}

static void	player_start_pos(t_user *user, size_t pos, size_t i)
{
	user->start_dir = user->map[pos][i];
	if (user->start_dir == 'N')
	{
		user->player.dir.x = 0;
		user->player.dir.y = -1;
	}
	if (user->start_dir == 'S')
	{
		user->player.dir.x = 0;
		user->player.dir.y = 1;
	}
	if (user->start_dir == 'W')
	{
		user->player.dir.x = -1;
		user->player.dir.y = 0;
	}
	if (user->start_dir == 'E')
	{
		user->player.dir.x = 1;
		user->player.dir.y = 0;
	}
	user->player.pos.x = (double)i + 0.5;
	user->player.pos.y = (double)pos + 0.5;
	user->plane.x = -(FOV_LEN * user->player.dir.y);
	user->plane.y = FOV_LEN * user->player.dir.x;
}

static int	valid_line(t_user *user, size_t pos)
{
	size_t	i;

	i = 0;
	while (user->map[pos][i])
	{
		if (user->map[pos][i] != ' ' && user->map[pos][i] != '1'
			&& user->map[pos][i] != '0')
		{
			if ((user->map[pos][i] == 'N' || user->map[pos][i] == 'S'
					|| user->map[pos][i] == 'E'
					|| user->map[pos][i] == 'W') && user->start_dir == 'D')
				player_start_pos(user, pos, i);
			else
				return (1);
		}
		if (should_be_a_wall(user, i, pos) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	valid_map(t_user *user)
{
	size_t	i;

	i = 0;
	while (user->map[i])
	{
		if (valid_line(user, i) == 1)
			exit_game(user, ERROR, "Invalid info in provided file");
		i++;
	}
}
