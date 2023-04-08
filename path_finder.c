/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:21:00 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/08 17:32:10 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_checker(char **map)
{
	int		i;
	int		j;
	t_point	orig;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == "C")
			{
				orig->row = i;
				orig->col = j;
				find_path(map, &orig, find_item(map, 'P'));
			}
		}
	}
	find_path(map, find_item(map, 'P'), find_item(map, 'E'));
}

void	*find_path(char **map, t_point orig, int dest[2])
{
	int	**arr;
	int	i;
	int	j;

	arr = (t_point *)malloc(sizeof(t_point) * 1);
	if (!arr)
		ft_error(1, "ERROR: Memory problems\n");
	arr[0] = orig;
	while (arr[0])
	{
		if (i > 0 && map[i - 1][j] != '1')
			arr = ft_new_arr('a', arr, map[i - 1][j]);
		if (map[i + 1] && map[i - 1][j] != '1')
			arr = ft_new_arr('a', arr, map[i - 1][j]);
		if (i > 0 && map[i - 1][j] != '1')
			arr = ft_new_arr('a', arr, map[i - 1][j]);
		if (i > 0 && map[i - 1][j] != '1')
			arr = ft_new_arr('a', arr, map[i - 1][j]);
		arr = ft_new_arr('d', arr, arr[0]);
		//find 
		find_path(map, sol[0], dest);
	}
	ft_error(1, "ERROR\nNo valid path found\n");
}

int	**ft_addpoint(char c, int **arr, int point[2])
{
	int	**new_arr;
	int	i;

	i = 0;
	while (arr[i])
		i++;
	if (c == 'a')
	{
		new_arr = (int **)malloc(sizeof(int *) * (i + 1));
		i = -1;
		while (arr[++i])
			new_arr[i] = arr[i];
		new_arr[i] = point;
	}
	else
	{
		new_arr = (int **)malloc(sizeof(int *) * (i - 1));
		i = 0;
		while (arr[++i])
			new_arr[i - 1] = arr[i];
	}
	free(arr);
	return (new_arr);
}

t_point	find_item(char **map, char item)
{
	int		i;
	int		j;
	t_point	p;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == item)
			{
				p->row = i;
				p->col = j;
				return (p);
			}
		}
	}
	return (NULL);
}
