/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:06:41 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/08 15:33:00 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int err, char *msg)
{
	int	len;

	len = (int)ft_strlen(msg);
	write(2, msg, len);
	exit(err);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error(0, "ERROR\nPlease enter an argument\n");
	check_map(argv[1], &game);
	matrix_free(game.map.map);
	return (0);
}
