#pragma once

#include <la/vec.hpp>

#include "object.hpp"

class Static : public virtual Object {
public:
	vec2 pos;  // position
	vec2 dir;  // direction
	vec2 size; // bounds
};
