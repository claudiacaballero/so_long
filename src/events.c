/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:38:52 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/22 13:24:51 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game	*game)
{
	matrix_free(game->map);
	mlx_destroy_window(game->win->mlx_ptr, game->win->win_ptr);
	exit(0);
}

void	outro(t_win *win, t_game *game)
{
	char	*str;
	int		x;
	int		y;

	ft_printf("Congratulations you won !!!\n");
	y = -1;
	while (++y < win->h)
	{
		x = -1;
		while (++x < win->w)
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x0000000);
	}
	x = game->len * 32 / 3;
	y = game->heig * 32 / 3;
	str = "Congratulations you won!";
	mlx_string_put(win->mlx_ptr, win->win_ptr, x, y, 0x00FFFFFF, str);
	str = "Press ESC to exit";
	mlx_string_put(win->mlx_ptr, win->win_ptr, x, y + 32, 0x00FFFFFF, str);
}

int	manage_keys(int keycode, t_game	*game)
{
	t_point	new;

	new.x = game->pos.x;
	new.y = game->pos.y;
	if (keycode == ESC)
		close_window(game);
	else if (keycode == SPACE && game->check.start == 0)
	{
		game->check.start = 1;
		render_map(game, game->win);
	}
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
		outro(game->win, game);
	return (0);
}
