/*
 * logger.hh
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
#ifndef LOGGER_HH_
#define LOGGER_HH_
#include <map>;

#include "chatopia.hh";
enum LogLvls {
	LOG_RAWIO = 0,
	LOG_DEBUG = 1,
	LOG_VERBOSE = 2,
	LOG_DEFAULT = 3,
	LOG_SPARSE = 4,
	LOG_NONE = 5
};

enum Colors {
	RESET = 0,
	BOLD = 1,
	UNDERLINE = 4,
	BLINK = 5,
	INVERTED = 7,
	BLACK = 30,
	RED = 31,
	GREEN = 32,
	YELLOW = 33,
	BLUE = 34,
	MAGENTA = 35,
	CYAN = 36,
	WHITE = 37
};
struct LogType {
	char* type;
	int level;
};
class LogFile {
public:
	LogFile(char* logfile, LogType* type, LogLvls level, Colors* color);

	char* log;
	LogType* type;
	LogLvls level;
	Colors* color;
};

class Loger {
public:
	std::map<char*, LogFile*> Logs;
	std::map<char*, LogType*> Types;
	/**
	 * Adds a log type to LogType
	 *
	 * @param type key index of the log to report on.
	 * @param lvl Reporting level of the log type.
	 */
	void AddLogType(char* type, LogLvls lvl);

	/**
	 * Deletes a log type
	 *
	 * @param type key index of the log to report on.
	 * @param lvl Reporting level of the log type.
	 */
	 void DelLogType(char* type);

	 /**
	  * Adds a log to the logs to print to
	  *
	  * @param name Key name to target the log.
	  * @param type Type of log in LogTypes.
	  * @param file Filename of the log.
	  * @param level Default log level to report at
	  * @param color Color to show in the console.
	  */
	 void AddLog(char* name, LogType* type, char* file, LogLvls level, Colors* color);

	 /**
	  *  adds a line to Log
	  * @param name Key name to target the log.
	  * @param msg Message to add to log.
	  */
	 void Log(char* name, char* msg);
};
#endif /* LOGGER_HH */
