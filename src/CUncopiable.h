
#pragma once
#include "link.h"

namespace cris
{	
	class CRIS_IMPEXP CUncopiable
	{
	private:
		CUncopiable(const CUncopiable &);  // This doesn't need to be implemented anywhere
		const CUncopiable& operator =(const CUncopiable &);   // This doesn't need to be implemented anywhere
	public:
		CUncopiable() {  }
	}; // End of class def.

} // end of namespace

