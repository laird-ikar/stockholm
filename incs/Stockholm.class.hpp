/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stockholm.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:43:26 by bguyot            #+#    #+#             */
/*   Updated: 2023/05/19 10:28:54 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Stockholm;
#pragma once

#include <string>
#include <iostream>
#include "constants.hpp"

class Stockholm
{
private:
	bool _help;
	bool _version;
	bool _silent;
	bool _reverse;
	std::string _key;

	void _printHelp(void);
	void _printVersion(void);
	void _decipher(void);
	void _cipher(void);

public:
	Stockholm(void);
	~Stockholm(void);

	void setHelp(bool help);
	void setVersion(bool version);
	void setSilent(bool silent);
	void setReverse(bool reverse);
	void setKey(std::string key);
	void run(void);
};