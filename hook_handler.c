/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:43:42 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/02/18 00:39:30 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_handler(int button, t_data *data)
{
	if (button == 53)
		exit(0);
	if (button == 0 || button == 123)
	{
		go_left(data);
		drawing(data);
	}
	else if (button == 2 || button == 124)
	{
		go_right(data);
		drawing(data);
	}
	else if (button == 13 || button == 126)
	{
		go_up(data);
		drawing(data);
	}
	else if (button == 1 || button == 125)
	{
		go_down(data);
		drawing(data);
	}
	return (0);
}
