/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:52 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/16 21:41:54 by ccaballe         ###   ########.fr       */
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
	if (keycode == ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game->win, game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(game->win, game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(game->win, game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(game->win, game);
	if (game->check.end == 1)
		close_window(game);
	return (0);
}
