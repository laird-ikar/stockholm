/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockholm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:38:47 by bguyot            #+#    #+#             */
/*   Updated: 2023/05/19 15:26:12 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/stockholm.hpp"

int	main(int argc, char **argv)
{
	Stockholm	stockholm;

	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i],"--help") || !strcmp(argv[i],"-h"))
			stockholm.setHelp(true);
		else if (!strcmp(argv[i],"--version") || !strcmp(argv[i],"-v"))
			stockholm.setVersion(true);
		else if (!strcmp(argv[i],"--silent") || !strcmp(argv[i],"-s"))
			stockholm.setSilent(true);
		else if (!strcmp(argv[i],"--reverse") || !strcmp(argv[i],"-r"))
		{
			if (i + 1 < argc && argv[i + 1][0] != 0)
			{
				stockholm.setReverse(true);
				stockholm.setKey(argv[i + 1]);
			}
			else
			{
				stockholm.setHelp(true);
			}
		}
	}
	stockholm.run();
}