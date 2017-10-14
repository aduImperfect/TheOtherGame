///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: Log.h
/// DATE: 2017-10-15 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Precompiled.h"

#define LOGASSERT(condition, message)		\
{											\
	if(!(condition))						\
	{										\
		Log::Error(std::string(message));	\
		assert(false);						\
	}										\
}

namespace Log
{
	//The different levels of Logs. For outputting information, warnings or errors.
	void Info(const std::string& message);
	void Warning(const std::string& message);
	void Error(const std::string& message);

	//Track the value of the specified label and graph it between its min and max.
	void TrackValue(const std::string& label, float value, float graphMin = FLT_MAX, float graphMax = FLT_MAX);

	//Performance Probe for the specified label.
	struct PerfProbe
	{
		PerfProbe(const std::string& label);
		~PerfProbe();

		double startTime;
		const std::string label;
	};
}

#define PERFPROBE(label) auto __probe = Log::PerfProbe(std::string(label));
