/*
 * chatopia.cpp
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
#include <fstream>;
#include <iostream>;
#include <utility>;
#include <getopt.h>
#include "chatopia.hh";


using namespace std;
Chatopia* ServerInstance = NULL;
void Chatopia::Run() {

}
Chatopia::Chatopia(int argc, char** argv) {
	/**
	 * Initialize stuff so we do not lose them later
	 */
	this->Config = 0;
	ServerInstance = this;
	int do_nofork = 0, do_version = 0;


	this->Config = new ServiceConfig;
	this->Logs = new Logger;
	/**
	 * Pass argv off for later use.
	 */
	this->Config->cmdline.argv = argv;

	/**
	 * Pass argc off for later use.
	 */
	this->Config->cmdline.argc = argc;

	/**
	 * parse command and set longopts
	 */
	struct option longopts[] =
	{
			{ "nofork",	no_argument,		&do_nofork,	1	},
			{ "version",	no_argument,		&do_version,	1	},
			{ 0, 0, 0, 0 }
	};
	int c;
	int index;
	while((c = getopt_long(argc, argv, ":c:", longopts, &index)) != -1) {
		switch (c)
		{
		case 0:
			/* just keep going */
			break;
		case '?':
			/* Unknown parameter */
		default:
			/* Fall through to handle other weird values too */
			cout << "Unknown parameter '" << argv[optind-1] << "'" << endl;
			cout << "Usage: " << argv[0] << " [--nofork] [--version]" << endl;
			exit(0);
			break;
		}
	}

	/* prints version if specified on command line */
	if(do_version != 0) {
		cout << endl << VERSION << endl;
		exit(0);
	}

	/* set command line argument values */
	Config->cmdline.nofork = (do_nofork != 0);
	cout << "\x1b[50m\x1b[33mChatopia IRC Services\x1b[0m" << endl << endl;

}

int main(int argc, char** argv) {
	new Chatopia(argc, argv);
	ServerInstance->Run();

  delete ServerInstance;
  return 0;
}
