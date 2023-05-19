/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:43:56 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/19 15:56:40 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_win *win, t_game *game)
{
	int	w;
	int	h;

	game->sprts->hero = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/hero.xpm", &w, &h);
	game->sprts->tile = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/grass.xpm", &w, &h);
	game->sprts->wall = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/bush.xpm", &w, &h);
	game->sprts->coll = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/chest.xpm", &w, &h);
	game->sprts->exit = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/exit.xpm", &w, &h);
	if (!game->sprts->hero || !game->sprts->tile || \
		!game->sprts->wall || !game->sprts->coll || \
		!game->sprts->exit)
		ft_error(2, "ERROR\nCould not open images");
}

void	render_map(t_game *game, t_win *win)
{
	int			x;
	int			y;

	y = -1;
	while (++y < game->heig)
	{
		x = -1;
		while (++x < game->len)
		{
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
				game->sprts->tile, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
						game->sprts->wall, x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->coll, x * 32, y * 32);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->hero, x * 32, y * 32);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->exit, x * 32, y * 32);
		}
	}
}
