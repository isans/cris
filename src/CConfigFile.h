
#pragma once

#include "CConfigFileBase.h"
#	define ASSERTMSG_(f,__ERROR_MSG) \
	{ \
	if (!(f)) std::cerr << ::std::string( __ERROR_MSG ) << std::endl; \
	}
#	define ASSERT_(f) \
	ASSERTMSG_(f, std::string("Assert condition failed: ") + ::std::string(#f) )
namespace cris
{
	template <class T>
	struct non_copiable_ptr_basic
	{
	protected:
		T *ptr;

	public:
		non_copiable_ptr_basic() : ptr(NULL) { }
		non_copiable_ptr_basic(const non_copiable_ptr_basic<T> &o) : ptr(NULL) { throw std::logic_error("Pointer non-copiable..."); }
		non_copiable_ptr_basic(const T* p) : ptr(const_cast<T*>(p)) { }
		non_copiable_ptr_basic<T> &operator =(T * p) { ptr = p; return *this; }

		non_copiable_ptr_basic<T> &operator =(const non_copiable_ptr_basic<T>&o)
		{ throw std::logic_error("Pointer non-copiable..."); }

		/** This method can change the pointer, since the change is made explicitly, not through copy operators transparent to the user. */
		void set( const T* p ) { ptr = const_cast<T*>(p); }

		virtual ~non_copiable_ptr_basic() {  }

		bool operator == ( const T *o ) const { return o==ptr; }
		bool operator == ( const non_copiable_ptr_basic<T> &o )const { return o.ptr==ptr; }

		bool operator != ( const T *o )const { return o!=ptr; }
		bool operator != ( const non_copiable_ptr_basic<T> &o )const { return o.ptr!=ptr; }

		T*& get() { return ptr; }
		const T* get()const { return ptr; }

		T** getPtrToPtr() { return &ptr; }

		T *& operator ->() { ASSERT_(ptr); return ptr; }
		const T * operator ->() const  { ASSERT_(ptr); return ptr; }
	};
	template <class T>
	struct non_copiable_ptr : non_copiable_ptr_basic<T>
	{
	public:
		non_copiable_ptr() : non_copiable_ptr_basic<T>() { }
		non_copiable_ptr(const non_copiable_ptr<T> &o) : non_copiable_ptr_basic<T>(o) { }
		non_copiable_ptr(const T* p) : non_copiable_ptr_basic<T>(p) { }

		non_copiable_ptr<T> &operator =(const T* p) { non_copiable_ptr_basic<T>::ptr = const_cast<T*>(p); return *this; }

		non_copiable_ptr<T> &operator =(const non_copiable_ptr<T>&o)
		{ throw std::logic_error("Pointer non-copiable..."); }

		virtual ~non_copiable_ptr() {  }

		T & operator *() { ASSERT_(non_copiable_ptr_basic<T>::ptr); return *non_copiable_ptr_basic<T>::ptr; }
		const T & operator *() const  { ASSERT_(non_copiable_ptr_basic<T>::ptr); return *non_copiable_ptr_basic<T>::ptr; }

		T & operator [](const size_t &i) { ASSERT_(non_copiable_ptr_basic<T>::ptr); return non_copiable_ptr_basic<T>::ptr[i]; }
		const T & operator [](const size_t &i) const { ASSERT_(non_copiable_ptr_basic<T>::ptr); return non_copiable_ptr_basic<T>::ptr[i]; }
	};

	typedef non_copiable_ptr_basic<void> void_ptr_noncopy;
		
	class CRIS_IMPEXP CConfigFile : public CConfigFileBase
	{
	private:
		/** The name of the file
		  */
		std::string		m_file;

		/** The interface to the file:
		  */
		void_ptr_noncopy m_ini;

		/** If modified since load.
		  */
		bool			m_modified;

	protected:
		/** A virtual method to write a generic string.
		  */
		void  writeString(const std::string &section,const std::string &name, const std::string &str);

		/** A virtual method to read a generic string.
         * \exception std::exception If the key name is not found and "failIfNotFound" is true. Otherwise the "defaultValue" is returned.
		 */
		std::string  readString(
            const std::string &section,
            const std::string &name,
            const std::string &defaultStr,
            bool failIfNotFound = false) const;

	public:
		/** Constructor that opens a configuration file. */
		CConfigFile( const std::string &fileName );

		/** Constructor, does not open any file. You should call "setFileName" before reading or writting or otherwise nothing will be read and write operations will be eventually lost.
		  * However, it's perfectly right to use this object without an associated file, in which case it will behave as an "in-memory" file.
		  */
		CConfigFile();

        /** Associate this object with the given file, so future read/write operations will be applied to that file (it's synchronized at destruction).
          */
		void setFileName(const std::string &fil_path);

        /** Dumps the changes to the physical configuration file now, not waiting until destruction. */
		void writeNow();

        /** Returns the file currently open by this object.
          */
		std::string getAssociatedFile() const { return m_file; }

		/** Destructor
		  */
        virtual ~CConfigFile();

		/** Returns a list with all the section names.
		  */
		virtual void getAllSections( vector_string	&sections ) const;

		/** Returs a list with all the keys into a section.
		  */
		virtual void getAllKeys( const std::string section, vector_string	&keys ) const;
	}; 
} 