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
	part_one(mlx);
	part_two(mlx);
}

void	init(t_mlx *mlx)
{
	mlx->img.ptr_img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.image = mlx_get_data_addr(mlx->img.ptr_img, &mlx->img.bpp,
		&mlx->img.size_line, &mlx->img.endian);
}

void	part_one(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx,
		WIN_WIDTH, WIN_HEIGHT, "Fractol - dmisnich");
	mlx->z = (t_complex *)malloc(sizeof(t_complex));
	mlx->z->max_ret = 200;
	mlx->z->ret = 0;
	mlx->z->r = 0;
	mlx->z->i = 0;
	mlx->img.image = NULL;
	mlx->img.ptr_img = NULL;
	mlx->v.tempx = 0;
	mlx->v.tempy = 0;
	mlx->v.zoom = 0.7;
	mlx->v.movey = 0;
	mlx->v.movex = 0;
}

void	part_two(t_mlx *mlx)
{
	mlx->c.r = -0.947000;
	mlx->c.i = -0.260570;
	mlx->v.movex = 0;
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
}
