/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:18:33 by dmisnich          #+#    #+#             */
/*   Updated: 2018/02/08 15:18:34 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 24)
		mlx->mouse.plus = 1;
	if (keycode == 27)
		mlx->mouse.minus = 1;
	if (keycode == 13)
		mlx->board.w = 1;
	if (keycode == 1)
		mlx->board.s = 1;
	if (keycode == 0)
		mlx->board.a = 1;
	if (keycode == 2)
		mlx->board.d = 1;
	if (keycode == 69)
		mlx->board.pl_ret = 1;
	if (keycode == 78)
		mlx->board.min_ret = 1;
	if (keycode == 53)
		MSG("Program closed!");
	kb1(mlx);
	parse_fractol(mlx);
	return (0);
}

int		key_release(int keycode, t_mlx *mlx)
{
	if (keycode == 24)
		mlx->mouse.plus = 0;
	if (keycode == 27)
		mlx->mouse.minus = 0;
	if (keycode == 13)
		mlx->board.w = 0;
	if (keycode == 1)
		mlx->board.s = 0;
	if (keycode == 0)
		mlx->board.a = 0;
	if (keycode == 2)
		mlx->board.d = 0;
	if (keycode == 69)
		mlx->board.pl_ret = 0;
	if (keycode == 78)
		mlx->board.min_ret = 0;
	return (0);
}

int 	kb1(t_mlx *mlx)
{
	if (mlx->mouse.plus == 1)
		mlx->v.zoom *= 1.1;
	if (mlx->mouse.minus == 1)
	{
		if (mlx->v.zoom < 0.25000)
			return (0);
		mlx->v.zoom *= 0.9;
	}
	if (mlx->board.w == 1)
		mlx->v.moveY += 0.03;
	if (mlx->board.s == 1)
		mlx->v.moveY -= 0.03;
	if (mlx->board.a == 1)
		mlx->v.moveX += 0.03;
	if (mlx->board.d == 1)
		mlx->v.moveX -= 0.03;
	if (mlx->board.pl_ret == 1)
		mlx->z->max_ret += 10;
	if (mlx->board.min_ret == 1)
		mlx->z->max_ret -= 10;
	return (0);
}

int		move_mouse(int x, int y, t_mlx *mlx)
{
	float Tx;
	float Ty;

	Tx = (float)x / 100000;
	Ty = (float)y / 100000;
	if (mlx->v.tempx < x)
		mlx->c.r = mlx->c.r + Tx;
	else if (mlx->v.tempx > x)
		mlx->c.r = mlx->c.r - Tx;
	mlx->v.tempx = x;
	if (mlx->v.tempy < y)
		mlx->c.i = mlx->c.i + Ty;
	else if (mlx->v.tempy > y)
		mlx->c.i = mlx->c.i - Ty;
	mlx->v.tempy = y;
	parse_fractol(mlx);
	return (0);
}
