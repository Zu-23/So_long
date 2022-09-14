#include<stdio.h>
#include<unistd.h>
#include "mlx.h"
#include "mlx_int.h"
#include "lib/libft.h"
#include "get_next_line/get_next_line.h"
#include<fcntl.h>

typedef struct program
{
	void    *mlx_ptr;
	void    *mlx_win;
	void	*img_ptr;

}t_prog;

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

void	error_handler(char *str)
{
	perror(str);
	exit(1);
}

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
				error_handler("Error wrong type of elements");
			var.j++;
		}
		var.i++;
	}
	if (comp.p_e != 2 || comp.col == 0)
		error_handler("Error too many exists or players");
}

void	wall(char **matrix, int height)
{
	t_var var;

	var.k = height;
	var.j = ft_strlen(matrix[0]);
	while (height--)
	{
		if (matrix[0][var.i] != '1' || matrix[var.k - 1][var.i] != '1')
			error_handler("Error map is not covered in walls");
		else if (var.i < var.k)
			if (matrix[var.i][0] != '1' || matrix[var.i][var.k] != '1')
				error_handler("Error map is not covered in walls");
		var.i++;
	}
	components(matrix, var.k);
}

void	map_is_rectangular(char **matrix, int height)
{
	t_var var;

	var.i = 0;
	var.j = ft_strlen(matrix[var.i]);
	var.k = height;
	if (height < 3 || var.j < 3)
		error_handler("Error not rectangular");
	while (height--)
	{
		if (var.j != (int) ft_strlen(matrix[var.i]))
			error_handler("Error map not rectangular");
		else
			var.i++;
	}
}

void    map(t_var *var, char *str)
{
	int		fd;
	char	*line;
	char 	*matrix_line;
	int		height; 

	fd = open(str,O_RDONLY);
	line = get_next_line(fd);
	matrix_line = "";
	height = 0;
	if (line == NULL)
		error_handler("Error while reading the map file");
	while (line)
	{
		height++;
		matrix_line = ft_strjoin(matrix_line, line);
		line = get_next_line(fd);
	}
	var->matrix = ft_split(matrix_line, '\n');
	map_is_rectangular(var->matrix, height);
	var->height = height;
	var->width = ft_strlen(var->matrix[0]);
}

void	render_image(t_var *var, char *img)
{
	int	w;
	int	h;

	var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, img, &w, &h);
	mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, var->img_ptr, var->j * 50, var->i * 50);
}

void	sprite_image(char tile, t_var *var)
{
	var->collect = 0;
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
void	open_exit(t_var *var)
{
	printf("CONGRATULATION!!!");
	mlx_destroy_window(var->mlx_ptr, var->mlx_win);
}
void	event_render(t_var *var, char *str)
{
	int	h;
	int	w;
	var->img_ptr = mlx_xpm_file_to_image(var->mlx_ptr, str, &w, &h);
	mlx_put_image_to_window(var->mlx_ptr, var->mlx_win, var->img_ptr, var->x * 50, var->y * 50);
}
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
		//put image of player in x+1 * 50
		event_render(var, "img/grass.xpm");
		var->x++;
		event_render(var, "img/player.xpm");
		//put image of grass in x+1 * 50
		//remove the collectable img
	}
	else if (var->matrix[var->y][var->x + 1] == '0')
	{
		printf("value of x + 1 %d\n",var->x);
		//put image of player in x-1 * 50
		event_render(var, "img/grass.xpm");
		var->x++;
		event_render(var, "img/player.xpm");
		//put image of GRass in x-1 * 50
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
		//put image of player in x-1 * 50
		event_render(var, "img/grass.xpm");
		var->x--;
		event_render(var, "img/player.xpm");
		//put image of Grass in x-1 * 50
	}
	else if (var->matrix[var->y][var->x - 1] == '0')
	{
		//put image of player in x-1 * 50
		event_render(var, "img/grass.xpm");
		var->x--;
		event_render(var, "img/player.xpm");
		//put image of GRass in x-1 * 50
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
		//put image of player in y-1 * 50
		event_render(var, "img/grass.xpm");
		var->y--;
		event_render(var, "img/player.xpm");
		//put image of Grass in y-1 * 50
	}
	else if (var->matrix[var->y - 1][var->x] == '0')
	{
		//put image of player in y-1 * 50
		event_render(var, "img/grass.xpm");
		var->y--;
		event_render(var, "img/player.xpm");
		//put image of GRass in y-1 * 50
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
		//put image of player in y+1 * 50
		event_render(var, "img/grass.xpm");
		var->y++;
		event_render(var, "img/player.xpm");
		//put image of Grass in y+1 * 50
	}
	else if (var->matrix[var->y + 1][var->x] == '0')
	{
		//put image of player in y+1 * 50
		event_render(var, "img/grass.xpm");
		var->y++;
		event_render(var, "img/player.xpm");
		//put image of GRass in y+1 * 50
	}
}
int	events(int key, t_var *var)
{
	printf("key %d\n",key);
	//mlx_clear_window(var->mlx_ptr, var->mlx_win);
	if (key == 100)
		right(var);
	else if (key == 97)
		left(var);
	else if (key == 115)
		down(var);
	else if (key == 119)
		up(var);
	else if (key == 65307)
	{
		mlx_destroy_window(var->mlx_ptr, var->mlx_win);
		exit(1);
	}
	return (0);
}

int	close_prog(t_var *var)
{
	mlx_destroy_window(var->mlx_ptr, var->mlx_win);
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






///scratch map
/**
 * 1- we have a file that have numbers we read each line...we read first letter
 * we paint an image depending on the number we have seen
 * 2- once we finish from a letter we move to the next letter
 * this move translates into pixels in the window 
 * */

/** pseudo code for map
 * 1 initialize window
 * 2-read from the file 
 * 3-check if the map respects the rules
 * 4-we read the returned line and for each letter we implement an img in the window */

/**  structs needed
 * 1-struct for image
 * 2-struct for program
 * 3-struct for window*/