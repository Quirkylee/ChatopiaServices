/*
 * logger.cc
 *
 *  Created on: Aug 25, 2013
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
#include "logger.hh";


LogFile::LogFile(char* logfile, LogType* type, LogLvls level, Colors* color) {
		this->log = logfile;
		this->type = type;
		this->level = level;
		this->color = color;
	}
void Loger::AddLogType(char* type, LogLvls lvl) {
	switch(lvl) {
		case LOG_RAWIO:
		case LOG_DEBUG:
		case LOG_VERBOSE:
		case LOG_DEFAULT:
		case LOG_SPARSE:
		case LOG_NONE:
		Types.insert(std::make_pair<char*,LogLvls>(type, lvl));
		break;
	}
}
void Loger::AddLog(char* name, LogType* type, char* file, LogLvls level, Colors* color) {
	switch(level) {
	case LOG_RAWIO:
	case LOG_DEBUG:
	case LOG_VERBOSE:
	case LOG_DEFAULT:
	case LOG_SPARSE:
	case LOG_NONE:
		LogFile* log = new LogFile(file,type, level,color);
		Logs.insert(std::make_pair<char*,LogFile*>(name,log));
		break;

	}
}
void Loger::Log(char* name, char* msg) {

}
