#include "ObjectComponentManager.h"
#include "XML/XML_Manager.h"
#include "ObjectComponentMaker.h"
#include "BaseLogic/Object.h"

#include <iostream>

namespace BaseLogic{
	bool ObjectComponentManager::LoadObject(const std::string& path)
	{
		auto reader = std::make_shared<XML::XML_ObjectReader>();

		if (reader->OpenFile(path) && reader->Read()) {	

			if (auto objectPtr = ObjectComponentMaker::MakeComponent(reader->GetObjectData())){
				_objectComponentList.push_back(objectPtr);
				return true;
			}
		}
		return false;
	}

	void ObjectComponentManager::CalculateObject()
	{
		CalculatePLC();
	}

	ObjectComponentManager::~ObjectComponentManager()
	{
		if (_objectComponentList.empty()) {
			return;
		}

		for (auto objectComponent : _objectComponentList) {
			if (objectComponent) {
				delete objectComponent;
			}
		}

	}

	void ObjectComponentManager::CalculatePLC()
	{
		if (_objectComponentList.empty()) {
			std::cout << "[ObjectComponentManager::CalculatePLC] - _objectComponentList.empty";
			return;
		}

		auto objectPtr = static_cast<BaseLogic::ObjectComponents::Object*>(_objectComponentList[0]);
		auto brandId = objectPtr->GetBrandId();
		std::cout << "Brandid: " << brandId << "\n";
	}

}


