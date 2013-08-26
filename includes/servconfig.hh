/*
 * serviceconfig.hh
 *
 *  Created on: Aug 16, 2013
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

#ifndef SERVCONFIG_HH_
#define SERVCONFIG_HH_

#include "chatopia.hh";

struct CmdLineConf {
		/**
		 * argc from startup
		 */
		int argc;

		/**
		 * argv from startup
		 */
		char** argv;

		/**
		 * if --nofork at commandline is specified the deamon won't fork to background.
		 */
		bool nofork;
	};
class ServiceConfig {
public:
	CmdLineConf cmdline;
	void ReadConf();

};
class ConfigTags {
public:
	const std::string tag;
	const std::string source_line;
	const std::string source_name;
};

#endif /* SERVCONFIG_HH_ */
