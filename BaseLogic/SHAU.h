#pragma once
//#include "Common/CommonData.h"
#include "Component.h"
#include "BaseLogic/Machine.h"

namespace BaseLogic {

	namespace ObjectComponents {
		
		//class Machine;
		class Unit;
		//struct MachineData;

		struct SHAUData : ComponentData {

			std::vector<MachineData> _machineDataList;
			/*SHAUData() {
				������� ���������� �� ����������
				std::vector<MachineData> vec{};
				vec.reserve(1);
			}*/
			void ReadXML(boost::property_tree::ptree::value_type objectNode);
		};

		class SHAU : public Component {
		private:
			//SHAUData _data{};

			// �������� ����������� ��������� Machine � Machine



		public:
			//void AddMachine(Machine*);
			//void DeleteMachine(const std::string& id);
			//void GetMachineByID();
			//void AddUnit(Unit*); // ��������� ������������� ���� ��������� ����

		};

		///-----------------------------------------------------------
		/*class Unit {
		private:
			Data::UnitData _data{};

		public:


		};*/

	}
	
}