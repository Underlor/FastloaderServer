#include <cstdio>
#include <iostream>
#include <libconfig.h++>
#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include "SocketServer.h"
#include <arpa/inet.h>
#include "ConfigReader.h"

int main()
{
	/*sql::Driver     *driver;
	sql::Connection    *con;
	sql::Statement    *stmt;
	sql::ResultSet     *res;

	driver = get_driver_instance();
	con = driver->connect("tcp://5.9.94.46:3306", "loaderadm", "456258");
	if (con == NULL)
	{
		std::cout << "Can't connect!" << std::endl;
	}
	else
	{
		std::cout << "Connected!" << std::endl;
	}

	stmt = con->createStatement();
	stmt->execute("USE loadbd");
	res = stmt->executeQuery("SELECT id, num FROM test WHERE id = 1 union select 1,2,3,4");
	while (res->next()) 
	{
		std::cout << "id = " << res->getInt("id") << "; ";
		std::cout << "num = " << res->getInt("num") << ";" << std::endl;
	}
	delete con;*/



	ConfigReader config;
	try
	{
		std::cout << "Version = " << config.conf()->lookup("v").c_str() << std::endl;
		
	}
	catch (libconfig::SettingNotFoundException e)
	{
		std::cout << "ConfigReader ERROR: Can't find the key" << e.getPath() << std::endl;
		exit(1);
	}
	//	SocketServer server(40125);
//	server.Listen();
//
//	SocketClient *client = server.Accept();
//	
//	std::cout << "ip: " << client->GetAddrStr() << std::endl
//		<< "descriptor: " << client->descriptor << std::endl;

    return 0;
}
