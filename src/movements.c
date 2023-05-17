/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:51:45 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/17 13:18:17 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_win *win, t_game *game, t_point new)
{
	int		x;
	int		y;

	x = game->pos.x;
	y = game->pos.y;
	if (!valid_cell(game, game->map, new.y, new.x))
		return ;
	if (game->map[y][x] != 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			game->sprts->tile->img_ptr, x * 32, y * 32);
	else
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			game->sprts->exit->img_ptr, x * 32, y * 32);
	game->pos.x = new.x;
	game->pos.y = new.y;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		game->sprts->hero->img_ptr, new.x * 32, new.y * 32);
	game->movements++;
	ft_printf("nbr movements = %i\n", game->movements);
	if (game->map[new.y][new.x] == 'C' || game->map[new.y][new.x] == 'E')
		collect_item(game, new.x, new.y, game->map[new.y][new.x]);
}

void	collect_item(t_game *game, int x, int y, char item)
{
	if (item == 'C')
		game->map[y][x] = '0';
	else
	{
		if (game->check.collected == game->check.c)
			game->check.end = 1;
	}
}
