/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:09:18 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/25 16:34:58 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

//structs
typedef struct s_map
{
	char	**map;
	int		len;
	int		heig;
	int		p;
	int		e;
	int		c;
}	t_map;

typedef struct s_game
{
	int		movements;
	int		collected;
	int		exit_found;
	t_map	map;
}	t_game;

//main
void	ft_error(int err, char *msg);

//map_checker
void	check_map(char *file, t_game *game);
void	valid_line(char *line, t_game *game);
void	check_items(t_game *game);
void	map_dimentions(t_game *game);

//path finder
void	path_checker(t_game *game);
char	**temp_map(t_game *game);
int		valid_path(t_game *game, char **map, int row, int col);
int		valid_cell(t_game *game, char **map, int row, int col);

#endif