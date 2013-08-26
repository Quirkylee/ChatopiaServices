/*
 * chatopia.h
 *
 *  Created on: Aug 13, 2013
 *      Author: matthewl
 *
 * Copyright 2013 Matthew Lindsey (chatopia.net)
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#ifndef CHATOPIA_H_
#define CHATOPIA_H_

#include <fstream>;
#include <iostream>;
#include <string>;
#include <sstream>;
#include <map>;
#include <cstring>;
#include "config.hh";
#include "servconfig.hh";
#include "logger.hh";


/** Template function to convert any input type to std::string
*/
template<typename T> inline std::string ToNumeric(const T &in)
{
if (in == 0)
return "0";
T quotient = in;
std::string out;
while (quotient)
{
out += "0123456789"[ std::abs( (long)quotient % 10 ) ];
quotient /= 10;
}
if (in < 0)
out += '-';
std::reverse(out.begin(), out.end());
return out;
}


/** Template function to convert any input type to std::string
*/
inline std::string ConvToStr(const long in)
{
return ToNumeric(in);
}

/** Template function to convert any input type to std::string
*/
inline std::string ConvToStr(const char* in)
{
return in;
}

/** Template function to convert any input type to std::string
*/
inline std::string ConvToStr(const bool in)
{
return (in ? "1" : "0");
}

/** Template function to convert any input type to std::string
*/
inline std::string ConvToStr(char in)
{
return std::string(in,1);
}

/** Template function to convert any input type to std::string
*/
template <class T> inline std::string ConvToStr(const T &in)
{
std::stringstream tmp;
if (!(tmp << in)) return std::string();
return tmp.str();
}

class Chatopia {
public:
	/**
	 * The constructor initializes sub
	 * @param argc The argument count passed to main()
	 * @param argv The argument list passed to main()
	 */
	Chatopia(int argc, char** argv);

	/**
	 * Holds Service Configuration Data
	 */
	ServiceConfig* Config;
	/**
	 * Initialize the logger class
	 */
	Logger* Logs;
	/**
	 * Starts server
	*/
	void Run();
};


#endif /* CHATOPIA_H_ */
