#pragma once

#include <map>

#include "drawcontext.hpp"
#include "object/drawable.hpp"

#include <graphics/graphics.h>

class Graphics {
private:
	std::map<ID, const Drawable *> index;
	
public:
	bool add(const Drawable *d) {
		return index.insert(std::pair<ID, const Drawable *>(d->id, d)).second;
	}
	
	bool remove(ID id) {
		auto i = index.find(id);
		if(i == index.end())
			return false;
		index.erase(i);
		return true;
	}
	
	void draw() {
		for(std::pair<ID, const Drawable *> p : index) {
			p.second->draw(nullptr);
		}
	}
};
