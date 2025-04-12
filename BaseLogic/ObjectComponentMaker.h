#pragma once

#include "BaseLogic/Component.h"

namespace BaseLogic {

	namespace ObjectComponents {
		class Component;
	}

	class ObjectComponentMaker {
	public:
		static ObjectComponents::Component* MakeComponent(const ObjectComponents::ComponentData& componentData);
	};

}