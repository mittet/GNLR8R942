/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:44:39 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/20 18:52:05 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_next_line(char *rest, int fd, char *buff)
{
	char	*tmp;
	int		n;

	n = 1;
	tmp = NULL;
	while (n != -1)
	{
		n = read(fd, buff, BUFFER_SIZE);
		buff[n] = 0;
		if(tmp)
		{
			rest = ft_get_line (buff, tmp);
			free (tmp);
			tmp = NULL;
			if (ft_strchr(rest))
				n = -1;
		}
		else
		{
			tmp = ft_get_line(buff, rest);
			free(rest);
			rest = NULL;
			if (ft_strchr(tmp))
				n = -1;
		}
	}
	if (tmp)
		return (tmp);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char	*str;
	char	buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	str = ft_read_next_line (rest, fd, buff);
	free(rest);
	rest = recuprest(buff);
	return (str);
}

int main()
{
	int	a;
	char	*str;

	a = open("hello", O_RDONLY);
	str = get_next_line(a);
	write(1, str, ft_strlen(str));
	str = get_next_line(a);
	write(1, "\n", 1);
	write(1, str, ft_strlen(str));
	close(a);
}
