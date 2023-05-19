/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:18:56 by ccaballe          #+#    #+#             */
/*   Updated: 2023/05/19 13:08:21 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	l;

	l = ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) * (l + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	if (l != 0)
		ft_memcpy(s3, s1, l);
	i = 0;
	while (s2[i] != '\0')
	{
		s3[l + i] = s2[i];
		i++;
	}
	s3[l + i] = '\0';
	return (s3);
}

static void	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strjoin_free(char *storage, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!storage)
		return (ft_strdup(buffer));
	str = malloc(sizeof(char) * ((ft_strlen(storage) + ft_strlen(buffer)) + 1));
	if (!str)
		return (ft_free(&storage));
	i = -1;
	j = 0;
	while (storage[++i] != '\0')
		str[i] = storage[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(storage);
	return (str);
}

char	*ft_strjoin_doublefree(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str1)
		return (ft_strdup(str2));
	str = malloc(sizeof(char) * ((ft_strlen(str1) + ft_strlen(str2)) + 1));
	if (!str)
		return (ft_free(&str1));
	i = -1;
	j = 0;
	while (str1[++i] != '\0')
		str[i] = str1[i];
	while (str2[j] != '\0')
		str[i++] = str2[j++];
	str[i] = '\0';
	free(str1);
	free(str2);
	return (str);
}
