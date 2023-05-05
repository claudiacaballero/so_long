/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:28:55 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/05 17:07:40 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_images(t_win *win)
{
	put_background(win);
	put_collects(win);
}

void	put_hero(t_win *win, int x, int y)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"images/xpm/Pink.xpm", &img.w, &img.h);
	if (!img.img_ptr)
		ft_error(2, "ERROR\nCould not open image");
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, \
		&img.line_len, &img.endian);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img.img_ptr, x, y);
	mlx_destroy_image(win->mlx_ptr, img.img_ptr);
}

void	put_walls(t_win *win, int x, int y)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"images/xpm/tile010.xpm", &img.w, &img.h);
	if (!img.img_ptr)
		ft_error(2, "ERROR\nCould not open image");
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, \
		&img.line_len, &img.endian);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img.img_ptr, x, y);
	mlx_destroy_image(win->mlx_ptr, img.img_ptr);
}

void	put_background(t_win *win)
{
	t_img	img;
	int		x;
	int		y;

	img.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"images/xpm/tile081.xpm", &img.w, &img.h);
	if (!img.img_ptr)
		ft_error(2, "ERROR\nCould not open image");
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, \
		&img.line_len, &img.endian);
	y = 0;
	while (y < win->game->heig)
	{
		x = 0;
		while (x < win->game->len)
		{
			if (win->game->map[y][x] != '1')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					img.img_ptr, x * 32, y * 32);
			else
			{
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					img.img_ptr, x * 32, y * 32);
				put_walls(win, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
	mlx_destroy_image(win->mlx_ptr, img.img_ptr);
}

void	put_collects(t_win *win)
{
	t_img	img;
	int		x;
	int		y;

	img.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"images/xpm/Icon10.xpm", &img.w, &img.h);
	if (!img.img_ptr)
		ft_error(2, "ERROR\nCould not open image");
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, \
		&img.line_len, &img.endian);
	y = 0;
	while (y < win->game->heig)
	{
		x = 0;
		while (x < win->game->len)
		{
			if (win->game->map[y][x] == 'C')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img.img_ptr, x * 32, y * 32);
			else if (win->game->map[y][x] == 'P')
				put_hero(win, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_destroy_image(win->mlx_ptr, img.img_ptr);
}
