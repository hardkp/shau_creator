#include "UnitComponent.h"
#include "ItemComponent.h"

namespace BaseLogic::ObjectComponents {

	void UnitData::ReadXML(boost::property_tree::ptree::value_type objectNode)
	{
		ForEachChildXML(objectNode, [this](Child child) {

			std::string id = "";
			try
			{
				id = child.second.get<std::string>("<xmlattr>.id");
			}
			catch (...) {}

			if (child.first == "option") {
				OptionData option{};
				option._id = id;
				this->_optionDataList.push_back(option);
			}
			else if (child.first == "item") {
				ItemData itemData{};
				itemData._id = id;
				itemData.ReadXML(child);
				this->_itemDataList.push_back(itemData);
			}

			});
	}

	UnitType UnitData::GetTypeByString(const std::string& type) { // Дописать все типы
		if (type == "fan") {
			return UnitType::FAN;
		}
		else {
			return UnitType::UNDEFINED;
		}
	}

}