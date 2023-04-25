/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:54 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/25 18:44:01 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (map[i][j] == 'P')
				if (valid_path(game, map, i, j) == 0)
					ft_error(0, "ERROR\nNo valid path found");
	}
	matrix_free(map);
	ft_printf("path found");
}

char	**temp_map(t_game *game)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (game->map.heig + 1));
	if (!map)
		ft_error(1, "ERROR: Could not allocate memory");
	i = -1;
	while (game->map.map[++i])
		map[i] = ft_substr(game->map.map[i], 0, game->map.len);
	return (map);
}

int	valid_path(t_game *game, char **map, int row, int col)
{
	if (game->collected == game->map.c && game->exit_found == 1)
		return (1);
	map[row][col] = '1';
	if (valid_cell(game, map, row, col + 1))
	{
		if (valid_path(game, map, row, col + 1))
			return (1);
	}
	if (valid_cell(game, map, row + 1, col))
	{
		if (valid_path(game, map, row + 1, col))
			return (1);
	}
	if (valid_cell(game, map, row, col - 1))
	{
		if (valid_path(game, map, row, col - 1))
			return (1);
	}
	if (valid_cell(game, map, row - 1, col))
	{
		if (valid_path(game, map, row - 1, col))
			return (1);
	}
	return (0);
}

int	valid_cell(t_game *game, char **map, int row, int col)
{
	if (row >= 0 && row <= game->map.heig && col >= 0 && col <= game->map.len)
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
