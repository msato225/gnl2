/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:53:50 by event             #+#    #+#             */
/*   Updated: 2022/04/05 21:37:42 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	tmp_line(char *tmp, char *res, char	*buff)
{		
	tmp = ft_strdup(res);
	free(res);
	res = NULL;
	res = ft_strjoin(tmp, buff);
}

char	*read_line(int fd, char *res)
{
	char	*buff;
	int		bytes;
	char	*tmp;

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
			tmp_line(tmp, res, buff);
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

int main ()
{
    char    *line;
    int     fd;

    line = NULL;
    fd = open("./test.c", O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        printf("%s", line);
        line = get_next_line(fd);
    }
    close(fd);
    return 0;
}