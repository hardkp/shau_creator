#pragma once
#include <vector>
#include <any>
#include <memory>
#include <string>
#include <tuple>

namespace Data{
	namespace Unit
	{
		enum class ParameterType {
			VOLTAGE,
		};

		struct UnitParameter {
			ParameterType _parameterType;
			std::any _value;

			template<typename T> UnitParameter(ParameterType type, T value) : _parameterType{ type } {
				_value = value;
			}

			template<typename T> T GetValue() {
				return std::any_cast<T>(_value);
			}

		};

		enum class UnitType {
			TEN, FAN, WaterHeater, AirValve,
		};

		struct UnitData {
			std::string _idObject = ""; // Объект как здание
			std::string _idSHAU = "";
			std::string _idMachine = "";
			std::string _idUnit = "";
			UnitType _type;
			std::vector<UnitParameter> _parameters;
		};

		struct DataBase {		
			//using Id = std::string;
			std::vector<std::string> _objectIdsList{};
			/*std::vector<std::tuple<Id, Id>> _SHAUIdsList;
			std::vector<std::tuple<Id, Id, Id>> _MachineList;
			std::vector<UnitData> _unitDataList;*/
		};	

		class Manager{ //синглтон
		public:
			static Manager* Instance();
			void MakeObject(std::string id);
			void MakeSHAU(std::string id);
			void MakeMachine();
			void MakeUnit();

		private:
			Manager() = default;
			static std::unique_ptr<Manager> _self;

			DataBase _dataBase = {};
		};

	}	
}