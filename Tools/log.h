/*
ICode Library:log.h
This library realizes the output of debugging information.
*/

#ifndef ICODE_LOG__
#define ICODE_LOG__

#if __cplusplus < 201103L
#error "should use C++11 implementation"
#endif

#include "chrono_meter.h"
#include <cstdio>

namespace ICode
{
	enum LogLevel
	{
		LEVEL_CLOSE=0,
		LEVEL_VERBOSE=1,
		LEVEL_DEBUG=2,
		LEVEL_INFO=3,
		LEVEL_WARN=4,
		LEVEL_ERROR=5,	
	};
	
	template<typename... Args>
	void logcat(const char* format,Args const&... args)
	{
		if(sizeof...(args)==0)
		{
			fprintf(stderr,"%s",FormatTime().c_str());
			fprintf(stderr,"ICODE_LOG:%s",format);
		}
		else
		{
			fprintf(stderr,"%s",FormatTime().c_str());
			fprintf(stderr,"ICODE_LOG:") ;
			fprintf(stderr,format,args...);
		}
	}
	
	class Logger
	{
		private:
			int _level=LEVEL_ERROR+1;
			
		public:
			void setLevel(int level)
			{
				if(level==LEVEL_CLOSE)
					level=LEVEL_ERROR+1;
				
				_level=level;
			}
			
			template<typename... Args>
			void verbose(const char* fmt,Args const&... args)
			{
				if(_level<=LEVEL_VERBOSE)
					logcat(fmt,args...);
			}
			
			template<typename... Args>
			void debug(const char* fmt,Args const&... args)
			{
				if(_level<=LEVEL_DEBUG)
					logcat(fmt,args...);
			}
			
			template<typename... Args>
			void info(const char* fmt,Args const&... args)
			{
				if(_level<=LEVEL_INFO)
					logcat(fmt,args...);
			}
			
			template<typename... Args>
			void warn(const char* fmt,Args const&... args)
			{
				if(_level<=LEVEL_WARN)
					logcat(fmt,args...);
			}
			
			template<typename... Args>
			void error(const char* fmt,Args const&... args)
			{
				if(_level<=LEVEL_ERROR)
					logcat(fmt,args...);
			}
	};
	
}

#endif 
