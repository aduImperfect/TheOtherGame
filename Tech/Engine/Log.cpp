///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: Log.cpp
/// DATE: 2017-10-15 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#include "Precompiled.h"
#include "Log.h"

namespace Log
{
#undef APIENTRY
#include <Windows.h>

	void Info(const std::string& message)
	{
#ifdef LOGTOSYSCONSOLE
		std::cout << message << std::endl;
#endif // LOGTOSYSCONSOLE
		//TODO: Core calls logger to write the message in an info style.
	}

	void Warning(const std::string& message)
	{
#ifdef LOGTOSYSCONSOLE
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << message << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif // LOGTOSYSCONSOLE
		//TODO: Core calls logger to write the message in an warning style.
	}

	void Error(const std::string& message)
	{
#ifdef LOGTOSYSCONSOLE
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << message << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif // LOGTOSYSCONSOLE
		//TODO: Core calls logger to write the message in an error style.
	}

	void TrackValue(const std::string& label, float value, float graphMin, float graphMax)
	{
		//TODO: Core calls logger to track the value by graphing it.
	}

	PerfProbe::PerfProbe(const std::string& label) : startTime(/*TODO: glfwGetTime()*/), label(label)
	{
		//TODO: Core calls logger to push the performance probe.
	}

	PerfProbe::~PerfProbe()
	{
		//TODO: Core calls logger to pop the performance probe based on glfwGetTime() - startTime.
	}
}
