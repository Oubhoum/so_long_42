/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:57:17 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/02/18 00:29:12 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->player_x--;
		ft_putnbr_fd(++data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (data->map[data->player_y][data->player_x - 1] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->player_x--;
		data->nb_collect--;
		ft_putnbr_fd(++data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (data->map[data->player_y][data->player_x - 1] == 'E')
		if (data->nb_collect == 0)
			exit(0);
}

void	go_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->player_x++;
		ft_putnbr_fd(++data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (data->map[data->player_y][data->player_x + 1] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->player_x++;
		data->nb_collect--;
		ft_putnbr_fd(++data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (data->map[data->player_y][data->player_x + 1] == 'E')
		if (data->nb_collect == 0)
			exit(0);
}

void	go_up(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->player_y--;
		ft_putnbr_fd(++data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (data->map[data->player_y - 1][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->player_y--;
		data->nb_collect--;
		ft_putnbr_fd(++data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (data->map[data->player_y - 1][data->player_x] == 'E')
		if (data->nb_collect == 0)
			exit(0);
}

void	go_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] == '0')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->player_y++;
		ft_putnbr_fd(++data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (data->map[data->player_y + 1][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->player_y++;
		data->nb_collect--;
		ft_putnbr_fd(++data->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (data->map[data->player_y + 1][data->player_x] == 'E')
		if (data->nb_collect == 0)
			exit(0);
}
