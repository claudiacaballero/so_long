/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:28:55 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/04 18:07:32 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_images(t_win *win)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, "images/xpm/Pink_Monster.xpm", &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len, &img.endian);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img.img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, img.img_ptr);
}


/*
	t_img	img;

	img.w = 100;
	img.h = 100;
	img.win = win;
	img.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, "images/xpm/Pink_Monster.xpm", &img.w, &img.h);
	if (!img.img_ptr)
		ft_error(2, "error aquest\n");
	img.addr = mlx_get_data_addr(img.img_ptr, &(img.bpp), &(img.line_len), &(img.endian));
	mlx_put_image_to_window (win->mlx_ptr, win->win_ptr, &img, 5, 5);
*/
