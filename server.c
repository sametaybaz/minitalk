/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaybaz <aaybaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:15:03 by aaybaz            #+#    #+#             */
/*   Updated: 2023/02/02 19:29:58 by aaybaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	bitstorage(int poolsignal)
{
	static unsigned char	x = 0;
	static int				i = 0;

	if (poolsignal == SIGUSR1)
		x = x | 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", x);
		i = 0;
		x = 0;
	}
	x = x << 1;
}

int	main(void)
{
	ft_printf("Server started with PID: %d\n ", getpid());
	signal (SIGUSR1, bitstorage);
	signal (SIGUSR2, bitstorage);
	while (1)
		pause();
	return (0);
}
