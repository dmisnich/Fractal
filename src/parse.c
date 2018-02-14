/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:46:19 by dmisnich          #+#    #+#             */
/*   Updated: 2018/02/14 12:46:21 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		mlx->k->name_n = ft_strdup(name);
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
