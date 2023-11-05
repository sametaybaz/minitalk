/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaybaz <aaybaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:46 by aaybaz            #+#    #+#             */
/*   Updated: 2023/02/02 16:14:55 by aaybaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h" 

void	signalcheck(int pid, char *data)
{
	int				i;
	int				j;
	unsigned char	bit;

	j = 0;
	while (data[j])
	{
		i = 7;
		bit = data[j];
		while (i >= 0)
		{
			if ((bit >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		j++;
	}	
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*data;

	data = argv[2];
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signalcheck(pid, data);
	}
}
