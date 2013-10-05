
#pragma once

#include <string>
#include <vector>
#include <deque>
#include "link.h"

typedef std::vector<std::string> vector_string;	//!<  A type for passing a vector of strings.

namespace cris
{
	std::string format(const char *fmt, ...);
	std::string lowerCase(const std::string& str);
	std::string trim(const std::string &str);		
	void tokenize(
		const std::string			&inString,
		const std::string			&inDelimiters,
		std::vector<std::string>		&outTokens );
	char *strtok( char *str, const char *strDelimit, char **context );	
	int _strcmpi(const char*str1,const char*str2);
	int vsnprintf(char *buf, size_t bufSize, const char *format, va_list args);

	class CRIS_IMPEXP CConfigFileBase
	{
	protected:
		/** A virtual method to write a generic string.
		  */
		virtual void  writeString(const std::string &section,const std::string &name, const std::string &str) = 0;

		/** Write a generic string with optional padding and a comment field ("// ...") at the end of the line. */
		void  writeString(const std::string &section,const std::string &name, const std::string &str, const int name_padding_width, const int value_padding_width, const std::string &comment);

		/** A virtual method to read a generic string.
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		virtual std::string  readString(
            const std::string &section,
            const std::string &name,
            const std::string &defaultStr,
            bool failIfNotFound = false) const = 0;

	public:
        /** Virtual destructor...
         */
         virtual ~CConfigFileBase()
         {
         }

		/** Returns a list with all the section names.
		  */
		virtual void getAllSections( vector_string	&sections ) const = 0 ;

		/** Returns a list with all the keys into a section.
		  */
		virtual void getAllKeys( const std::string section, vector_string	&keys ) const = 0;

		/** Checks if a given section exists (name is case insensitive) */
		bool sectionExists( const std::string &section_name) const;

		/** @name Save a configuration parameter. Optionally pads with spaces up to the desired width in number of characters (-1: no fill), and add a final comment field at the end of the line (a "// " prefix is automatically inserted).
		  * @{ */
		void  write(const std::string &section, const std::string &name, double value, const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		void  write(const std::string &section, const std::string &name, float value , const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		void  write(const std::string &section, const std::string &name, int value   , const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		void  write(const std::string &section, const std::string &name, const std::string &value        , const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		void  write(const std::string &section, const std::string &name, const std::vector<int> &value   , const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		void  write(const std::string &section, const std::string &name, const std::vector<unsigned int> &value, const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		void  write(const std::string &section, const std::string &name, const std::vector<float> &value , const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		void  write(const std::string &section, const std::string &name, const std::vector<double> &value, const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		void  write(const std::string &section, const std::string &name, const std::vector<bool> &value  , const int name_padding_width=-1, const int value_padding_width=-1, const std::string &comment = std::string() );
		/** @} */

		/** Reads a configuration parameter of type "double"
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		double  read_double(const std::string &section, const std::string &name, double defaultValue, bool failIfNotFound = false) const;

		/** Reads a configuration parameter of type "float"
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		float  read_float(const std::string &section, const std::string &name, float defaultValue, bool failIfNotFound = false) const;

		/** Reads a configuration parameter of type "bool", codified as "1"/"0" or "true"/"false" or "yes"/"no" for true/false, repectively.
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		bool  read_bool(const std::string &section, const std::string &name, bool defaultValue, bool failIfNotFound = false) const;

		/** Reads a configuration parameter of type "int"
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		int  read_int(const std::string &section, const std::string &name, int defaultValue, bool failIfNotFound = false) const;
				
		/** Reads a configuration parameter of type "string"
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		std::string  read_string(const std::string &section, const std::string &name, const std::string &defaultValue, bool failIfNotFound = false) const;

		/** Reads a configuration parameter of type "string", and keeps only the first word (this can be used to eliminate possible comments at the end of the line)
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		std::string  read_string_first_word(const std::string &section, const std::string &name, const std::string &defaultValue, bool failIfNotFound = false) const;

		/** Reads a configuration parameter of type vector, stored in the file as a string: "[v1 v2 v3 ... ]", where spaces could also be commas.
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		template <class VECTOR_TYPE>
		void  read_vector(
			const std::string  & section,
			const std::string  & name,
			const VECTOR_TYPE  & defaultValue,
			VECTOR_TYPE        & outValues,
			bool                 failIfNotFound = false) const
		{
			std::string aux ( readString(section, name, "",failIfNotFound ) );
			// Parse the text into a vector:
			std::vector<std::string>	tokens;
			cris::tokenize( aux,"[], \t",tokens);

			if (tokens.size()==0)
			{
				outValues = defaultValue;
			}
			else
			{
				// Parse to numeric type:
				const size_t N = tokens.size();
				outValues.resize( N );
				for (size_t i=0;i<N;i++)
				{
					std::stringstream ss(tokens[i]);
					ss >> outValues[i];
				}
			}
		}


		/** Reads a configuration parameter as a matrix written in a matlab-like format - for example: "[2 3 4 ; 7 8 9]"
		 *  This template method can be instantiated for matrices of the types: int, long, unsinged int, unsigned long, float, double, long double
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		 template <class MATRIX_TYPE>
		 void read_matrix(
			const std::string			&section,
			const std::string			&name,
			MATRIX_TYPE	&outMatrix,
			const MATRIX_TYPE &defaultMatrix = MATRIX_TYPE(),
			bool failIfNotFound = false ) const
		{
			std::string aux = readString(section, name, "",failIfNotFound );
			if (aux.empty())
				outMatrix = defaultMatrix;
			else
			{
				// Parse the text into a vector:
				if (!outMatrix.fromMatlabStringFormat(aux))
					std::cerr << "Error parsing matrix: '%s'",aux.c_str();
			}
		}

	};  // class
}	// namespace

