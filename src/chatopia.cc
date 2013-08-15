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
#include "chatopia.hh";


using namespace std;
Chatopia* ServerInstance = NULL;
void Chatopia::Run() {

}
ENTRYPOINT {
	//TODO: fix this error
	new Chatopia(argc, argv);
	ServerInstance->Run();
  cout << "\x1b[1mChatopia IRC Services\x1b[0m" << endl << endl;

  delete ServerInstance;
  return 0;
}


