/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:53:59 by event             #+#    #+#             */
/*   Updated: 2022/04/05 21:14:17 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *fp)
{
	int		i;
	char	*heap;

	i = 0;
	if (!fp[i])
		return (NULL);
	while (fp[i] && fp[i] != '\n')
		i++;
	heap = (char *)malloc(sizeof(char) * (i + 2));
	if (!heap)
		return (NULL);
	i = 0;
	while (fp[i] && fp[i] != '\n')
	{
		heap[i] = fp[i];
		i++;
	}
	if (fp[i] == '\n')
	{
		heap[i] = fp[i];
		i++;
	}
	heap[i] = '\0';
	return (heap);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}
