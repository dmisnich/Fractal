/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:39:37 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/30 11:39:39 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH		1100
# define WIN_HEIGHT		900
# define MSG(x) message(x)
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct	s_kboard
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			pl_ret;
	int			min_ret;
}				t_kboard;

typedef struct	s_v
{
	char		*name_n;
}				t_v;

typedef struct	s_value
{
	float		movex;
	float		movey;
	float		zoom;
	int			tempx;
	int			tempy;
}				t_value;

typedef struct	s_mouse
{
	int			lkm;
	int			pkm;
	int			plus;
	int			minus;
}				t_mouse;

typedef struct	s_complex
{
	float		r;
	float		i;
	int			ret;
	int			max_ret;
}				t_complex;

typedef struct	s_range
{
	float		xmax;
	float		ymax;
	float		xmin;
	float		ymin;
}				t_range;

typedef	struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_img
{
	void		*ptr_img;
	char		*image;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_color		color;
	t_range		rng;
	t_mouse		mouse;
	t_value		v;
	t_complex	c;
	t_complex	*z;
	t_v			*k;
	t_kboard	board;

}				t_mlx;

/*
**	MAIN.C
*/

void			init_mlx(t_mlx *mlx);
void			part_one(t_mlx *mlx);
void			part_two(t_mlx *mlx);
void			init(t_mlx *mlx);

/*
**	PARSE.C
*/

void			check_arg(char *name, t_mlx *mlx);
void			parse_fractol(t_mlx *mlx);

/*
**	PUT_PIXEL.C
*/

void			img_set_pixel(int x, int y, t_mlx *mlx);
t_complex		*range_jul(int x, int y, t_mlx *mlx);
t_complex		range_md(int x, int y, t_mlx *mlx);
t_color			color(t_mlx *mlx);

/*
**	EXIT.C
*/

int				exit_x(void);

/*
**	OTHER.C
*/

void			message(char *msg);

/*
**	KEYBOARD.C
*/

int				m_zoom(int keycode, int x, int y, t_mlx *mlx);
int				move_mouse(int x, int y, t_mlx *mlx);
int				key_release(int keycode, t_mlx *mlx);
int				key_press(int keycode, t_mlx *mlx);
int				kb1(t_mlx *mlx);

/*
**	FRACTOLES
*/

void			draw_mandelbrot_5(t_mlx *mlx);
void			draw_burningship(t_mlx *mlx);
void			draw_mandelbrot(t_mlx *mlx);
void			draw_mandelbar(t_mlx *mlx);
void			draw_buffalo(t_mlx *mlx);
void			draw_julia(t_mlx *mlx);

void			help_mandelbrot_5(t_mlx *mlx, t_complex *c, t_complex *temp);
void			help_burningship(t_mlx *mlx, t_complex *c, t_complex *temp);
void			help_mandelbrot(t_mlx *mlx, t_complex *c, t_complex *temp);
void			help_mandelbar(t_mlx *mlx, t_complex *c, t_complex *temp);
void			help_buffalo(t_mlx *mlx, t_complex *c, t_complex *temp);
void			help_julia(t_mlx *mlx, t_complex *temp);

#endif
