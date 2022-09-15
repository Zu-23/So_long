/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:52:37 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/15 19:36:17 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right(t_var *var)
{
	if (var->matrix[var->y][var->x + 1] == 'E')
	{
		if (var->collect <= 0)
			open_exit(var);
		
	}
	else if (var->matrix[var->y][var->x + 1] == 'C')
	{
		var->matrix[var->y][var->x + 1] = '0';
		var->collect--;
		event_render(var, "img/grass.xpm");
		var->x++;
		event_render(var, "img/player.xpm");
	}
	else if (var->matrix[var->y][var->x + 1] == '0' || var->matrix[var->y][var->x + 1] == 'P')
	{
		event_render(var, "img/grass.xpm");
		var->x++;
		event_render(var, "img/player.xpm");
	}
}
void	left(t_var *var)
{
	if (var->matrix[var->y][var->x - 1] == 'E')
	{
		if (var->collect <= 0)
			open_exit(var);
	}
	else if (var->matrix[var->y][var->x - 1] == 'C')
	{
		var->matrix[var->y][var->x - 1] = '0';
		var->collect--;
		event_render(var, "img/grass.xpm");
		var->x--;
		event_render(var, "img/player.xpm");
	}
	else if (var->matrix[var->y][var->x - 1] == '0' || var->matrix[var->y][var->x - 1] == 'P')
	{
		event_render(var, "img/grass.xpm");
		var->x--;
		event_render(var, "img/player.xpm");
	}
}
void	up(t_var *var)
{
	if (var->matrix[var->y - 1][var->x] == 'E')
	{
		if (var->collect <= 0)
			open_exit(var);
	}
	else if (var->matrix[var->y - 1][var->x] == 'C')
	{
		var->matrix[var->y - 1][var->x] = '0';
		var->collect--;
		event_render(var, "img/grass.xpm");
		var->y--;
		event_render(var, "img/player.xpm");
	}
	else if (var->matrix[var->y - 1][var->x] == '0' || var->matrix[var->y - 1][var->x] == 'P')
	{
		event_render(var, "img/grass.xpm");
		var->y--;
		event_render(var, "img/player.xpm");
	}
}
void	down(t_var *var)
{
	if (var->matrix[var->y + 1][var->x] == 'E')
	{
		if (var->collect <= 0)
			open_exit(var);
	}
	else if (var->matrix[var->y + 1][var->x] == 'C')
	{
		var->matrix[var->y + 1][var->x] = '0';
		var->collect--;
		event_render(var, "img/grass.xpm");
		var->y++;
		event_render(var, "img/player.xpm");
	}
	else if (var->matrix[var->y + 1][var->x] == '0' || var->matrix[var->y + 1][var->x] == 'P')
	{
		event_render(var, "img/grass.xpm");
		var->y++;
		event_render(var, "img/player.xpm");
	}
}