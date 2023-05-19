/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stockholm.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:51:57 by bguyot            #+#    #+#             */
/*   Updated: 2023/05/19 13:16:53 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Stockholm.class.hpp"

Stockholm::Stockholm(void): _path(std::filesystem::path{getenv("HOME") + std::string("/infection/")})
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
		this->_decipher(this->_path);
	else
		this->_cipher(this->_path);
}

void	Stockholm::_printHelp(void)
{
	std::cout << "Usage:" << std::endl;
	std::cout << "\t./stockholm [-hv]" << std::endl;
	std::cout << "\t./stockholm [-s] [-r] [-r key]" << std::endl;
	std::cout << std::endl;
	std::cout << "Description:" << std::endl;
	std::cout << "\tstockholm is a 42 project that mimic the encyption of files, inspired by Wannacry but limited to the \"~/infection/\" folder. This project is for educational purposes only. You should never use the type of program for malicious purposes." << std::endl;
	std::cout << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "\t-h\t\tPrint this help message and exit" << std::endl;
	std::cout << "\t-v\t\tPrint the version and exit" << std::endl;
	std::cout << "\t-s\t\tSilent mode" << std::endl;
	std::cout << "\t-r\t\tReverse mode, use the key to decrypt the files" << std::endl;
	std::cout << std::endl;
}

void	Stockholm::_printVersion(void)
{
	std::cout << "stockholm v" << VERSION << std::endl;
}

void	Stockholm::_decipher(std::filesystem::path path)
{
	(void) path;
}

void	Stockholm::_cipher(std::filesystem::path path)
{
	std::cout << "ciphering " << path << std::endl;
	std::cout << std::filesystem::exists(path) << std::endl;
	if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path))
	{
		std::cout << "Error while cyphering: path " << path << " does not exist" << std::endl;
		return ;
	}
	for (const auto & entry : std::filesystem::directory_iterator(path))
	{
		std::cout << entry.path() << std::endl;
		if (std::filesystem::is_directory(entry.path()))
			this->_cipher(entry.path());
		else
			this->_cipherFile(entry.path());
	}
}

void	Stockholm::_cipherFile(std::filesystem::path path)
{
	//check if the file path extension is in the RANSOMWARE_EXTENSIONS
	

	
}