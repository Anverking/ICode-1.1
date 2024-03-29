/*
ICode Library:chrono_meter.h
This library implements the time period statistical class chrono_meter based on C++11 library chrono.
*/

#ifndef ICODE_CHRONO_METER__
#define ICODE_CHRONO_METER__

#if __cplusplus < 201103L
#error "should use C++11 implementation"
#endif

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace ICode
{
	typedef std::chrono::milliseconds tick_t;
	
	inline tick_t TimeStamp()
	{
		using namespace std::chrono;
		return duration_cast<milliseconds>(system_clock::now()-time_point<system_clock>());
	}
	
	inline uint64_t GetTickCount()
	{
		using namespace std::chrono;
		return TimeStamp().count();
	}
	
	inline std::string FormatTime(uint64_t ts)
	{
		std::time_t t=ts;
		time_t tt=(time_t)(t/1000);
		int micsec=t%1000;
		struct tm* local_time=NULL;
		local_time=localtime(&tt);
		char szBuffer[32]={0};
		int len=strftime(szBuffer,sizeof(szBuffer),"%Y-%m-%d %H:%M:%S",local_time);
		sprintf(szBuffer+len,".%d",micsec);
		return std::string(szBuffer);
	}
	
	inline std::string FormatTime()
	{
		return FormatTime(GetTickCount());
	}
	
	class chrono_meter
	{
		private:
			std::chrono::time_point<std::chrono::high_resolution_clock>m_begin;
			
		public:
			chrono_meter():m_begin(std::chrono::high_resolution_clock::now()){}
			
			void reset()
			{
				m_begin=std::chrono::high_resolution_clock::now();
			}
			
			int64_t Elapsed() const
			{
				return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-m_begin).count();
			}
			
			int64_t ElapsedMicro() const
			{
				return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()-m_begin).count();
			}
			
			int64_t ElapsedNano() const
			{
				return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-m_begin).count();
			}			
			
			int64_t ElapsedSeconds() const
			{
				return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now()-m_begin).count();
			}		
	
			int64_t ElapsedMinutes() const
			{
				return std::chrono::duration_cast<std::chrono::minutes>(std::chrono::high_resolution_clock::now()-m_begin).count();
			}
			
			int64_t ElapsedHours() const
			{
				return std::chrono::duration_cast<std::chrono::hours>(std::chrono::high_resolution_clock::now()-m_begin).count();
			}
	};
}

#endif
