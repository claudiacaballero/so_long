/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:52 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/03 15:16:08 by ccaballe         ###   ########.fr       */
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
	return (0);
}
