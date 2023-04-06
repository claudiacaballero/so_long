/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:04:51 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/06 19:08:02 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*str_map;

	str_map = NULL;
	if (ft_strlen(ft_strstr(file, ".ber")) != 4)
		ft_error(1, "ERROR\nFile should be .ber type");
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error(1, "ERROR\nFile is empty");
	while (line)
	{
		str_map = ft_strjoin(str_map, line);
		valid_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	game->map.map = ft_split(str_map, '\n');
	check_items(game);
	close(fd);
}

void	valid_line(char *line, t_game *game)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'P')
			game->map.p++;
		else if (line[i] == 'E')
			game->map.e++;
		else if (line[i] == 'C')
			game->map.c++;
		else if (line[i] != '1' && line[i] != '0' && line[i] != '\n')
			ft_error(1, "ERROR\nIncorrect characters in map");
	}
	if (line[0] != '1' || (line[i - 1] == '\n' && line[i - 2] != '1'))
		ft_error(1, "ERROR\nMap borders should be walls");
	else if (line[i - 1] != '\n' && line[i - 1] != '1')
		ft_error(1, "ERROR\nMap borders should be walls");
}

void	check_items(t_game *game)
{
	int		i;
	int		j;
	size_t	len_line;

	i = 0;
	if (game->map.p != 1)
		ft_error(1, "ERROR\nMap should contain exactly 1 starting position");
	if (game->map.c < 1)
		ft_error(1, "ERROR\nMap should contain at least 1 collectible");
	if (game->map.e != 1)
		ft_error(1, "ERROR\nMap should contain exactly 1 exit");
	len_line = ft_strlen(game->map.map[i]);
	while (game->map.map[i])
	{
		if (ft_strlen(game->map.map[i]) != len_line)
			ft_error(1, "ERROR\nThe map should be rectangular");
		i++;
	}
	j = -1;
	while (game->map.map[0][++j])
		if (game->map.map[0][j] != '1')
			ft_error(1, "ERROR\nMap borders should be walls");
	while (--j >= 0)
		if (game->map.map[i - 1][j] != '1')
			ft_error(1, "ERROR\nMap borders should be walls");
}
