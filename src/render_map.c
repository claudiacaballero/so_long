/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:43:56 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/17 13:24:26 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				game->sprts->tile->img_ptr, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
						game->sprts->wall->img_ptr, x * 32, y * 32);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->coll->img_ptr, x * 32, y * 32);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->hero->img_ptr, x * 32, y * 32);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
					game->sprts->exit->img_ptr, x * 32, y * 32);
		}
	}
}

void	init_sprites(t_win *win, t_game *game)
{
	int	w;
	int	h;

	ft_printf("not here\n");
	game->sprts->hero->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/hero.xpm", &w, &h);
	game->sprts->tile->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/grass.xpm", &w, &h);
	game->sprts->wall->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/rock.xpm", &w, &h);
	game->sprts->coll->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/chest.xpm", &w, &h);
	game->sprts->exit->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, \
		"sprites/exit.xpm", &w, &h);
	if (!game->sprts->hero->img_ptr || !game->sprts->tile->img_ptr || \
		!game->sprts->wall->img_ptr || !game->sprts->coll->img_ptr || \
		!game->sprts->exit->img_ptr)
		ft_error(2, "ERROR\nCould not open images");
}
