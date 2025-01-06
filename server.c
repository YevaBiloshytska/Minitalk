/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybiloshy <ybiloshy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:44:47 by ybiloshy          #+#    #+#             */
/*   Updated: 2025/01/06 07:10:24 by ybiloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <string.h>

int	convert_to_dec(int *arr)
{
	int	i;
	int	dec;

	dec = 0;
	i = 0;
	while (i < 8)
	{
		dec = dec * 2 + arr[i];
		i++;
	}
	return (dec);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	char		c;
	static int	letter_in_bit[8] = {0};
	static int	bit_index = 0;

	(void)context;
	if (signum == SIGUSR1)
		letter_in_bit[bit_index] = 0;
	else if (signum == SIGUSR2)
		letter_in_bit[bit_index] = 1;
	bit_index++;
	if (bit_index == 8)
	{
		c = convert_to_dec(letter_in_bit);
		if (c == '\0')
			ft_printf("\n");
		write(1, &c, 1);
		bit_index = 0;
		memset(letter_in_bit, 0, 8 * sizeof(int));
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Server PID: %d\n", getpid());
	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
