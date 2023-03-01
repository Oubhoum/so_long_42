/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:14:33 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/03/01 15:30:25 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			if (str[i] == '\n')
				return (0);
			i--;
		}
		i++;
	}
	return (1);
}

char	**read_dote_ber_file(char *file_dote_ber)
{
	char	**map;
	char	*s;
	char	*tmp;
	char	*c;
	int		fd;

	fd = open(file_dote_ber, O_RDONLY, 0777);
	s = ft_strdup("");
	c = get_next_line(fd);
	while (c)
	{
		tmp = s;
		s = ft_strjoin(s, c);
		free(tmp);
		free(c);
		c = get_next_line(fd);
	}
	if (check_new_line(s) == 1)
	{
		map = ft_split(s, '\n');
		return (free(s), map);
	}
	return (free(s), perror("Not valid map"), exit(0), map);
}
