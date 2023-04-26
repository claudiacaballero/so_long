/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:06:41 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/26 17:55:44 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	void	*mlx_ptr;
	void	*win_ptr;

	if (argc != 2)
		ft_error(0, "ERROR\nPlease enter an argument\n");
	init_game(&game);
	check_map(argv[1], &game);
	path_checker(&game);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window (mlx_ptr, game.len * 25, game.heig * 50, "clau");
	if (!win_ptr)
		return (2);
	mlx_loop(mlx_ptr);
	matrix_free(game.map);
	return (0);
}

void	init_game(t_game *game)
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
}

void	ft_error(int err, char *msg)
{
	int	len;

	len = (int)ft_strlen(msg);
	write(2, msg, len);
	exit(err);
}
