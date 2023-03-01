/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:50:51 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/02/17 08:02:20 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	init_var2(t_var *var)
{
	var->i = -1;
	var->j = -1;
}

void	drawing(t_data *info)
{
	t_var	var;

	init_var2(&var);
	while (info->map[++var.i])
	{
		var.j = -1;
		while (info->map[var.i][++var.j])
		{
			if (info->map[var.i][var.j] == '1')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_wall, var.j * 64, var.i * 64);
			else if (info->map[var.i][var.j] == '0')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_empty, var.j * 64, var.i * 64);
			else if (info->map[var.i][var.j] == 'P')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_player, var.j * 64, var.i * 64);
			else if (info->map[var.i][var.j] == 'E')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_door, var.j * 64, var.i * 64);
			else if (info->map[var.i][var.j] == 'C')
				mlx_put_image_to_window(info->mlx, info->mlx_win,
					info->img_collect, var.j * 64, var.i * 64);
		}
	}
}
