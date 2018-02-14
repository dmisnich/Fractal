/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:37:30 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/30 11:37:33 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc < 2)
		MSG("Please, add argument!");
	init_mlx(&mlx);
	init(&mlx);
	check_arg(argv[1], &mlx);
	parse_fractol(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 3, 0, key_release, &mlx);
	mlx_hook(mlx.win, 4, 0, m_zoom, &mlx);
	mlx_hook(mlx.win, 6, 0, move_mouse, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_x, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->z = (t_complex *)malloc(sizeof(t_complex));
	mlx->z->max_ret = 200;
	mlx->z->ret = 0;
	mlx->z->r = 0;
	mlx->z->i = 0;
	mlx->img.image = NULL;
	mlx->img.ptr_img = NULL;
	mlx->v.tempx = 0;
	mlx->v.tempy = 0;
	mlx->c.r = -0.947000;
	mlx->c.i = -0.260570;
	mlx->v.zoom = 0.7;
	mlx->v.moveY = 0;
	mlx->v.moveX = 0;
	mlx->img.bpp = 0;
	mlx->color.r = 0;
	mlx->color.g = 0;
	mlx->color.b = 0;
	mlx->mouse.plus = 0;
	mlx->mouse.minus = 0;
	mlx->board.w = 0;
	mlx->board.s = 0;
	mlx->board.a = 0;
	mlx->board.d = 0;
	mlx->board.pl_ret = 0;
	mlx->board.min_ret = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol - dmisnich");
}

// void	part_one(t_mlx *mlx)
// {

// }

// void	part_two(t_mlx *mlx)
// {
	
// }

void	init(t_mlx *mlx)
{
	mlx->img.ptr_img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.image = mlx_get_data_addr(mlx->img.ptr_img, &mlx->img.bpp,
		&mlx->img.size_line, &mlx->img.endian);
}

void	check_arg(char *name, t_mlx *mlx)
{
	char flag;

	flag = 0;
	mlx->k = (t_v *)malloc(sizeof(t_v));
	if (!ft_strcmp(name, "julia")
	|| !ft_strcmp(name, "mandelbrot")
	|| !ft_strcmp(name, "mandelbrot_five")
	|| !ft_strcmp(name, "buffalo")
	|| !ft_strcmp(name, "burningship")
	|| !ft_strcmp(name, "mandelbar"))
	{
		flag = 1;
		mlx->k->name_n = ft_strdup(name); // зафришить!
	}
	if (flag == 1)
		free(mlx->k->name_n);
	mlx->k->name_n = ft_strdup(name);
}

void	parse_fractol(t_mlx *mlx)
{
	if (!(ft_strcmp(mlx->k->name_n, "mandelbrot")))
		draw_mandelbrot(mlx);
	else if (!(ft_strcmp(mlx->k->name_n, "julia")))
		draw_julia(mlx);
	else if (!(ft_strcmp(mlx->k->name_n, "mandelbrot_five")))
		draw_mandelbrot_5(mlx);
	else if (!(ft_strcmp(mlx->k->name_n, "buffalo")))
		draw_buffalo(mlx);
	else if (!(ft_strcmp(mlx->k->name_n, "burningship")))
		draw_burningship(mlx);
	else if (!(ft_strcmp(mlx->k->name_n, "mandelbar")))
		draw_mandelbar(mlx);
	else
		MSG("Usage: ./fractol\t[parameter] \n\nExample:\t\tmandelbrot\
			\n\t\t\tmandelbrot_five\n\t\t\tjulia\
			\n\t\t\tbuffalo\n\t\t\tburningship\
			\n\t\t\tmandelbar\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.ptr_img, 0, 0);
}

void	message(char *msg)
{
	ft_putendl(msg);
	// system("leaks -quiet fractol");
	exit_x();
}
