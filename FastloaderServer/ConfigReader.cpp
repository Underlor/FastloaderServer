#include "ConfigReader.h"
#include <iostream>

libconfig::Config* ConfigReader::conf() const
{
	return conf_;
}

ConfigReader::ConfigReader(std::string name_path): conf_(new libconfig::Config)
{
	try
	{
		conf_->readFile(name_path.c_str());
	}
	catch (libconfig::ParseException e)
	{
		std::cout << " ConfigReader ERROR:" << e.getError() << " line:" << e.getLine() << std::endl;
		exit(1);
	}
	catch(libconfig::FileIOException e)
	{
		std::cout << " ConfigReader ERROR:" << "Can't find the config here: " << name_path << std::endl;
		exit(1);
	}
}
