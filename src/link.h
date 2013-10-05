
#ifndef link_H
#define link_H

#if defined(WIN32)   
#    if defined(_MSC_VER) || defined(__BORLANDC__) || defined(__GNUC__) || defined(__WATCOMC__)
#        define CRIS_BASE_EXPORT __declspec(dllexport)
#        define CRIS_BASE_IMPORT __declspec(dllimport)
#    else /* compiler doesn't support __declspec() */
#        define CRIS_BASE_EXPORT
#        define CRIS_BASE_IMPORT
#    endif
#elif defined(__CYGWIN__)
#    define CRIS_BASE_EXPORT __declspec(dllexport)
#    define CRIS_BASE_IMPORT __declspec(dllimport)
#endif

/* for other platforms/compilers we don't anything */
#ifndef CRIS_BASE_EXPORT
#    define CRIS_BASE_EXPORT
#    define CRIS_BASE_IMPORT
#endif

/*  Macros that map to export declaration when building the DLL, to import
	declaration if using it or to nothing at all if we are not compiling as DLL */
#if defined(CRIS_BUILT_AS_DLL)
#	define CRIS_IMPEXP CRIS_BASE_EXPORT
#else /* not making nor using DLL */
#    define CRIS_IMPEXP CRIS_BASE_IMPORT
#endif

// Finally this one allows exporting a class that inherits from a
// template in MS DLLs with both MSVC and GCC. To see how nasty is
// this, Google "class derived from template DLL export" and suffer...
#if defined(_MSC_VER)
#   define BASE_IMPEXP_TEMPL
#else
    // Mostly for Mingw:
#   define BASE_IMPEXP_TEMPL CRIS_IMPEXP
#endif


#endif
