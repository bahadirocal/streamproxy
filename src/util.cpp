#include "util.h"

#include <errno.h>
#include <stdarg.h>
#include <syslog.h>
#include <stdio.h>
#include <string.h>

#include <string>
using std::string;

#include <ios>
using std::ios;

#include <sstream>
#include <iomanip>
using std::stringstream;
using std::istringstream;
using std::ostringstream;
using std::hex;
using std::setfill;
using std::setw;
using std::fixed;
using std::setprecision;

bool Util::foreground = false;

void Util::vlog(const char * format, ...) throw()
{
    va_list ap;

    va_start(ap, format);

    if(foreground)
	{
        vfprintf(stderr, format, ap);

		if(errno)
			fprintf(stderr, ", system error: %s", strerror(errno));

		fputs("\n", stderr);
	}
    else
	{
        vsyslog(LOG_WARNING, format, ap);

   		if(errno)
			vsyslog(LOG_WARNING, "system error: %s", strerror(errno));
	}

    va_end(ap);
}

string Util::int_to_string(int in) throw()
{
	stringstream conv;
	conv << in;
	return(conv.str());
}

string Util::hex_to_string(int in, int width) throw()
{
	stringstream conv;
	conv << setw(width) << setfill('0') << hex << in;
	return(conv.str());
}

string Util::float_to_string(double value, int precision) throw()
{
	stringstream conv;
	conv << fixed << setprecision(precision) << value;
	return(conv.str());
}

double Util::string_to_float(string in) throw()
{
	stringstream	conv;
	double			rv;

	try
	{
		conv.str(in);
		conv >> rv;
	}
	catch(...)
	{
		return(-1);
	}

	return(rv);
}

int Util::string_to_int(string in) throw()
{
	stringstream	conv;
	int				rv;

	try
	{
		conv.str(in);
		conv >> rv;
	}
	catch(...)
	{
		return(-1);
	}

	return(rv);
}