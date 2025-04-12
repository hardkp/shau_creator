#include "ObjectComponentMaker.h"
#include "Component.h"
#include "Common/CommonData.h"
#include "Object.h"

namespace BaseLogic
{
	ObjectComponents::Component* ObjectComponentMaker::MakeComponent(const ObjectComponents::ComponentData& componentData)
	{
		switch (componentData._componentType) {
		case ObjectComponents::ComponentType::OBJECT:
		{
			auto objectComponent = new BaseLogic::ObjectComponents::Object{ componentData };
			return objectComponent;
			break;
		}
		case ObjectComponents::ComponentType::UNKNOWN:
			break;
		}

		return nullptr;
	}
}
