/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:05:11 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/15 19:08:35 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	components(char **matrix, int height)
{
	t_var var;
	t_comp comp;

	var.i = 0;
	comp.p_e = 0;
	comp.col = 0;
	while (height--)
	{
		var.j = 0;
		while (matrix[var.i][var.j] != '\0')
		{
			if (matrix[var.i][var.j] == 'E' || matrix[var.i][var.j] == 'P')
				comp.p_e++;
			else if (matrix[var.i][var.j] == 'C')
				comp.col++;
			else if (matrix[var.i][var.j] != '1' && matrix[var.i][var.j] != '0')
				error_handler("Error\nwrong type of elements", matrix);
			var.j++;
		}
		var.i++;
	}
	if (comp.p_e != 2 || comp.col == 0)
		error_handler("Error\ntoo many exists or players", matrix);
}

void	wall(char **matrix, int height)
{
	t_var var;

	var.k = height;
	var.j = ft_strlen(matrix[0]);
	var.i = 0;
	while (height--)
	{
		if (matrix[0][var.i] != '1' || matrix[var.k - 1][var.i] != '1')
			error_handler("Error\nmap is not covered in walls", matrix);
		else if (var.i < var.k)
			if (matrix[var.i][0] != '1' || matrix[var.i][var.j - 1] != '1')
				error_handler("Error\nmap is not covered in walls", matrix);
		var.i++;
	}
	components(matrix, var.k);
}

void	map_is_rectangular(char **matrix, int height)
{
	t_var var;

	var.i = 0;
	var.j = ft_strlen(matrix[0]);
	var.k = height;
	if (height < 3 || var.j < 3)
		error_handler("Error\nnot rectangular", matrix);
	while (height--)
	{
		if (var.j != (int) ft_strlen(matrix[var.i]))
			error_handler("Error\nmap not rectangular", matrix);
		else
			var.i++;
	}
	wall(matrix, var.k);
}

void    map(t_var *var, char *str)
{
	int		fd;
	char	*line;
	char 	*matrix_line;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	matrix_line = "";
	var->height = 0;
	if (line == NULL)
		error_handler("Error\nWhile reading the map", NULL);
	while (line)
	{
		var->height++;
		if (line[0] == '\n')
			error_handler("Error\nWhile reading the map", NULL);
		matrix_line = ft_strjoin(matrix_line, line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
	}
	free(line);
	var->matrix = ft_split(matrix_line, '\n');
	map_is_rectangular(var->matrix, var->height);
	var->width = ft_strlen(var->matrix[0]);
}