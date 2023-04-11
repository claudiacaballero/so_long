/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:07:06 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/11 13:13:33 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_checker(t_game game)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	while (game.map.map[++i])
	{
		j = -1;
		while (game.map.map[i][++j])
		{
			if (game.map.map[i][j] == 'C')
			{
				map = temp_map(game, i, j);
				find_path(map, game);
				matrix_free(map);
			}
		}
	}
}

char	**temp_map(t_game game, int row, int col)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * (game.map.heig + 1));
	if (!map)
		ft_error(1, "ERROR: Could not allocate memory");
	i = -1;
	while (game.map.map[++i])
	{
		map[i] = (char *)malloc(sizeof(char) * (game.map.len + 1));
		if (!map[i])
			ft_error(1, "ERROR: Could not allocate memory");
		j = -1;
		while (game.map.map[i][++j])
		{
			if (game.map.map[i][j] == 'C' && (i != row || j != col))
				map[i][j] = '0';
			else
				map[i][j] = game.map.map[i][j];
		}
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

void	find_path(char **map, t_game game)
{
	int	i;
	int	j;
	int	e;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
			{
				// printf("test\n");
				e = expand_c(map, i, j, game);
				if (e == -1)
					return ;
				if (e == 0)
					ft_error(1, "ERROR\nNo valid path found");
			}
		}
	}
	find_path(map, game);
}

int	expand_c(char **map, int row, int col, t_game game)
{
	int	i;

	i = 0;
	if (row > 0 && map[row - 1][col] != '1')
	{
		if (map[row - 1][col] == 'P')
			return (-1);
		map[row - 1][col] = 'C';
		i++;
	}
	if (row < game.map.heig && map[row + 1][col] != '1')
	{
		if (map[row + 1][col] == 'P')
			return (-1);
		map[row + 1][col] = 'C';
		i++;
	}
	if (col > 0 && map[row][col - 1] != '1')
	{
		if (map[row][col - 1] == 'P')
			return (-1);
		map[row][col - 1] = 'C';
		i++;
	}
	if (col < game.map.len && map[row][col + 1] != '1')
	{
		if (map[row][col + 1] == 'P')
			return (-1);
		map[row][col + 1] = 'C';
		i++;
	}
	return (i);
}