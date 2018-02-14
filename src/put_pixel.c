/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:33:05 by dmisnich          #+#    #+#             */
/*   Updated: 2018/02/06 15:33:07 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			img_set_pixel(int x, int y, t_mlx *mlx)
{
	int			i;

	i = (x * 4) + (y * mlx->img.size_line);
	mlx->img.image[i++] = mlx->color.r;
	mlx->img.image[i++] = mlx->color.g;
	mlx->img.image[i] = mlx->color.b;
}

t_color			color(t_mlx *mlx)
{
	t_color color;

	color.r = (mlx->z->ret * 9) % 50;
	color.g = 0;
	color.b = (mlx->z->ret * 4) % 200;
	return (color);
}

t_complex		range_md(int x, int y, t_mlx *mlx)
{
	t_complex	p;

	if (!ft_strcmp(mlx->k->name_n, "mandelbar")
	|| !ft_strcmp(mlx->k->name_n, "mandelbrot_five"))
	{
		p.r = 1.5 * (x - WIN_WIDTH / 2) / (0.6 * mlx->v.zoom * WIN_WIDTH)
		+ mlx->v.movex;
		p.i = (y - WIN_HEIGHT / 2) / (0.5 * mlx->v.zoom * WIN_HEIGHT)
		+ mlx->v.movey;
	}
	else
	{
		p.r = 1.5 * (x - WIN_WIDTH / 2) / (0.6 * mlx->v.zoom * WIN_WIDTH)
		+ (mlx->v.movex - 0.5);
		p.i = (y - WIN_HEIGHT / 2) / (0.5 * mlx->v.zoom * WIN_HEIGHT)
		+ mlx->v.movey;
	}
	return (p);
}

t_complex		*range_jul(int x, int y, t_mlx *mlx)
{
	t_complex	*p;

	p = (t_complex *)malloc(sizeof(t_complex));
	p->r = 1.5 * (x - WIN_WIDTH / 2) / (0.6 * mlx->v.zoom * WIN_WIDTH)
	+ mlx->v.movex;
	p->i = (y - WIN_HEIGHT / 2) / (0.5 * mlx->v.zoom * WIN_HEIGHT)
	+ mlx->v.movey;
	return (p);
}
