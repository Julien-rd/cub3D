/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:29:29 by vmanuyko          #+#    #+#             */
/*   Updated: 2026/03/16 15:22:32 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	error_exit(char *mes)
{
	ft_putendl_fd(mes, 2);
	exit(1);
}

void	validate_file_extension(char *file_name)
{
	char	*ret;

	ret = ft_strnstr(file_name, ".cub", ft_strlen(file_name));
	if (!ret)
		error_exit("Error\ninvalid input format");
	if (ft_strlen(ret) > 4)
		error_exit("Error\ninvalid input format");
	ret = ft_strrchr(file_name, '/');
	if (ret)
	{
		if (ft_strlen(ret + 1) < 5)
			error_exit("Error\ninvalid input format");
	}
	if (ft_strlen(file_name) < 5)
		error_exit("Error\ninvalid input format");
}
