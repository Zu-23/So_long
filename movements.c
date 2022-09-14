/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:10:58 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/14 23:05:13 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	error_handler(char *str)
{
	perror(str);
	exit(1);
}

void	event_render(t_var *var, char *str)
{
	int	h;
	int	w;
	var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, str, &w, &h);
	mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, var->img_ptr, var->x * 50, var->y * 50);
}

void	open_exit(t_var *var)
{
	ft_printf("CONGRATULATION!!!");
	mlx_destroy_window(var->mlx_ptr, var->mlx_win);
	exit(1);
}

int	events(int key, t_var *var)
{
	static int	move;

	if (key == 2)
		right(var);
	else if (key == 0)
		left(var);
	else if (key == 1)
		down(var);
	else if (key == 13)
		up(var);
	else if (key == 53)
	{
		mlx_destroy_window(var->mlx_ptr, var->mlx_win);
		exit(1);
	}
	else
		error_handler("Wrong key!");

	ft_printf("moves: %d\n", move++);
	return (0);
}