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

#include <iostream>;

#include "config.hh";

#ifdef _WIN32|| _WIN64
   #define ENTRYPOINT int smain(int argc, char** argv)
#elif __APPLE__ || __linux || __unix || __posix
    #define ENTRYPOINT int main(int argc, char** argv)
#endif
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
		 * Starts server
		 */
		void Run();
};
ENTRYPOINT;
#endif /* CHATOPIA_H_ */
