/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 01:21:23 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/02/17 08:43:33 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	check_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' && (map[i - 1][j] == 'P' ||
			map[i + 1][j] == 'P'
			|| map[i][j + 1] == 'E' || map[i][j - 1] == 'P'))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static	void	replace_by_p(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (map[i - 1][j] == 'P' ||
			map[i + 1][j] == 'P'
			|| map[i][j + 1] == 'P' || map[i][j - 1] == 'P'))
			{
				map[i][j] = 'P';
			}
			else if (map[i][j] == 'C' && (map[i - 1][j] == 'P' ||
			map[i + 1][j] == 'P'
			|| map[i][j + 1] == 'P' || map[i][j - 1] == 'P'))
			{
				map[i][j] = 'P';
			}
			j++;
		}
		i++;
	}
}

static	int	check_walls(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (map[i - 1][j] == 'P' ||
			map[i + 1][j] == 'P'
			||map[i][j + 1] == 'P' || map[i][j - 1] == 'P'))
			{
				return (1);
			}
			else if (map[i][j] == 'C' && (map[i - 1][j] == 'P' ||
			map[i + 1][j] == 'P'
			||map[i][j + 1] == 'P' || map[i][j - 1] == 'P'))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static	int	check_c(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	if_the_path_is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check_walls(map, i, j))
	{
		replace_by_p(map, i, j);
	}
	if (check_exit(map) && check_c(map, i, j))
	{
		return (1);
	}
	return (0);
}
