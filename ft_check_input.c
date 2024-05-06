/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:05:44 by kkoval            #+#    #+#             */
/*   Updated: 2024/05/06 18:25:19 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// it converts our arguments from a string to a long long int
long long int	ft_atoi(char *str)
{
	long long int	res;
	int				sig;
	int				i;

	res = 0;
	sig = 1;
	i = 0;
	if (str[0] == '-')
		sig = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * sig;
	return (res);
}

// checks if each argument passed to the program is indeed an int
int	ft_check_int(int argc, char **argv)
{
	int	x;
	int	y;

	x = 1;
	while (x < argc)
	{
		y = 0;
		if (argv[x][y] == '\0' || ((argv[x][y] == '-'
			|| argv[x][y] == '+') && ft_strlen(argv[x]) == 1))
			return (0);
		while (argv[x][y] != '\0')
		{
			if (y > 10)
				return (0);
			if (argv[x][y] < '0' || argv[x][y] > '9')
			{
				if (y != 0 || argv[x][y] != '-')
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

// if duplicates are detected it will return 0
int	ft_check_duplicate(long long int *arr, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (i < len)
	{
		x = 0;
		while (x < i)
		{
			if (arr[x] == arr[i])
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

// our arguments have to be in between the integer limits
int	ft_check_limits(long long int num)
{
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

// controller function responsible for validating and processing the input 
// arguments passed to the program
int	ft_check_input(int argc, char **argv)
{
	int				i;
	long long int	*nums;
	long long int	aux;

	nums = malloc(sizeof(long long int) * (argc - 1));
	if (!nums)
		return (0);
	if (!ft_check_int(argc, argv))
		return (ft_free_int(nums, 0));
	i = 0;
	while (i + 1 < argc)
	{
		aux = ft_atoi(argv[i + 1]);
		if (!ft_check_limits(aux))
			return (ft_free_int(nums, 0));
		nums[i] = (int)aux;
		i++;
	}
	if (!ft_check_duplicate(nums, (size_t)argc - 1))
		return (ft_free_int(nums, 0));
	return (ft_free_int(nums, 1));
}
