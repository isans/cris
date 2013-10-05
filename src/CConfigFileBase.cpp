
#include "CConfigFileBase.h"
#include <iostream>
#include <fstream> 
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;
using namespace cris;

string cris::lowerCase(const string& str)
{
	string outStr( str );

	transform(
		outStr.begin(), outStr.end(),		// In
		outStr.begin(),			// Out
		(int(*)(int)) tolower );
	return outStr;
}
std::string cris::trim(const std::string &str)
{
	if (str.empty())
	{
		return std::string();
	}
	else
	{
		size_t s = str.find_first_not_of(" \t");
		size_t e = str.find_last_not_of(" \t");
		if (s==std::string::npos || e==std::string::npos)
			return std::string();
		else	return str.substr( s, e-s+1);
	}
}
char *cris::strtok( char *str, const char *strDelimit, char **context )
{
#if defined(_MSC_VER) && (_MSC_VER>=1400)
	// Use a secure version in Visual Studio 2005:
	return ::strtok_s(str,strDelimit,context);
#else
	// Use standard version:
	return ::strtok(str,strDelimit);
#endif
}
/*---------------------------------------------------------------
						tokenize
---------------------------------------------------------------*/
void  cris::tokenize(
	const std::string			&inString,
	const std::string			&inDelimiters,
	std::vector<std::string>	&outTokens ) 
{
    char	*nextTok,*context;

	outTokens.clear();
	char *dupStr = ::strdup(inString.c_str());

	nextTok = strtok (dupStr,inDelimiters.c_str(),&context);
	while (nextTok != NULL)
	{
		outTokens.push_back( std::string(nextTok) );
		nextTok = strtok (NULL,inDelimiters.c_str(),&context);
	};

	free(dupStr);
}
int cris::_strcmpi(const char*str1,const char*str2) 
{
#ifdef WIN32
#if defined(_MSC_VER) && (_MSC_VER>=1400)
	return ::_strcmpi( str1,str2 );
#else
	return ::strcmpi( str1,str2 );
#endif
#else
	return ::strcasecmp( str1,str2 );
#endif
}
int cris::vsnprintf(char *buf, size_t bufSize, const char *format, va_list args) 
{
#if defined(_MSC_VER)
#if (_MSC_VER>=1400)
	// Use a secure version in Visual Studio 2005:
	return ::vsnprintf_s (buf, bufSize, _TRUNCATE, format, args);
#else
	return ::vsprintf(buf,format, args);
#endif
#else
	// Use standard version:
	return ::vsnprintf(buf, bufSize,format, args);
#endif
}
void  CConfigFileBase::write(const std::string &section, const std::string &name, double value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	writeString(section, name, format("%e",value), name_padding_width,value_padding_width,comment);
}
void  CConfigFileBase::write(const std::string &section, const std::string &name, float value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	writeString(section, name, format("%e",value), name_padding_width,value_padding_width,comment);
}
void  CConfigFileBase::write(const std::string &section, const std::string &name, int value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	writeString(section, name, format("%i",value), name_padding_width,value_padding_width,comment);
}

void  CConfigFileBase::write(const std::string &section, const std::string &name, const std::string &value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	writeString(section, name, value , name_padding_width,value_padding_width,comment);
}

void  CConfigFileBase::write(const std::string &section, const std::string &name, const std::vector<int> &value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	string str;
	for (std::vector<int>::const_iterator it=value.begin();it!=value.end();++it)
		str+=format("%i ", *it);
	writeString(section, name, str , name_padding_width,value_padding_width,comment);
}

void  CConfigFileBase::write(const std::string &section, const std::string &name, const std::vector<unsigned int> &value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	string str;
	for (std::vector<unsigned int>::const_iterator it=value.begin();it!=value.end();++it)
		str+=format("%u ", *it);
	writeString(section, name, str , name_padding_width,value_padding_width,comment);
}

void  CConfigFileBase::write(const std::string &section, const std::string &name, const std::vector<float> &value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	string str;
	for (std::vector<float>::const_iterator it=value.begin();it!=value.end();++it)
		str+=format("%.9e ", *it);
	writeString(section, name, str , name_padding_width,value_padding_width,comment);
}

void  CConfigFileBase::write(const std::string &section, const std::string &name, const std::vector<double> &value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	string str;
	for (std::vector<double>::const_iterator it=value.begin();it!=value.end();++it)
		str+=format("%.16e ", *it);
	writeString(section, name, str , name_padding_width,value_padding_width,comment);
}

