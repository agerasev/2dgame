#pragma once

#include <vec.hpp>

#include "static.hpp"

class Dynamic : public virtual Static {
public:
	vec2   vel;    // velocity
	double spin;   // rotation speed
	double iinert; // inverted inertia momentum
	double imass;  // inverted mass
};
