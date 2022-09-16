/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:08:22 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/15 21:07:26 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(t_var *var, char *img)
{
	int	w;
	int	h;

	var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, img, &w, &h);
	mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, var->img_ptr,
		var->j * 50, var->i * 50);
}

void	sprite_image(char tile, t_var *var)
{
	if (tile == '1')
		render_image(var, "img/wall.xpm");
	else if (tile == '0')
		render_image(var, "img/grass.xpm");
	else if (tile == 'P')
	{
		render_image(var, "img/grass.xpm");
		render_image(var, "img/player.xpm");
		var->x = var->j;
		var->y = var->i;
	}
	else if (tile == 'E')
		render_image(var, "img/exit.xpm");
	else if (tile == 'C')
	{
		var->collect++;
		render_image(var, "img/grass.xpm");
		render_image(var, "img/collect.xpm");
	}
}

void	create_map(t_var *var)
{
	int	height;

	height = var->height;
	var->i = 0;
	var->collect = 0;
	while (height--)
	{
		var->j = 0;
		while (var->matrix[var->i][var->j] != '\0')
		{
			sprite_image(var->matrix[var->i][var->j], var);
			var->j++;
		}
		var->i++;
	}
}
