#include "CommonData.h"
#include <functional>

namespace Data
{
	using Child = const std::pair<const std::string, boost::property_tree::ptree>;

	static void ForEachChildXML(boost::property_tree::ptree::value_type objectNodeVar, std::function<void(Child)> callback) {

		for (const auto& child : objectNodeVar.second.get_child(""))
		{
			if (child.first == "<xmlattr>") {
				continue;
			}

			callback(child);

		}

	}

	static UnitType GetTypeByString(const std::string& type) { // Дописать все типы
		if (type == "fan") {
			return UnitType::FAN;
		}
		else {
			return UnitType::UNDEFINED;
		}
	}

	void ObjectData::ReadXML(boost::property_tree::ptree::value_type objectNode)
	{
		// TODO прописать сценарий парсинга объекта

		for (const auto& child : objectNode.second.get_child("")) {

			if (child.first == "<xmlattr>") {
				continue;
			}

			auto id = child.second.get<std::string>("<xmlattr>.id");

			if (child.first == "option") {
				OptionData option{};
				option._id = id;
				this->_optionDataList.push_back(option);
			}
			else if (child.first == "shau") {
				SHAUData shauData{};
				shauData._id = id;
				shauData.ReadXML(child);
				this->_shauDataList.push_back(shauData);
			}


		}

		std::vector<OptionData> _optionDataList = {};

	}

	void SHAUData::ReadXML(boost::property_tree::ptree::value_type objectNode)
	{
		for(const auto& child : objectNode.second.get_child(""))
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

				auto type_index = GetTypeByString(type);

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
