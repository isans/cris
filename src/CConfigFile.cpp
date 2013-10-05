
#include "CConfigFile.h"
#include "SimpleIni.h"
#include <iostream>

using namespace cris;
using namespace std;

CConfigFile::CConfigFile( const std::string &fileName )
{
	m_file = fileName;
	m_modified = false;
    m_ini = (void*) new CSimpleIniA();
    static_cast<CSimpleIniA*>(m_ini.get())->LoadFile(fileName.c_str());
}

CConfigFile::CConfigFile()
{
	m_file = "";
	m_modified = false;
    m_ini = (void*) new CSimpleIniA();
}

void CConfigFile::setFileName(const std::string &fil_path)
{
	m_file = fil_path;
	m_modified = false;

    static_cast<CSimpleIniA*>(m_ini.get())->LoadFile(fil_path.c_str());
}

void CConfigFile::writeNow()
{
	if (m_modified && !m_file.empty())
	{
	    static_cast<CSimpleIniA*>(m_ini.get())->SaveFile( m_file.c_str() );
	    m_modified = false;
	}
}

CConfigFile::~CConfigFile()
{
    writeNow();
    delete static_cast<CSimpleIniA*>(m_ini.get());
}

void  CConfigFile::writeString(const std::string &section,const std::string &name, const std::string &str)
{
	m_modified = true;

    if (0 > static_cast<CSimpleIniA*>(m_ini.get())->SetValue( section.c_str(),name.c_str(),str.c_str(), NULL ))
        std::cerr << "Error changing value in INI-style file!\n";

}

std::string  CConfigFile::readString(
    const std::string &section,
    const std::string &name,
    const std::string &defaultStr,
    bool failIfNotFound ) const
{
    const char *defVal = failIfNotFound ? NULL :defaultStr.c_str();

    const char *aux = static_cast<const CSimpleIniA*>(m_ini.get())->GetValue(
        section.c_str(),
        name.c_str(),
        defVal,
        NULL );     // The memory is managed by the SimpleIni object

    if (failIfNotFound && !aux )
    {
        string tmpStr( format("Value '%s' not found in section '%s' of file '%s' and failIfNotFound=true.",
			name.c_str(),
			section.c_str(),
			m_file.c_str() ) );
        std::cerr << tmpStr << std::endl;
    }

	// Remove possible comments: "//"
	std::string ret = aux;
	size_t  pos;
	if ((pos=ret.find("//"))!=string::npos && pos>0 && isspace(ret[pos-1]))
		ret = ret.substr(0,pos);
	return ret;
}

void CConfigFile::getAllSections( vector_string	&sections ) const
{
	CSimpleIniA::TNamesDepend	names;
	static_cast<const CSimpleIniA*>(m_ini.get())->GetAllSections(names);

	CSimpleIniA::TNamesDepend::iterator		n;
	vector_string::iterator		s;
	sections.resize(names.size());
	for (n=names.begin(),s=sections.begin(); n!=names.end();n++,s++)
		*s = n->pItem;
}

void CConfigFile::getAllKeys( const string section, vector_string	&keys ) const
{
	CSimpleIniA::TNamesDepend	names;
	static_cast<const CSimpleIniA*>(m_ini.get())->GetAllKeys(section.c_str(), names);

	CSimpleIniA::TNamesDepend::iterator		n;
	vector_string::iterator		s;
	keys.resize(names.size());
	for ( n = names.begin(), s = keys.begin(); n!=names.end();n++,s++)
		*s = n->pItem;
}
