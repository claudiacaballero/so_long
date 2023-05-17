/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:52 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/17 13:18:26 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game	*game)
{
	matrix_free(game->map);
	mlx_destroy_window(game->win->mlx_ptr, game->win->win_ptr);
	exit(0);
}

int	manage_keys(int keycode, t_game	*game)
{
	t_point	new;

	new.x = game->pos.x;
	new.y = game->pos.y;
	if (keycode == ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		new.y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new.y++;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new.x++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		new.x--;
	else
		return (1);
	move(game->win, game, new);
	if (game->check.end == 1)
		close_window(game);
	return (0);
}
