/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:54 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/05 19:12:22 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	path_checker(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	map = temp_map(game);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				if (valid_path(game, map, i, j) == 0)
					ft_error(0, "ERROR\nNo valid path found");
			}
		}
	}
	matrix_free(map);
	game->exit_found = 0;
	game->collected = 0;
}

char	**temp_map(t_game *game)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (game->heig + 1));
	if (!map)
		ft_error(1, "ERROR: Could not allocate memory");
	i = -1;
	while (game->map[++i])
	{
		map[i] = ft_substr(game->map[i], 0, game->len);
		if (!map[i])
		{
			matrix_free(map);
			ft_error(1, "ERROR: Could not allocate memory");
		}
	}
	map[i] = NULL;
	return (map);
}

int	valid_path(t_game *game, char **map, int row, int col)
{
	if (game->collected == game->c && game->exit_found == 1)
		return (1);
	map[row][col] = '1';
	if (valid_cell(game, map, row, col + 1))
		if (valid_path(game, map, row, col + 1))
			return (1);
	if (valid_cell(game, map, row + 1, col))
		if (valid_path(game, map, row + 1, col))
			return (1);
	if (valid_cell(game, map, row, col - 1))
		if (valid_path(game, map, row, col - 1))
			return (1);
	if (valid_cell(game, map, row - 1, col))
		if (valid_path(game, map, row - 1, col))
			return (1);
	return (0);
}

int	valid_cell(t_game *game, char **map, int row, int col)
{
	if (row >= 0 && row < game->heig && col >= 0 && col < game->len)
	{
		if (map[row][col] == '1')
			return (0);
		if (map[row][col] == 'C')
			game->collected++;
		if (map[row][col] == 'E')
			game->exit_found = 1;
		return (1);
	}
	return (0);
}
