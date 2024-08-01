#include "Unit.h"
#include <iostream>

namespace Data {
	namespace Unit
	{
		std::unique_ptr<Manager> Manager::_self = nullptr;

		Manager* Manager::Instance()
		{
			if (!_self) {
				_self = std::move(std::unique_ptr<Manager>{new Manager});				
			}

			return _self.get();
		}

		void Manager::MakeObject(std::string id)
		{
			const auto& objectList = _dataBase._objectIdsList;		
			auto result = std::find_if(objectList.begin(), objectList.end(), [id](const std::string& objectId) {
				return id == objectId;
				});

			/*if (result == objectList.end()) {
				objectList.push_back(id);
				return;
			}*/

			std::cout << "[Data::Unit::Manager::MakeObject] - id: " << id << " is already exis\n";

		}

		void Manager::MakeSHAU(std::string id)
		{

		}

	}
}