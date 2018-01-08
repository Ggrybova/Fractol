/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 13:00:42 by ggrybova          #+#    #+#             */
/*   Updated: 2017/06/17 15:11:53 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fractal1(t_mlx *m)
{
	int		n;
	double	tmp;

	m->x = -1;
	while (++m->x < WIDTH && (m->y = -1) >= -1)
	{
		while (++m->y < HEIGHT && (n = -1) >= -1)
		{
			m->a = m->x * (m->re_x - (-m->re_x)) / WIDTH + (-m->re_x) + m->m_h;
			m->b = m->y * (m->im_y - (-m->im_y)) / HEIGHT + (-m->im_y) + m->m_v;
			while (++n < 100 && (m->a * m->a + m->b * m->b) <= 4)
			{
				tmp = m->a;
				m->a = m->a * m->a * m->a - 3 * m->b * m->b * m->a + m->ca;
				m->b = 3 * tmp * tmp * m->b - m->b * m->b * m->b + m->cb;
			}
			m->col = (n == 100) ? 0 : (n - 0) * (255 - 0) / (100 - 0) + 0;
			draw_pixel(m, m->x, m->y);
		}
	}
}

void		fractal2(t_mlx *m)
{
	int		n;
	double	tmp;

	m->x = -1;
	while (++m->x < WIDTH && (m->y = -1) >= -1)
	{
		while (++m->y < HEIGHT && (n = -1) >= -1)
		{
			m->a = m->x * (m->re_x - (-m->re_x)) / WIDTH + (-m->re_x) + m->m_h;
			m->b = m->y * (m->im_y - (-m->im_y)) / HEIGHT + (-m->im_y) + m->m_v;
			while (++n < 100 && (m->a * m->a + m->b * m->b) <= 4)
			{
				tmp = m->a;
				m->a = pow(pow(m->a, 2) - pow(m->b, 2), 2) - 4 * pow(m->a, 2)
					* pow(m->b, 2) + m->ca;
				m->b = 4 * tmp * m->b * (pow(tmp, 2) - pow(m->b, 2)) + m->cb;
			}
			m->col = (n == 100) ? 0 : (n - 0) * (255 - 0) / (100 - 0) + 0;
			draw_pixel(m, m->x, m->y);
		}
	}
}

void		fractal3(t_mlx *m)
{
	int		n;
	double	tmp;

	m->x = -1;
	while (++m->x < WIDTH && (m->y = -1) >= -1)
	{
		while (++m->y < HEIGHT && (n = -1) >= -1)
		{
			m->a = m->x * (m->re_x - (-m->re_x)) / WIDTH + (-m->re_x) + m->m_h;
			m->b = m->y * (m->im_y - (-m->im_y)) / HEIGHT + (-m->im_y) + m->m_v;
			while (++n < 100 && (m->a * m->a + m->b * m->b) <= 4)
			{
				tmp = m->a;
				m->a = pow(m->a, 5) - 10 * pow(m->a, 3) * pow(m->b, 2) + 5 *
					m->a * pow(m->b, 4) + m->ca;
				m->b = pow(m->b, 5) - 10 * pow(m->b, 3) * pow(tmp, 2) + 5 *
					m->b * pow(tmp, 4) + m->cb;
			}
			m->col = (n == 100) ? 0 : (n - 0) * (255 - 0) / (100 - 0) + 0;
			draw_pixel(m, m->x, m->y);
		}
	}
}

void		fractal4(t_mlx *m)
{
	int		n;

	while (++m->x < WIDTH && (m->y = -1) >= -1)
	{
		while (++m->y < HEIGHT && (n = -1) >= -1)
		{
			m->a = m->x * (m->re_x - (-m->re_x)) / WIDTH + (-m->re_x) + m->m_h;
			m->b = m->y * (m->im_y - (-m->im_y)) / HEIGHT + (-m->im_y) + m->m_v;
			while (++n < 100 && (m->tmp = pow(m->a - m->ca, 4) + pow(m->b -
							m->cb, 4)) > 0.00001)
			{
				m->ca = m->a;
				m->cb = m->b;
				m->s = m->ca * m->ca + m->cb * m->cb;
				m->r = m->ca * m->ca - m->cb * m->cb;
				m->a = (4 * m->a * m->a * pow(m->s, 4) + 4 * m->a * m->s * m->s
	* m->r + m->r * m->r - 4 * m->b * m->b * (m->s * m->s - m->a) * (m->s * m->s
	- m->a)) / 9 / pow(m->s, 4);
				m->b = (4 * m->b * (2 * m->ca * m->s * m->s + m->r) * (m->s *
	m->s - m->ca)) / 9 / pow(m->s, 4);
			}
			m->col = (n == 100) ? 0 : (n - 0) * (255 - 0) / (100 - 0) + 0;
			draw_pixel(m, m->x, m->y);
		}
	}
}

void		ship(t_mlx *m)
{
	int		n;
	double	tmp;

	m->x = -1;
	while (++m->x < WIDTH && (m->y = -1) >= -1)
	{
		while (++m->y < HEIGHT && (n = -1) >= -1)
		{
			m->a = m->x * (m->re_x - (-m->re_x)) / WIDTH + (-m->re_x) + m->m_h;
			m->b = m->y * (m->im_y - (-m->im_y)) / HEIGHT + (-m->im_y) + m->m_v;
			m->ca = m->a;
			m->cb = m->b;
			while (++n < 100 && (m->a * m->a + m->b * m->b) <= 4)
			{
				tmp = m->b;
				m->b = fabs(2 * m->a * m->b) + m->cb;
				m->a = fabs(pow(m->a, 2) - pow(tmp, 2) + m->ca);
			}
			m->col = (n == 100) ? 0 : (n * n - 0) * (255 - 0) / (100 - 0) + 0;
			draw_pixel(m, m->x, m->y);
		}
	}
}
