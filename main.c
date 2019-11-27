/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slupe <slupe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:11:30 by nmanzini          #+#    #+#             */
/*   Updated: 2019/11/27 11:56:10 by slupe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int				main(int argc, char **argv)
{
	int			k;
	int			i;
	int			j;
	int			fd;
	char		*line;
	int			array[8] = {0, 0, 0, 0, 0 ,0, 0, 0};
	int			x;
	int			y;
	if (argc == 2)
	{
		x = 0;
		y = 0;
		i = 0;
		int t =0;
		j = 1;
		k = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
			k = 0;
			y = 0;
			while (line[k] != '\0')
			{
				if (line[k] == '#')
				{
					array[i] = x;
					array[j] = y;
					i++;
					j++;
				}
				y++;
				k++;
			}
			x++;
		}
		t = 0;
		while (t <= 7)
		{
			printf("%d ", array[t]);
			t++;
		}
		close(fd);
	}
	return (0);
}
