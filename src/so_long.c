/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:06:41 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/03 15:16:21 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_win	win;

	if (argc != 2)
		ft_error(0, "ERROR\nPlease enter an argument\n");
	init_game(argv[1], &game);
	new_program(&win, &game);
	if (!win.mlx_ptr || !win.win_ptr)
		ft_error(1, "ERROR\nProblems with mlx");
	mlx_hook(win.win_ptr, DESTROY_WIN, 0, &close_window, &win);
	mlx_key_hook(win.win_ptr, &manage_keys, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}

void	ft_error(int err, char *msg)
{
	int	len;

	len = (int)ft_strlen(msg);
	write(2, msg, len);
	exit(err);
}

void	init_game(char *ar, t_game *game)
{
	game->movements = 0;
	game->collected = 0;
	game->exit_found = 0;
	game->c = 0;
	game->p = 0;
	game->e = 0;
	game->len = 0;
	game->heig = 0;
	game->map = NULL;
	check_map(ar, game);
	path_checker(game);
}

void	new_program(t_win *win, t_game *game)
{
	win->h = game->heig * 50;
	win->w = game->len * 25;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window (win->mlx_ptr, win->w, win->h, "clau's game");
	win->game = game;
}
