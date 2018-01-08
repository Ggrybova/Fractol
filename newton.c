/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 13:22:05 by ggrybova          #+#    #+#             */
/*   Updated: 2017/06/17 15:41:04 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		newton(t_mlx *m)
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
			tmp = 1;
			while (++n < 100 && tmp > 0.00001)
			{
				m->ca = m->a;
				m->cb = m->b;
				tmp = pow(m->a * m->a + m->b * m->b, 2);
				m->a = (2 * m->a * tmp + m->a * m->a - m->b * m->b) / (3 * tmp);
				m->b = (2 * m->b * (tmp - m->ca)) / (3 * tmp);
				tmp = pow(m->a - m->ca, 2) + pow(m->b - m->cb, 2);
			}
			m->col = (n == 100) ? 0 : (n - 0) * (255 - 0) / (100 - 0) + 0;
			draw_pixel(m, m->x, m->y);
		}
	}
}
