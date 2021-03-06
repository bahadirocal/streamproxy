#ifndef _types_h_
#define _types_h_

#include "config.h"

#include <string>
#include <vector>
#include <map>

typedef std::vector<std::string>				StringVector;
typedef std::map<std::string, int>				PidMap;
typedef std::map<std::string, std::string>		UrlParameterMap;
typedef std::map<std::string, std::string>		HeaderMap;
typedef std::map<std::string, std::string>		CookieMap;
typedef std::map<std::string, std::string>		StreamingParameters;

#endif
