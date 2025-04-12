#pragma once
#include <string>
#include <vector>

#include "Component.h"

namespace BaseLogic {
	class ObjectComponentManager {
	public:
		using ObjectComponentList = std::vector<ObjectComponents::Component*>;
		bool LoadObject(const std::string& path);
		void CalculateObject();

	public:
		ObjectComponentManager() = default;
		~ObjectComponentManager();

	private:
		void CalculatePLC();

	private:
		ObjectComponentList _objectComponentList;

	};

}