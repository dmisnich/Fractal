/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffalo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:04:52 by dmisnich          #+#    #+#             */
/*   Updated: 2018/02/13 14:04:54 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_buffalo(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	c;
	t_complex	temp;

	y = -1;
	while (++y != WIN_HEIGHT)
	{
		x = -1;
		while (++x != WIN_WIDTH)
		{
			ft_bzero(mlx->z, sizeof(mlx->z));
			c = range_md(x, y, mlx);
			mlx->z->ret = 0;
			help_buffalo(mlx, &c, &temp);
			mlx->color = color(mlx);
			img_set_pixel(x, y, mlx);
		}
	}
}

void			help_buffalo(t_mlx *mlx, t_complex *c, t_complex *temp)
{
	while (mlx->z->ret < mlx->z->max_ret)
	{
		temp->r = fabs(mlx->z->r * mlx->z->r - mlx->z->i * mlx->z->i) + c->r;
		mlx->z->i = 2 * fabs(mlx->z->r * mlx->z->i) + c->i;
		mlx->z->r = temp->r;
		if (mlx->z->r * mlx->z->r + mlx->z->i * mlx->z->i > 4)
			break ;
		mlx->z->ret++;
	}
}
