#include "ItemComponent.h"

namespace BaseLogic::ObjectComponents {

	void ItemData::ReadXML(boost::property_tree::ptree::value_type objectNode)
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

			});
	}

}