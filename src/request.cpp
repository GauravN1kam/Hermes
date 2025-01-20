#include "../include/request.hpp"
#include <sstream>
#include <string>


Request::Request(std::string http)
{
	full_path = http;
}


std::string Request::getBody(){
	std::string body = "";
	bool startReading = false;
	for(int i = 0; i < full_path.size(); i++)
	{
		if(startReading == true)
		{
			body += full_path[i];
		}
		if(full_path[i] == '\r\n\r\n' && startReading == false)
		{
			startReading = true;
		}
	}

	return body;

}
