/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:06:41 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/06 18:17:39 by ccaballe         ###   ########.fr       */
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
		ft_error(0, "ERROR\nPlease enter an argument");
	check_map(argv[1], &game);
	return (0);
}
