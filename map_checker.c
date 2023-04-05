/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:04:51 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/05 16:34:17 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char *file)
{
	int		fd;
	char	*line;
	size_t	len_line;
	t_game	game;

	//ber file
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error(1, "enter a non-empty file");
	len_line = ft_strlen(line);
	//check_first_line
	while (line)
	{
		if (ft_strlen(line) != len_line)
			ft_error(1, "enter a valid map");
		valid_line(line, &game);
		//potser fer una flag de veure si la ultima (?) per fer un check_last_line
		free(line);
		line = get_next_line(fd);
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
		else if (line[i] != '1' || line[i] != '0')
			ft_error(1, "enter a valid map");
	}
	if (line[0] != '1' || line[i - 1] != '1')
		ft_error(1, "enter a valid map");
}
