/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:52 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/10 20:25:42 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_win	*window)
{
	matrix_free(window->game->map);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(0);
}

int	manage_keys(int keycode, t_win *window)
{
	if (keycode == ESC)
		close_window(window);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_up(window, window->game);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(window, window->game);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(window, window->game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(window, window->game);
	return (0);
}
