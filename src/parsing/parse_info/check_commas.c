/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:42:34 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/04/27 15:02:07 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_commas(char *s)
{
	char	*ret;
	char	*tmp;
	int		i;

	i = 0;
	ret = ft_strchr(s, ',');
	while (ret)
	{
		tmp = ret + 1;
		ret = ft_strchr(tmp, ',');
		i++;
	}
	if (i > 2)
		return (-1);
	return (0);
}
