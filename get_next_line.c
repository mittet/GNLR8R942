/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:10:42 by luciefer          #+#    #+#             */
/*   Updated: 2022/11/23 15:59:12 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buff(int fd, char *rest)
{
	char	buff[BUFFER_SIZE + 1];
	int		n;

	n = 1;
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
			return (NULL);
		buff[n] = 0;
		rest = ft_strjoin(buff, rest);
		if (check(rest))
			n = 0;
	}
	return(rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;

	str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest = get_buff(fd, rest);		//take all buffer 
	if (!rest)
		return (NULL);
	str = get_line(rest);		//recupere la premiere ligne du buff
	rest = get_rest(rest);		//delete la phrase qu'on vient juste de copie
	if (!str)
		free(rest);
	return (str);
}

/*int main()
{
	int	a;
	char	*str;
	int	i;

	a = open("test", O_RDONLY);
	i = 0;
	str = get_next_line(1000);
	while (str)
	{
		i++;
		printf("%6i\t%s", i, str);
		free(str);
		str = get_next_line(a);
	}
	close(a);
}*/
