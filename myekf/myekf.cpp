#include "myekf.h"

#include <mathlib/mathlib.h>

bool Myekf::init(uint64_t timestamp)
{
	if (!_initialised) {
		_initialised = initialise_interface(timestamp);
		reset();
	}

	return _initialised;
}

void Myekf::reset() 
{
	ECL_INFO("reset");
}
