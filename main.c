/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:47:22 by ggrybova          #+#    #+#             */
/*   Updated: 2017/06/17 15:38:08 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(t_mlx *m, double x, double y)
{
	m->pix = (x + y * WIDTH) * 4;
	m->addr[m->pix] = m->col;
	m->addr[m->pix + 1] = m->col;
	m->addr[m->pix + 2] = m->col;
	if (m->rgb == 18 || m->rgb == 19)
	{
		m->addr[m->pix] = 0;
		if (m->rgb == 19)
			m->addr[m->pix + 1] = 0;
	}
	if (m->rgb == 20 || m->rgb == 21)
	{
		m->addr[m->pix + 1] = 0;
		if (m->rgb == 21)
			m->addr[m->pix + 2] = 0;
	}
	if (m->rgb == 22 || m->rgb == 23)
	{
		m->addr[m->pix + 2] = 0;
		if (m->rgb == 23)
			m->addr[m->pix] = 0;
	}
	if (m->rgb == 24)
		m->addr[m->pix] = m->col;
	m->addr[m->pix + 3] = 0;
}

void		print_set(t_mlx *m)
{
	m->im = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = mlx_get_data_addr(m->im, &(m->b_p_p), &(m->size_l), &(m->end));
	if (m->set == 1)
		mandelbrot(m);
	else if (m->set == 2)
		julia(m);
	else if (m->set == 3)
		newton(m);
	else if (m->set == 4)
		fractal1(m);
	else if (m->set == 5)
		fractal2(m);
	else if (m->set == 6)
		fractal3(m);
	else if (m->set == 7)
		fractal4(m);
	else if (m->set == 8)
		ship(m);
	mlx_put_image_to_window(m->mlx, m->win, m->im, 10, 10);
	mlx_destroy_image(m->mlx, m->im);
}

void		choose_set(t_mlx *map, char *s)
{
	if (ft_strncmp(s, "1", ft_strlen(s)) == 0)
		map->set = 1;
	else if (ft_strncmp(s, "2", ft_strlen(s)) == 0)
	{
		map->ca = -0.70176;
		map->cb = -0.3842;
		map->set = 2;
	}
	else if (ft_strncmp(s, "3", ft_strlen(s)) == 0)
		map->set = 3;
	else if (ft_strncmp(s, "4", ft_strlen(s)) == 0)
		map->set = 4;
	else if (ft_strncmp(s, "5", ft_strlen(s)) == 0)
	{
		map->ca = 0.484;
		map->set = 5;
	}
	else if (ft_strncmp(s, "6", ft_strlen(s)) == 0)
	{
		map->ca = 0.544;
		map->set = 6;
	}
	else if (ft_strncmp(s, "7", ft_strlen(s)) == 0)
		map->set = 7;
	map->set = (ft_strncmp(s, "8", ft_strlen(s)) == 0) ? 8 : map->set;
}

void		fill_data(t_mlx *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, (WIDTH), (HEIGHT), "FRACTOL");
	map->re_x = 2;
	map->im_y = 2;
	map->m_h = 0.1;
	map->m_v = 0.1;
	map->rgb = 24;
	map->ca = 0.4;
	map->cb = 0;
	map->tmp = 1;
}

int			main(int argc, char **argv)
{
	t_mlx	*map;

	if (argc != 2 || !(ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 8))
	{
		ft_putstr("Available parameters:\n\t1 - Mandelbrot;\n\t2 - Julia;\n\t3 "
				"- Newton;\n\t4 - Julia(z^2);\n\t5 - Julia(z^3);\n\t6 - "
				"Julia(z^4);\n\t7 - Newton(z^6);\n\t8 - Ship.\n");
		exit(0);
	}
	map = (t_mlx *)malloc(sizeof(t_mlx));
	fill_data(map);
	choose_set(map, argv[1]);
	print_set(map);
	mlx_hook(map->win, 2, 5, hook_func, map);
	mlx_mouse_hook(map->win, hook_mouse, map);
	mlx_hook(map->win, 6, 64, move_mouse, map);
	mlx_expose_hook(map->win, move, map);
	mlx_loop(map->mlx);
	return (1);
}
