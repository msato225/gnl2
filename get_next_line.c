/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:53:50 by event             #+#    #+#             */
/*   Updated: 2022/04/06 18:02:16 by event            ###   ########.fr       */
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

char	*tmp_line(char *res, char *buff)
{		
	char	*tmp;

	tmp = ft_strdup(res);
	free(res);
	res = NULL;
	res = ft_strjoin(tmp, buff);
	free(tmp);
	return (res);
}

char	*read_line(int fd, char *res)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(res, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		if (res != NULL)
			res = tmp_line(res, buff);
		else
			res = ft_strdup(buff);
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_line(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = ft_save(save);
	return (line);
}

/*
int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
		return (0);
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	system("leaks a.out");
	return 0;
}
*/