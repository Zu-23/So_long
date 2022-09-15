/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:04:37 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/15 19:41:25 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_var	var;

	if (argc < 2 || argc > 2 || ft_strstr(argv[1], ".ber") == NULL)
		error_handler("Error\nToo many or too few args or invalid map extension", NULL);
	var.mlx_ptr = mlx_init();
	map(&var, argv[1]);
	var.mlx_win = mlx_new_window(var.mlx_ptr, var.width * 50, var.height * 50, "So-long");
	create_map(&var);
	mlx_key_hook(var.mlx_win, events, &var);
	mlx_hook(var.mlx_win, 17, 0, open_exit, &var);
	mlx_loop(var.mlx_ptr);
	system("leaks executablename");
}