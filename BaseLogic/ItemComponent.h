#pragma once
#include  "Component.h"

namespace BaseLogic::ObjectComponents{

	struct ItemData : ComponentData {
		
		void ReadXML(boost::property_tree::ptree::value_type objectNode);
	};

	class ItemComponent : public Component
	{


	};

}



