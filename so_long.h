/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:09:18 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/02 16:08:08 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

//events
# define DESTROY_WIN 17

//keycodes
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define SPACE 49
# define ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

//structs
typedef struct s_game
{
	int		movements;
	int		collected;
	int		exit_found;
	char	**map;
	int		len;
	int		heig;
	int		p;
	int		e;
	int		c;
}	t_game;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;
	t_game	*game;
}	t_win;

//main
void	ft_error(int err, char *msg);
void	init_game(t_game *game);
void	new_program(t_win *window, t_game *game);

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

//events
int		close_window(t_win	*window);
int		manage_keys(int keycode, t_win *window);

#endif