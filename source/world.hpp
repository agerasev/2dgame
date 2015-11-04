#pragma once

#include <map>

#include "graphics.hpp"
#include "physics.hpp"
#include "object/object.hpp"

class World {
private:
	std::map<Object *, ID> index;
	Physics *physics;
	Graphics *graphics;
	
public:
	World(Physics *p, Graphics *g) :
	  physics(p), graphics(g)
	{
		
	}
	virtual ~World() {
		
	}
	
	bool add(Object *obj) {
		physics->add(dynamic_cast<Static >);
		graphics->add(dynamic_cast<Drawable *>(obj));
		return index.insert(std::pair<ID, const Drawable *>(d->id, d)).second;
	}
};
