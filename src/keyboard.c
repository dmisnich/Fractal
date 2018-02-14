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

int		kb1(t_mlx *mlx)
{
	int zoom;

	zoom = (int)mlx->v.zoom ? (int)mlx->v.zoom : 1;
	if (mlx->mouse.plus == 1)
		mlx->v.zoom *= 1.1;
	if (mlx->mouse.minus == 1)
	{
		if (mlx->v.zoom < 0.100)
			return (0);
		mlx->v.zoom *= 0.9;
	}
	if (mlx->board.w == 1)
		mlx->v.movey += 0.03 / zoom;
	if (mlx->board.s == 1)
		mlx->v.movey -= 0.03 / zoom;
	if (mlx->board.a == 1)
		mlx->v.movex += 0.03 / zoom;
	if (mlx->board.d == 1)
		mlx->v.movex -= 0.03 / zoom;
	if (mlx->board.pl_ret == 1)
		mlx->z->max_ret += 10;
	if (mlx->board.min_ret == 1)
		mlx->z->max_ret -= 10;
	return (0);
}

int		move_mouse(int x, int y, t_mlx *mlx)
{
	float tx;
	float ty;

	tx = (float)x / 100000;
	ty = (float)y / 100000;
	if (mlx->v.tempx < x)
		mlx->c.r = mlx->c.r + tx;
	else if (mlx->v.tempx > x)
		mlx->c.r = mlx->c.r - tx;
	mlx->v.tempx = x;
	if (mlx->v.tempy < y)
		mlx->c.i = mlx->c.i + ty;
	else if (mlx->v.tempy > y)
		mlx->c.i = mlx->c.i - ty;
	mlx->v.tempy = y;
	parse_fractol(mlx);
	return (0);
}

int		m_zoom(int keycode, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		mlx->v.zoom *= 1.1;
	if (keycode == 5)
	{
		if (mlx->v.zoom < 0.100)
			return (0);
		mlx->v.zoom *= 0.9;
	}
	parse_fractol(mlx);
	return (0);
}
