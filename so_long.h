/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:04:05 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/15 19:35:25 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef  SO_LONG_H
#   define  SO_LONG_H

#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include "get_next_line/get_next_line.h"
#include <mlx.h>
#include "lib/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct variables
{
	int		i;
	int		j; 
	int		k;
	int		x;
	int		y;
	int		width;
	int		height;
	int		collect;
	char 	**matrix;
	void    *mlx_ptr;
	void    *mlx_win;
	void	*img_ptr;
}t_var;

typedef struct components
{
	int	p_e;
	int	col;
}t_comp;

void	error_handler(char *str, char **matrix);

/*		movements	*/
void	event_render(t_var *var, char *str);
int		open_exit(t_var *var);
int		events(int key, t_var *var);
void	left(t_var *var);
void	up(t_var *var);
void	down(t_var *var);
void	right(t_var *var);

/*		map checking	*/
void    map(t_var *var, char *str);
void	map_is_rectangular(char **matrix, int height);
void	wall(char **matrix, int height);
void	components(char **matrix, int height);

/*		map creation	*/
void	render_image(t_var *var, char *img);
void	sprite_image(char tile, t_var *var);
void	create_map(t_var *var);

#endif