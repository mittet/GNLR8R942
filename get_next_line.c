/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:10:42 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/28 17:01:38 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *buff, char *rest)
{
	char	*str;
	int		i;
	int		u;

	u = 0;
	i = 0;
	if (!buff && !rest)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen_classic(buff)
				+ ft_strlen_classic(rest)) + 1);
	if (!str)
		return (0);
	if (rest)
	{
		while (rest[u])
			str[i++] = rest[u++];
	}
	u = 0;
	while (buff[u])
		str[i++] = buff[u++];
	str[i] = 0;
	if (rest)
		free(rest);
	return (str);
}

char	*get_buff(int fd, char *rest)
{
	char	*buff;
	int		n;

	n = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
		{
			free (buff);
			return (NULL);
		}
		buff[n] = 0;
		rest = ft_strjoin(buff, rest);
		if (check(rest))
			n = 0;
	}
	free (buff);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;

	str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest = get_buff(fd, rest);
	if (!rest)
		return (NULL);
	str = get_line(rest);
	rest = get_rest(rest);
	if (!str)
		free(rest);
	return (str);
}

int main()
{
	int	a;
	char	*str;
	int	i;

	a = open("test", O_RDONLY);
	i = 0;
	str = get_next_line(a);
	while (str)
	{
		i++;
		printf("%6i\t%s", i, str);
		free(str);
		str = get_next_line(a);
	}
	close(a);
}
