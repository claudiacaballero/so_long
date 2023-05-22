/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:06:41 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/22 12:52:25 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_win		win;
	t_sprites	s;

	if (argc != 2)
		ft_error(0, "ERROR\nPlease enter an argument\n");
	init_game(argv[1], &game, &s);
	new_program(&win, &game);
	intro(&win, &game);
	if (!win.mlx_ptr || !win.win_ptr)
		ft_error(1, "ERROR\nProblems with mlx");
	init_sprites(&win, &game);
	mlx_hook(game.win->win_ptr, DESTROY_WIN, 0, &close_window, &game);
	mlx_key_hook(game.win->win_ptr, &manage_keys, &game);
	mlx_loop(game.win->mlx_ptr);
	return (0);
}

void	ft_error(int err, char *msg)
{
	int	len;

	len = (int)ft_strlen(msg);
	write(2, msg, len);
	exit(err);
}

void	init_game(char *ar, t_game *game, t_sprites *s)
{
	game->movements = -1;
	game->len = 0;
	game->heig = 0;
	game->map = NULL;
	game->check.collected = 0;
	game->check.exit = 0;
	game->check.start = 0;
	game->check.c = 0;
	game->check.p = 0;
	game->check.e = 0;
	game->check.end = 0;
	s->hero = NULL;
	s->tile = NULL;
	s->wall = NULL;
	s->coll = NULL;
	s->exit = NULL;
	game->sprts = s;
	check_map(ar, game);
	path_checker(game);
}

void	new_program(t_win *win, t_game *game)
{
	win->h = game->heig * 32;
	win->w = game->len * 32;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window (win->mlx_ptr, win->w, win->h, "clau's game");
	game->win = win;
}

void	intro(t_win *win, t_game *game)
{
	char	*str;
	int		x;
	int		y;

	x = game->len * 32 / 3;
	y = game->heig * 32 / 3;
	str = "Welcome to my game!";
	mlx_string_put(win->mlx_ptr, win->win_ptr, x, y, 0x00FFFFFF, str);
	str = "Collect all the treasures";
	mlx_string_put(win->mlx_ptr, win->win_ptr, x, y + 32, 0x00FFFFFF, str);
	str = "and escape with the rocket";
	mlx_string_put(win->mlx_ptr, win->win_ptr, x, y + 42, 0x00FFFFFF, str);
	str = "Press space to start";
	mlx_string_put(win->mlx_ptr, win->win_ptr, x, y + 74, 0x00FFFFFF, str);
}
