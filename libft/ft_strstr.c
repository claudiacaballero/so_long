/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:39:26 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/06 17:40:17 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *h, char *n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(n) == 0 || n == NULL)
		return (h);
	while (h[i] != '\0')
	{
		j = 0;
		while (h[i + j] == n[j] && n[j] && h[i + j])
		{
			if (n[j + 1] == '\0')
				return (&h[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
