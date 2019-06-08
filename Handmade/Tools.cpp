#include "Tools.h"





void CutString(std::string& sentence, int start, int lenght)
{
	sentence = sentence.substr(start, lenght);
}

void AddString(std::string & string1, std::string & string2)
{
	string1 += string2;
}

void AddString(std::string & string1, const char * string2)
{
	string1 += string2;
}

void ListString(std::string m_string)
{
	if (m_string.size() == 0)
	{
		std::cout << "Is not working" << std::endl;
	}
	else
	{
		// Sub
		for (std::size_t i = 0; i < m_string.size(); i++)
		{
			std::cout << "Character #" << i + 1 << " is" << m_string[i] << std::endl;
		}
		// Itinerator
		int count = 1;
		for (auto it = m_string.begin(); it != m_string.end(); it++)
		{
			//this version displays also the number
			std::cout << "Character #" << count++ << *it << std::endl;
		}

	}
}
//make sub a vector of strings
void ParseString(std::string & str, std::vector<std::string>& sub, char token)
{

	unsigned int pos = 0;

	while ((pos = str.find(token)) != std::string::npos)
	{
		sub.push_back(str.substr(0, pos));
		std::cout << token << std::endl;
		str.erase(0, pos + 1);

	}

	sub.push_back(str);
}


