/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:04:51 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/06 17:55:45 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char *file)
{
	int		fd;
	char	*line;
	size_t	len_line;
	t_game	game;

	if (ft_strlen(ft_strstr(file, ".ber")) != 4)
		ft_error(1, "WARNING: File should be .ber type");
	fd = open(file, O_RDONLY);
	line = ft_strtrim_free(get_next_line(fd), "\n");
	if (!line)
		ft_error(1, "WARNING: File is empty");
	len_line = ft_strlen(line);
	//check_first_line
	while (line)
	{
		if (ft_strlen(line) != len_line)
			ft_error(1, "WARNING: The map should be rectangular");
		valid_line(line, &game);
		//potser fer una flag de veure si la ultima (?) per fer un check_last_line
		free(line);
		line = ft_strtrim_free(get_next_line(fd), "\n");
	}
	free(line);
	//check_items per checkear q hi ha "1 exit, at least 1 collectible, and 1 starting position"
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
			ft_error(1, "WARNING: Incorrect characters in map");
	}
	if (line[0] != '1' || line[i - 1] != '1')
		ft_error(1, "WARNING: Map borders should be walls");
}
