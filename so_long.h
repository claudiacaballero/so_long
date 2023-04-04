/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:09:18 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/04 16:59:59 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

//struct
typedef struct s_game
{
	int		p;
	int		e;
	int		c;
	char	**map;
}	t_game;

//main
void	ft_error(int err, char *msg);

//map_checker
void	check_map(char *file);
void	valid_line(char *line, t_game *game);

#endif