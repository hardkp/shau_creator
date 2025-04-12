#include "Component.h"
#include <iostream>

namespace BaseLogic::ObjectComponents {
	
	void Component::AddOption(const OptionData& optionData)
	{
		if (!_componentData) {
			std::cout << "[WARNING][Component::AddOption] - !_componentData\n";
			return;
		}

		if (optionData._id.empty()) {
			std::cout << "[WARNING][Component::AddOption] - optionData._id.empty()\n";
			return;
		}

		_componentData->_optionDataList.push_back(optionData);

	}

	void Component::DeleteOption(std::string id)
	{
		if (!_componentData) {
			std::cout << "[WARNING][Component::DeleteOption] - !_componentData\n";
			return;
		}

		if (id.empty()) {
			std::cout << "[WARNING][Component::DeleteOption] - id.empty()\n";
			return;
		}

		auto& dataList = _componentData->_optionDataList;
		auto resultIt = std::find_if(dataList.begin(), dataList.end(), [id](const OptionData& optionData) {
			return id == optionData._id;
			});

		if (resultIt != dataList.end()) {
			dataList.erase(resultIt);
		}
		
	}

	std::string Component::GetId()
	{
		if (_componentData) {
			return _componentData->_id;
		}

		return std::string{};
	}

	void Component::SetId(const std::string& id)
	{
		if (_componentData) {
			_componentData->_id = id;
		}
		std::cout << "[Component::SetId] - _componentData is not found\n";
	}

	void ComponentData::ForEachChildXML(boost::property_tree::ptree::value_type objectNodeVar, std::function<void(Child)> callback) {
		for (const auto& child : objectNodeVar.second.get_child(""))
		{
			if (child.first == "<xmlattr>") {
				continue;
			}

			callback(child);

		}
	}

}