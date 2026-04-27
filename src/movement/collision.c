/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:35:54 by jromann           #+#    #+#             */
/*   Updated: 2026/04/27 15:02:07 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda.h"

static bool	is_wall_at(t_user *user, double x, double y)
{
	return (user->map[(int)y][(int)x] == '1');
}

bool	check_collision(t_user *user, double x, double y)
{
	double	buf;

	buf = 0.1;
	if (is_wall_at(user, x - buf, y - buf))
		return (true);
	if (is_wall_at(user, x + buf, y - buf))
		return (true);
	if (is_wall_at(user, x - buf, y + buf))
		return (true);
	if (is_wall_at(user, x + buf, y + buf))
		return (true);
	return (false);
}
