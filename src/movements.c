/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:45 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/10 20:04:40 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_win *win, t_game *game)
{
	t_img	tile;
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	tile.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/tile081.xpm", &tile.w, &tile.h);
	if (!tile.img_ptr)
		ft_error(2, "ERROR\nCould not open image");
	tile.addr = mlx_get_data_addr(tile.img_ptr, &tile.bpp, \
		&tile.line_len, &tile.endian);
	if (valid_cell(game, game->map, y - 1, x))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					tile.img_ptr, x * 32, y * 32);
		game->player.y--;
	}
	put_hero(win, game->player.x * 32, game->player.y * 32);
}

void	move_down(t_win *win, t_game *game)
{
	t_img	tile;
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	tile.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/tile081.xpm", &tile.w, &tile.h);
	if (!tile.img_ptr)
		ft_error(2, "ERROR\nCould not open image");
	tile.addr = mlx_get_data_addr(tile.img_ptr, &tile.bpp, \
		&tile.line_len, &tile.endian);
	if (valid_cell(game, game->map, y + 1, x))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					tile.img_ptr, x * 32, y * 32);
		game->player.y++;
	}
	put_hero(win, game->player.x * 32, game->player.y * 32);
}

void	move_right(t_win *win, t_game *game)
{
	t_img	tile;
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	tile.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/tile081.xpm", &tile.w, &tile.h);
	if (!tile.img_ptr)
		ft_error(2, "ERROR\nCould not open image");
	tile.addr = mlx_get_data_addr(tile.img_ptr, &tile.bpp, \
		&tile.line_len, &tile.endian);
	if (valid_cell(game, game->map, y, x + 1))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					tile.img_ptr, x * 32, y * 32);
		game->player.x++;
	}
	put_hero(win, game->player.x * 32, game->player.y * 32);
}

void	move_left(t_win *win, t_game *game)
{
	t_img	tile;
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	tile.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/tile081.xpm", &tile.w, &tile.h);
	if (!tile.img_ptr)
		ft_error(2, "ERROR\nCould not open image");
	tile.addr = mlx_get_data_addr(tile.img_ptr, &tile.bpp, \
		&tile.line_len, &tile.endian);
	if (valid_cell(game, game->map, y, x - 1))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					tile.img_ptr, x * 32, y * 32);
		game->player.x--;
	}
	put_hero(win, game->player.x * 32, game->player.y * 32);
}
