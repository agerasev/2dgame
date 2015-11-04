#pragma once

#include "static.hpp"

#include "../drawcontext.hpp"

class Drawable : public virtual Static {
public:
	virtual void draw(const DrawContext *ctx) const = 0;
};
