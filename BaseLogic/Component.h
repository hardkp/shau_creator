#pragma once
#include "Common/CommonData.h"
#include <memory>
#include <iostream>

namespace BaseLogic {

	namespace ObjectComponents {



		struct OptionData {
			std::string _id;
		};

		enum class ComponentType {
			UNKNOWN, OBJECT,
		};

		struct ComponentData {
			using Ptr = std::shared_ptr<ComponentData>;
			virtual ~ComponentData() = default;
			ComponentData() = default;
			ComponentData(const ComponentData&) = default;
			std::string _id;
			std::vector<OptionData> _optionDataList = {};
			ComponentType _componentType = ComponentType::UNKNOWN;
			using Child = const std::pair<const std::string, boost::property_tree::ptree>;
			static void ForEachChildXML(boost::property_tree::ptree::value_type objectNodeVar, std::function<void(Child)> callback);
		};

		class Component {		

		protected:
			std::shared_ptr<ComponentData> _componentData = nullptr;

		public:
			virtual ~Component() = default;
			Component() {
				
			}

			virtual void AddOption(const OptionData&); 
			virtual void DeleteOption(std::string id);
			//virtual void EditOption(std::string id, const Data::OptionData&);
			virtual std::string GetId();
			virtual void SetId(const std::string& id);
		};
	}

}