/*
 * config.hh
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

#ifndef CONFIG_HH_
#define CONFIG_HH_

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
	void Read();

};


#endif /* CONFIG_HH_ */
