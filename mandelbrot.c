/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:45:16 by ggrybova          #+#    #+#             */
/*   Updated: 2017/06/17 15:13:27 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_mlx *m)
{
	double	x;
	double	y;
	int		n;

	x = -1;
	while (++x < WIDTH && (y = -1) >= -1)
	{
		while (++y < HEIGHT && (n = -1) >= -1)
		{
			m->a = x * (m->re_x - (-m->re_x)) / WIDTH + (-m->re_x) + m->m_h;
			m->b = y * (m->im_y - (-m->im_y)) / HEIGHT + (-m->im_y) + m->m_v;
			m->ca = m->a;
			m->cb = m->b;
			while (++n < 100 && fabs(m->a + m->b) <= 16)
			{
				m->tmp = m->a;
				m->a = m->a * m->a - m->b * m->b + m->ca;
				m->b = 2 * m->tmp * m->b + m->cb;
			}
			m->col = (sqrt((double)(n)) * n - 0) * (255 - 0) / (100 - 0) + 0;
			m->col = (n == 100) ? 0 : m->col;
			draw_pixel(m, x, y);
		}
	}
}
