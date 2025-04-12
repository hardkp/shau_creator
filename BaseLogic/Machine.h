#pragma once
#include "Component.h"
#include "BaseLogic/UnitComponent.h"

namespace BaseLogic {


	namespace ObjectComponents {

		struct MachineData : ComponentData {

			std::vector<UnitData> _unitDataList;
			void ReadXML(boost::property_tree::ptree::value_type objectNode);
		};

		class Machine : public Component {
		private:

		public:
			//void AddOption();
		}; 

	}
}