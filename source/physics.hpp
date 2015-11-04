#pragma once

#include <map>

#include "object/static.hpp"
#include "object/dynamic.hpp"

class Physics {
private:
	std::map<ID, Static *> static_index;
	std::map<ID, Dynamic *> dynamic_index;
	
public:
	bool add(Static *obj) {
		Dynamic *dobj = dynamic_cast<Dynamic *>(obj);
		if(dobj != nullptr) {
			return dynamic_index.insert(std::pair<ID, const Drawable *>(dobj->id, dobj)).second;
		}
		return static_index.insert(std::pair<ID, const Drawable *>(obj->id, obj)).second;
	}
	
	bool remove(ID id) {
		auto i = dynamic_index.find(id);
		if(i == static_index.end()) {
			auto si = static_index.find(id);
			if(si == dynamic_index.end())
			return false;
		}
		index.erase(i);
		return true;
	}
};