void  CConfigFileBase::write(const std::string &section, const std::string &name, const std::vector<bool> &value, const int name_padding_width, const int value_padding_width, const std::string &comment )
{
	string str;
	for (std::vector<bool>::const_iterator it=value.begin();it!=value.end();++it)
		str+=format("%c ", *it ? '1':'0');
	writeString(section, name, str , name_padding_width,value_padding_width,comment);
}

/** Write a generic string with optional padding and a comment field ("// ...") at the end of the line. */
void  CConfigFileBase::writeString(const std::string &section,const std::string &name, const std::string &str, const int name_padding_width, const int value_padding_width, const std::string &comment)
{
	if (name_padding_width<1 && value_padding_width<1 && comment.empty())
		this->writeString(section,name,str);  // Default (old) behavior.

	std::string name_pad;
	if (name_padding_width>=1)
	     name_pad = cris::format("%*s",-name_padding_width, name.c_str());  // negative width: printf right padding
	else name_pad = name;

	std::string value_pad;
	if (value_padding_width>=1)
	     value_pad = cris::format(" %*s",-value_padding_width, str.c_str());   // negative width: printf right padding
	else value_pad = str;

	if (!comment.empty())
	{
		value_pad += std::string("// ");
		value_pad += comment;
	}

	this->writeString(section,name_pad,value_pad);
}


/*---------------------------------------------------------------
					read_double
 ---------------------------------------------------------------*/
double  CConfigFileBase::read_double(const std::string &section, const std::string &name, double defaultValue, bool failIfNotFound ) const
{
	return atof( readString(section,name,format("%.16e",defaultValue),failIfNotFound).c_str());
}

/*---------------------------------------------------------------
					read_float
 ---------------------------------------------------------------*/
float  CConfigFileBase::read_float(const std::string &section, const std::string &name, float defaultValue, bool failIfNotFound ) const
{
	return (float)atof( readString(section,name,format("%.10e",defaultValue),failIfNotFound).c_str());
}

/*---------------------------------------------------------------
					read_int
 ---------------------------------------------------------------*/
int  CConfigFileBase::read_int(const std::string &section, const std::string &name, int defaultValue, bool failIfNotFound ) const
{
	return atoi( readString(section,name,format("%i",defaultValue),failIfNotFound).c_str());
}


/*---------------------------------------------------------------
					read_bool
 ---------------------------------------------------------------*/
bool  CConfigFileBase::read_bool(const std::string &section, const std::string &name, bool defaultValue, bool failIfNotFound ) const
{
	const string s = cris::lowerCase(trim(readString(section,name,string(defaultValue ? "1":"0"),failIfNotFound)));
	if (s=="true") return true;
	if (s=="false") return false;
	if (s=="yes") return true;
	if (s=="no") return false;
	return (0 != atoi(s.c_str()));
}

/*---------------------------------------------------------------
					read_string
 ---------------------------------------------------------------*/
std::string  CConfigFileBase::read_string(const std::string &section, const std::string &name, const std::string &defaultValue, bool failIfNotFound ) const
{
	return cris::trim(readString(section, name, defaultValue,failIfNotFound ));
}

/*---------------------------------------------------------------
					read_string_first_word
 ---------------------------------------------------------------*/
std::string  CConfigFileBase::read_string_first_word(const std::string &section, const std::string &name, const std::string &defaultValue, bool failIfNotFound ) const
{
	string s = readString(section, name, defaultValue,failIfNotFound );
	vector_string  auxStrs;
	cris::tokenize(s,"[], \t", auxStrs);
	if (auxStrs.empty())
	{
		if (failIfNotFound)
		{
			std::cerr << format("Value '%s' seems to be present in section '%s' but, are all whitespaces??\n",
				name.c_str(),
				section.c_str()  );
		}
		else return "";
	}
	else return auxStrs[0];
}

/** Checks if a given section exists (name is case insensitive) */
bool CConfigFileBase::sectionExists( const std::string &section_name) const
{
	vector_string sects;
	getAllSections(sects);
	for (vector_string::iterator s=sects.begin();s!=sects.end();++s)
		if (!cris::_strcmpi(section_name.c_str(), s->c_str() ))
			return true;
	return false;
}

