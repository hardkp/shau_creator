#pragma once
#include "Component.h"
#include "BaseLogic/ItemComponent.h"

namespace BaseLogic::ObjectComponents {
	
	enum class UnitType {
		UNDEFINED, TEN, FAN, WATER_HEATER, AIR_VALVE,
	};

	struct UnitData : ComponentData {
		UnitType _type = UnitType::UNDEFINED;
		std::vector<ItemData> _itemDataList;
		void ReadXML(boost::property_tree::ptree::value_type objectNode);
		static UnitType GetTypeByString(const std::string& type);
	};

	class UnitComponent : public Component
	{

	};

}