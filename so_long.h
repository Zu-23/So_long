#   ifndef  SO_LONG_H
#   define  SO_LONG_H

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