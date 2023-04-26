/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:04:51 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/26 17:38:36 by ccaballe         ###   ########.fr       */
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
		ft_error(1, "ERROR\nFile should be .ber type\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(1, "ERROR\nFile does not open\n");
	line = get_next_line(fd);
	if (!line)
		ft_error(1, "ERROR\nFile is empty\n");
	while (line)
	{
		str_map = ft_strjoin_free(str_map, line);
		valid_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	game->map = ft_split(str_map, '\n');
	map_dimentions(game);
	free(str_map);
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
			game->p++;
		else if (line[i] == 'E')
			game->e++;
		else if (line[i] == 'C')
			game->c++;
		else if (line[i] != '1' && line[i] != '0' && line[i] != '\n')
			ft_error(1, "ERROR\nUnrecognized characters in map\n");
	}
	if (line[0] != '1' || (line[i - 1] == '\n' && line[i - 2] != '1'))
		ft_error(1, "ERROR\nMap borders should be walls\n");
	else if (line[i - 1] != '\n' && line[i - 1] != '1')
		ft_error(1, "ERROR\nMap borders should be walls\n");
}

void	check_items(t_game *game)
{
	int		i;
	int		j;
	size_t	len_line;

	i = 0;
	if (game->p != 1)
		ft_error(1, "ERROR\nMap should contain exactly 1 starting position\n");
	if (game->c < 1)
		ft_error(1, "ERROR\nMap should contain at least 1 collectible\n");
	if (game->e != 1)
		ft_error(1, "ERROR\nMap should contain exactly 1 exit\n");
	len_line = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len_line)
			ft_error(1, "ERROR\nThe map should be rectangular\n");
		i++;
	}
	j = -1;
	while (game->map[0][++j])
		if (game->map[0][j] != '1')
			ft_error(1, "ERROR\nMap borders should be walls\n");
	while (--j >= 0)
		if (game->map[i - 1][j] != '1')
			ft_error(1, "ERROR\nMap borders should be walls\n");
}

void	map_dimentions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
		i++;
	j = 0;
	while (game->map[0][j])
		j++;
	game->len = j;
	game->heig = i;
}
