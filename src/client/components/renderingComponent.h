#pragma once
#include "core/component.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

COMPONENT(RenderingComponent) {
    RenderingComponent(Entity owner, ComponentHandle handle) :
            Component(owner, handle) {}

	void init(ArgsMap args) {
		plane = boost::lexical_cast<int>(args["plane"]);
	}

    int plane = 0; //renderer draws first graphics components which have highest plane - so plane INT_MIN will be always drawn last, so nothing will overlap it. 
    std::vector<sf::Drawable*> drawablesList; //Drawables from this list will be drawn in undefined order.
};
