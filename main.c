/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:04:37 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/14 23:04:48 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	close_prog(t_var *var)
{
	mlx_destroy_window(var->mlx_ptr, var->mlx_win);
	exit(1);
	return (0);
}

int main(int argc, char **argv)
{
	t_var	var;

	if (argc < 2 || ft_strstr(argv[1], ".ber") == NULL)
		error_handler("Error: too few arguments or .ber map not found");
	var.mlx_ptr = mlx_init();
	map(&var, argv[1]);
	var.mlx_win = mlx_new_window(var.mlx_ptr, var.width * 50, var.height * 50, "So-long");
	create_map(&var);
	mlx_key_hook(var.mlx_win, events, &var);
	mlx_hook(var.mlx_win, 17, 0, close_prog, &var);
	mlx_loop(var.mlx_ptr);
}