/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybiloshy <ybiloshy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:44:37 by ybiloshy          #+#    #+#             */
/*   Updated: 2024/12/24 18:16:57 by ybiloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*convert_a_word(unsigned int num)
{
    char	*buff;
	int		i;
	
	i = 7;
	buff = malloc(9 * sizeof(char)); // Выделяем память динамически
    if (!buff)
        return (NULL);
    while (i >= 0)
    {
        buff[i] = num % 2 + '0';
        i--;
        num = num / 2;
    }
	buff[8] = '\0';
	return(buff);
}

//from libft (ft_strlen)
size_t	amount_of_chars(char *text)
{
	size_t	i;

	i = 0;
	while(text[i])
		i++;
	return (i);
}

char	*get_encryption(char *text)
{
	char			*bin_text;
	size_t	len;
	int				i;
	char			*bin_char;

	i = 0;
	len = amount_of_chars(text);
	bin_text = malloc((len * 8 + 1) * sizeof(char));
	if (!bin_text)
        return (NULL);
	while(text[i]) //Hello
	{
		bin_char = convert_a_word((unsigned int)text[i]);
		if (!bin_char) // Проверяем, успешно ли выделилась память
        {
            free(bin_text); // Освобождаем уже выделенную память
            return (NULL);
        }
		memcpy(bin_text + (i * 8), bin_char, 8); //chnge to ft_memcpy from libft
		free(bin_char);
		i++;
	}
	bin_text[len * 8] = '\0';
	return (bin_text);
}

int	main(int argc, char **argv)
{
	char	*bin_encrypt;
	
	if (argc == 3)
		bin_encrypt = get_encryption(argv[2]);
	printf("%s", bin_encrypt);
	free(bin_encrypt);
	return (0);
}
//Отправить сообщение на сервер (через его PID)
//Создайте условие остановки, чтобы сервер знал, когда он закончит прием сообщения.