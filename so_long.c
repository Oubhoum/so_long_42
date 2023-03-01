/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:13:43 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/03/01 15:35:06 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	nb_collect(char **map)
{
	int	i;
	int	j;
	int	collect_nb;

	i = 0;
	collect_nb = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collect_nb++;
			j++;
		}
		i++;
	}
	return (collect_nb);
}

static	void	handel_25_line(t_data *data, char *av, int i, int j)
{
	data->invalid_map = read_dote_ber_file(av);
	check_if_map_is_valid(data->invalid_map);
	data->map = read_dote_ber_file(av);
	check_if_map_is_rectangular(data->map);
	check_if_map_is_closed(data->map);
	check_an_other_character(data->map);
	if (if_the_path_is_valid(data->invalid_map) == 0)
		return (perror("Invalid path"), exit(0));
	data->mlx = mlx_init();
	data->width = ft_strlen(data->map[0]) * 64;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		i++;
	}
	data->height = i * 64;
}

static	void	if_no_permissions(t_data *vars)
{
	if (vars->img_wall == NULL || vars->img_empty == NULL
		|| vars->img_player == NULL || vars->img_collect == NULL
		||vars->img_door == NULL)
		return (perror("Error !!"), exit(0));
}

int	exit_it(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		j;
	int		wh;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		handel_25_line(&data, argv[1], i, j);
		data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "xyz");
		data.img_wall = mlx_xpm_file_to_image(data.mlx, WL, &wh, &wh);
		data.img_empty = mlx_xpm_file_to_image(data.mlx, BG, &wh, &wh);
		data.img_player = mlx_xpm_file_to_image(data.mlx, PL, &wh, &wh);
		data.img_collect = mlx_xpm_file_to_image(data.mlx, CL, &wh, &wh);
		data.img_door = mlx_xpm_file_to_image(data.mlx, EX, &wh, &wh);
		if_no_permissions(&data);
		data.nb_collect = nb_collect(data.map);
		data.moves = 0;
		drawing(&data);
		mlx_hook(data.mlx_win, 2, 0, hook_handler, &data);
		mlx_hook(data.mlx_win, 17, 0, exit_it, &data);
		mlx_loop(data.mlx);
	}
	return (ft_putstr_fd("error\n", 1), 0);
}
