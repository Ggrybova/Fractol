/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 13:08:22 by ggrybova          #+#    #+#             */
/*   Updated: 2017/06/17 15:38:03 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom(int key, t_mlx *m)
{
	double h;

	h = (key == 69) ? -m->re_x / 10 : m->re_x / 10;
	m->re_x = m->re_x + h;
	m->im_y = m->im_y + h;
	return (1);
}

int		move(int key, t_mlx *m)
{
	double h;

	if (key == 123 || key == 124)
	{
		h = (key == 123) ? m->re_x / 10 : -m->re_x / 10;
		m->m_h = m->m_h + h;
	}
	else if (key == 125 || key == 126)
	{
		h = (key == 125) ? -m->re_x / 10 : m->re_x / 10;
		m->m_v = m->m_v + h;
	}
	return (1);
}

int		col_palette(int key, t_mlx *m)
{
	m->rgb = key;
	print_set(m);
	return (1);
}

int		hook_func(int key, t_mlx *m)
{
	if (key == 78 || key == 69)
		zoom(key, m);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, m);
	else if (key == 53)
		exit(1);
	else if (key >= 83 && key <= 87 && m->set == 2)
		julia_case(key, m);
	else if (key >= 18 || key <= 21)
		col_palette(key, m);
	print_set(m);
	return (1);
}

int		hook_mouse(int button, int x, int y, t_mlx *m)
{
	if (button == 5)
		zoom(69, m);
	else if (button == 4)
		zoom(78, m);
	print_set(m);
	x = 0;
	y = 0;
	return (1);
}
