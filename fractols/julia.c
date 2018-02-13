/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:27:55 by dmisnich          #+#    #+#             */
/*   Updated: 2018/02/08 12:27:57 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	temp;

	y = -1;
	while (++y != WIN_HEIGHT)
	{
		x = -1;
		while (++x != WIN_WIDTH)
		{
			mlx->z = range_jul(x, y, mlx);
			help_julia(mlx, &temp);
			mlx->color = color(mlx);
			img_set_pixel(x, y, mlx);
		}
	}
}

void	help_julia(t_mlx *mlx, t_complex *temp)
{
	mlx->z->max_ret = 200;
	//printf("ret: %d\n", mlx->z->max_ret);
	while (mlx->z->ret < mlx->z->max_ret)
	{
		temp->r = mlx->z->r;
		temp->i = mlx->z->i;
		mlx->z->r = temp->r * temp->r - temp->i * temp->i + mlx->c.r;
		mlx->z->i = 2 * temp->r * temp->i + mlx->c.i;
		if (mlx->z->r * mlx->z->r + mlx->z->i * mlx->z->i > 4)
			break ;
		mlx->z->ret++;
	}
}
