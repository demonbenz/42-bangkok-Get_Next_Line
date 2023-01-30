/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otangkab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:27:40 by otangkab          #+#    #+#             */
/*   Updated: 2022/11/11 15:38:36 by otangkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int	fd;
	char	*line;

	(void)argc;
	(void)argv[1];

	fd = open("test.txt", O_RDONLY);

	line = "";

	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		//getchar();
	}
	
	fd = close(fd);
	return (0);
}
