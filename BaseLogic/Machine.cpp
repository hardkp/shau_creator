#include "Machine.h"
#include "UnitComponent.h"

namespace BaseLogic::ObjectComponents {

	void MachineData::ReadXML(boost::property_tree::ptree::value_type objectNode)
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
			else if (child.first == "unit") {
				auto type = child.second.get<std::string>("<xmlattr>.type");

				auto type_index = UnitData::GetTypeByString(type);

				if (type_index == UnitType::UNDEFINED) {
					__debugbreak();
					return;
				}

				UnitData unitData{};
				unitData._id = id;
				unitData._type = type_index;
				unitData.ReadXML(child);

				this->_unitDataList.push_back(unitData);

			}

			});

	}
}