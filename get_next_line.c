/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valecart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:27:12 by valecart          #+#    #+#             */
/*   Updated: 2019/04/09 15:00:41 by valecart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	static char		*tmp = NULL;
	char			buff[BUFF_SIZE + 1];
	int				rd;

	if (!(tmp = ft_strchr(str, '\n')))
	{
	if ((rd = read(fd, buff, BUFF_SIZE)) == 0)
		return (0);
	}
	str = ft_strjoin(str, buff);
	printf("str: >%s<\n\n\n", str);
	if (!ft_strchr(str, '\n'))
	{
		get_next_line(fd, line);
	}
	else
	{
		tmp = ft_strchr(str, '\n');
		*tmp = '\0';
		*line = ft_memalloc(ft_strlen(str) + 1);
		*line = ft_strcpy(*line, str);
		str = tmp + 1;
	}
	return (1);
}

int main(int ac, char **av)
{
	char *line;
	int fd;

	(void)ac;
	(void)av;
	int		call = 1;
#include <fcntl.h>
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
	//	printf("%d appel: %s\n", call, line);
		call++;
	}
	return (0);
}
