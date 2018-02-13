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
		MSG("");
	init_mlx(&mlx);

	init(&mlx);
	//draw_mandelbrot(&mlx);
	check_arg(argv[1], &mlx);
    //draw_julia(&mlx);
	parse_fractol(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 3, 0, key_release, &mlx);
	mlx_hook(mlx.win, 6, 0, move_mouse, &mlx);

	mlx_hook(mlx.win, 17, 1L << 17, exit_x, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->z = (t_complex *)malloc(sizeof(t_complex));
	mlx->z->max_ret = 200;
	printf("ret: %d\n", mlx->z->max_ret);
	mlx->z->ret = 0;
	mlx->img.image = NULL;
	mlx->img.ptr_img = NULL;
	mlx->z->r = 0;
	mlx->z->i = 0;
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
	//view(mlx);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol - dmisnich");
}

void	init(t_mlx *mlx)
{
	mlx->img.ptr_img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.image = mlx_get_data_addr(mlx->img.ptr_img, &mlx->img.bpp,
		&mlx->img.size_line, &mlx->img.endian);
}

void	check_arg(char *name, t_mlx *mlx)
{
	mlx->k = (t_v *)malloc(sizeof(t_v));
	if (!ft_strcmp(name, "julia") || !ft_strcmp(name, "mandelbrot") || !ft_strcmp(name, "mandelbrot_five"))
		mlx->k->name_n = ft_strdup(name); // зафришить!
}

void	parse_fractol(t_mlx *mlx)
{
	// if (mlx->img.image != NULL)
	// {
	// 	mlx_destroy_image(mlx->mlx, mlx->img.image);
	// 	mlx->img.image = NULL;
	// 	init(mlx);
	// }
	// ft_bzero(mlx->mlx, mlx->img.bpp);
	// mlx_clear_window(mlx->mlx, mlx->win);
    
	if (!(ft_strcmp(mlx->k->name_n, "mandelbrot")))
		draw_mandelbrot(mlx);
	else if (!(ft_strcmp(mlx->k->name_n, "julia")))
		draw_julia(mlx);
	else if (!(ft_strcmp(mlx->k->name_n, "mandelbrot_five")))
		draw_mandelbrot_5(mlx);
	else
		MSG("Usage: ./fractol\t[parameter] \n\nExample:\t\tmandelbrot\
			\n\t\t\tmandelbrot_five\n\t\t\tjulia\
			\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.ptr_img, 0, 0);
}

void	message(char *msg)
{
	ft_putendl(msg);
	//system("leaks -quiet fractol");
	exit_x();
}

// void	view(t_mlx *mlx)
// {
// 	mlx->rng.xmax = 2;
// 	mlx->rng.xmin = -2;
// 	mlx->rng.ymax = 2;
// 	mlx->rng.ymin = -1;
// }

// t_complex range(int x, int y, t_mlx *mlx)
// {
// 	t_complex p;

// 	p.r = (((float)x / WIN_WIDTH) * (mlx->rng.xmax - mlx->rng.xmin));
// 	p.i = (((float)y / WIN_HEIGHT) * (mlx->rng.ymax - mlx->rng.ymin));
// 	return (p);

// }

