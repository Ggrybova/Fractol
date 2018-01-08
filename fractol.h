/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:55:13 by ggrybova          #+#    #+#             */
/*   Updated: 2017/06/17 15:48:29 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*im;
	char			*addr;
	int				b_p_p;
	int				size_l;
	int				end;
	int				set;
	double			col;
	int				rgb;
	double			re_x;
	double			im_y;
	double			a;
	double			b;
	double			ca;
	double			cb;
	double			tmp;
	double			r;
	double			s;
	double			m_h;
	double			m_v;
	int				pix;
	double			x;
	double			y;
}					t_mlx;

void				draw_pixel(t_mlx *m, double x, double y);
void				print_set(t_mlx *m);
int					hook_func(int key, t_mlx *m);
int					move(int key, t_mlx *m);
int					hook_mouse(int button, int x, int y, t_mlx *m);
void				fill_data(t_mlx *m);
int					zoom(int key, t_mlx *m);
void				julia_case(int key, t_mlx *m);
int					move_mouse(int x, int y, t_mlx *m);
void				mandelbrot(t_mlx *m);
void				julia(t_mlx *m);
void				newton(t_mlx *m);
void				fractal1(t_mlx *m);
void				fractal2(t_mlx *m);
void				fractal3(t_mlx *m);
void				fractal4(t_mlx *m);
void				ship(t_mlx *m);
void				*mlx_init();

#endif
