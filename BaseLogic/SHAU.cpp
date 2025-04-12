#include "SHAU.h"
#include "Machine.h"


namespace BaseLogic::ObjectComponents {

	void SHAUData::ReadXML(boost::property_tree::ptree::value_type objectNode)
	{
		for (const auto& child : objectNode.second.get_child(""))
		{
			if (child.first == "<xmlattr>") {
				continue;
			}

			std::string id = "";
			try
			{
				id = child.second.get<std::string>("<xmlattr>.id");
			}
			catch (...) {

			}

			if (child.first == "option") {
				OptionData option{};
				option._id = id;
				this->_optionDataList.push_back(option);
			}
			else if (child.first == "machine") {
				MachineData machineData{};
				machineData._id = id;
				machineData.ReadXML(child);
				this->_machineDataList.push_back(machineData);
			}

		}
	}
}