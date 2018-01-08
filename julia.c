/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 13:11:18 by ggrybova          #+#    #+#             */
/*   Updated: 2017/06/17 15:12:35 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_case(int key, t_mlx *m)
{
	if (key == 83)
	{
		m->ca = -0.835;
		m->cb = -0.2321;
	}
	else if (key == 84)
	{
		m->ca = -0.7269;
		m->cb = 0.1889;
	}
	if (key == 85)
	{
		m->ca = -0.8;
		m->cb = 0.156;
	}
	else if (key == 86)
	{
		m->ca = 0;
		m->cb = -0.8;
	}
	else if (key == 87)
	{
		m->ca = -0.70176;
		m->cb = -0.3842;
	}
}

int			move_mouse(int x, int y, t_mlx *m)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		m->ca = (x - 0) * (m->re_x - (-m->re_x)) / (WIDTH - 0) + (-m->re_x)
			+ m->m_h;
		m->cb = (x - 0) * (m->im_y - (-m->im_y)) / (HEIGHT - 0) + (-m->im_y)
			+ m->m_v;
		print_set(m);
	}
	return (1);
}

void		julia(t_mlx *m)
{
	double	x;
	double	y;
	int		n;
	double	tmp;

	x = -1;
	while (++x < WIDTH && (y = -1) >= -1)
	{
		while (++y < HEIGHT && (n = -1) >= -1)
		{
			m->a = x * (m->re_x - (-m->re_x)) / WIDTH + (-m->re_x) + m->m_h;
			m->b = y * (m->im_y - (-m->im_y)) / HEIGHT + (-m->im_y) + m->m_v;
			while (++n < 100 && (m->a * m->a + m->b * m->b) <= 4)
			{
				tmp = m->a;
				m->a = m->a * m->a - m->b * m->b + m->ca;
				m->b = 2 * tmp * m->b + m->cb;
			}
			m->col = (n - 0) * (255 - 0) / (100 - 0) + 0;
			if (n == 100)
				m->col = 0;
			draw_pixel(m, x, y);
		}
	}
}
