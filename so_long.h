/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:07:27 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/02/18 00:13:36 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<fcntl.h>
# include	"get_next_line.h"
# include	<mlx.h>
# include	"libft/libft.h"

# define WL "./ textures/wall.xpm"
# define PL "./ textures/player.xpm"
# define BG "./ textures/empty.xpm"
# define CL "./ textures/collect.xpm"
# define EX "./ textures/door.xpm"

typedef struct data
{
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_empty;
	void	*img_player;
	void	*img_collect;
	void	*img_door;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	char	**map;
	char	**invalid_map;
	int		moves;
	int		nb_collect;
}	t_data;

typedef struct s_var
{
	int	i;
	int	j;
	int	e;
	int	p;
	int	c;
}	t_var;

char	**read_dote_ber_file(char *file_dote_ber);
int		check_if_map_is_valid(char **map);
int		check_if_map_is_rectangular(char **map);
int		check_if_map_is_closed(char **map);
void	drawing(t_data *info);
void	go_left(t_data *data);
void	go_right(t_data *data);
void	go_up(t_data *data);
void	go_down(t_data *data);
int		if_the_path_is_valid(char **map);
int		check_an_other_character(char **map);
int		hook_handler(int button, t_data *data);

#endif