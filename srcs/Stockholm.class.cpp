/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stockholm.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:51:57 by bguyot            #+#    #+#             */
/*   Updated: 2023/05/19 10:26:36 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Stockholm.class.hpp"

Stockholm::Stockholm(void)
{
	this->_help = false;
	this->_version = false;
	this->_silent = false;
	this->_reverse = false;
	this->_key = "";
}

Stockholm::~Stockholm(void)
{}

void	Stockholm::setHelp(bool help)
{
	this->_help = help;
}

void	Stockholm::setVersion(bool version)
{
	this->_version = version;
}

void	Stockholm::setSilent(bool silent)
{
	this->_silent = silent;
}

void	Stockholm::setReverse(bool reverse)
{
	this->_reverse = reverse;
}

void	Stockholm::setKey(std::string key)
{
	this->_key = key;
}

void	Stockholm::run(void)
{
	if (this->_help)
		this->_printHelp();
	else if (this->_version)
		this->_printVersion();
	else if (this->_reverse)
		this->_decipher();
	else
		this->_cipher();
}

void	Stockholm::_printHelp(void)
{}

void	Stockholm::_printVersion(void)
{
	std::cout << "stockholm v" << VERSION << std::endl;
}

void	Stockholm::_decipher(void)
{}

void	Stockholm::_cipher(void)
{}