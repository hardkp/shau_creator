#pragma once
#include "Component.h"
#include "BaseLogic/SHAU.h"

namespace BaseLogic::ObjectComponents { // физический адрес объекта
		
	
	struct ObjectData : ComponentData { // Object: 
		using Ptr = std::shared_ptr<ObjectData>;
		std::string _brandId = "";
		std::vector<SHAUData> _shauDataList = {};
		void ReadXML(boost::property_tree::ptree::value_type objectNode);
	};

	class Object : public Component {
	public:
		Object() {
			std::cout << "[Object][Object] - Constructor\n";
		}
		Object(const ComponentData&);
		std::string GetBrandId();
	};



}