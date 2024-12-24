#include <stdio.h> //standart input output // printf
#include <stdlib.h>
#include <unistd.h>

char   *convert_to_bin(unsigned int num)
{
    char *buff = malloc(9 * sizeof(char)); // Выделяем память динамически
    if (!buff)
        return NULL;
    int     i;
    i = 7;
    while (i >= 0)
    {
        buff[i] = num % 2 + '0';
        i--;
        num = num / 2;
    }
	return(buff);
}

int main(int argc, char **argv) //Hello
{
	int i = 0;
	unsigned int num;
	char *arr;
	int j = 0;

	while(argv[1][i])
	{
		num = argv[1][i];
		arr = convert_to_bin(num);
		i++;
	}
	while(arr[j])
	{
		write(1, &arr[j], 1);
		j++;
	}
	printf("\n");
}

// посчитатьколличество букв в тексте
// сделать массив с размеров 8 * на колличество букв
