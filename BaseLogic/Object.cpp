#include "Object.h"
#include "BaseLogic/SHAU.h"

namespace BaseLogic::ObjectComponents {

	Object::Object(const ComponentData& data)
	{		
		_componentData = std::make_shared<ObjectData>(static_cast<const ObjectData&>(data));		
	}

	std::string Object::GetBrandId() // Ошибка, выбрасывается исключение
	{			
		if (!_componentData) {
			return std::string();
		}
		auto objectDataPtr = std::static_pointer_cast<ObjectData>(_componentData);
		return objectDataPtr->_brandId;		
	}

	void ObjectData::ReadXML(boost::property_tree::ptree::value_type objectNode)
	{
		// TODO прописать сценарий парсинга объекта
		_brandId = objectNode.second.get<std::string>("<xmlattr>.PLC_brand");

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

}