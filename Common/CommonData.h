#pragma once
#include <string>
#include <vector>

namespace Data {

	struct SHAUData;
	struct OptionData;
	struct MachineData;
	struct UnitData;
	struct ItemData;


	struct ObjectData { // Object: 
		std::string _id;
		std::vector<SHAUData> _shauDataList;
		std::vector<OptionData> _optionDataList;
	};


	struct SHAUData {
		std::string _id;
		std::vector<MachineData> _machineDataList;
		std::vector<OptionData> _optionDataList;
	};

	struct MachineData {
		std::string _id;
		std::vector<UnitData> _unitDataList;
		std::vector<OptionData> _optionDataList;
	};

	enum class UnitType {
		TEN, FAN, WaterHeater, AirValve,
	};

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

	struct UnitData {
		std::string _id;
		UnitType _type;
		std::vector<UnitParameter> _parameters;
		std::vector<ItemData> _itemDataList;
		std::vector<OptionData> _optionDataList;
	};

}