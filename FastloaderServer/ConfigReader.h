#pragma once
#include <libconfig.h++>
class ConfigReader
{
	libconfig::Config* conf_;
public:
	libconfig::Config* conf() const;
	explicit ConfigReader(
		std::string name_path = "/etc/fastloaderserver/config.conf");
};
