/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingywu <jingywu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:05:27 by jingywu           #+#    #+#             */
/*   Updated: 2026/03/06 11:53:55 by jingywu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int				bit_count = 0;
	static unsigned char	c = 0;

	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
