/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:19:11 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/02/19 14:45:49 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_var(t_var *var)
{
	var->e = 0;
	var->p = 0;
	var->c = 0;
	var->i = 0;
	var->j = 0;
}

int	check_if_map_is_valid(char **map)
{
	t_var	var;

	init_var(&var);
	while (map[var.i])
	{
		var.j = 0;
		while (map[var.i][var.j])
		{
			if (map[var.i][var.j] == 'E')
				var.e++;
			else if (map[var.i][var.j] == 'P')
				var.p++;
			else if (map[var.i][var.j] == 'C')
				var.c++;
			var.j++;
		}
		var.i++;
	}
	if (var.p == 1 && var.e == 1 && var.c >= 1)
		return (1);
	else
		return (perror("Invalid map"), exit(0), 0);
}

int	check_if_map_is_rectangular(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (perror("Invalid map"), exit(0), 0);
		i++;
	}
	return (1);
}

int	check_if_map_is_closed(char **map)
{
	int	j;
	int	i;

	j = -1;
	while (map[0][++j])
	{
		if (map[0][j] != '1')
			return (perror("Invalid map"), exit(0), 0);
	}
	i = 0;
	while (map[++i])
	{
		if (map[i][j - 1] != '1')
			return (perror("Invalid map"), exit(0), 0);
	}
	i = -1;
	while (map[++i])
	{
		if (map[i][0] != '1')
			return (perror("Invalid map"), exit(0), 0);
	}
	j = ft_strncmp(map[i - 1], map[0], ft_strlen(map[0]));
	if (j != 0)
		return (perror("Invalid map"), exit(0), 0);
	return (1);
}

int	check_an_other_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
			&& map[i][j] != 'C' && map[i][j] != 'E')
				return (perror("Pierced map"), exit(0), 0);
			j++;
		}
		i++;
	}
	return (1);
}
