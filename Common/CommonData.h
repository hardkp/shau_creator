#pragma once
#include <string>
#include <vector>
#include <any>
#include <boost/property_tree/ptree.hpp>

namespace Data {

	struct SHAUData;	
	struct MachineData;
	struct UnitData;

	struct OptionData {
		std::string _id;
	};

	struct ItemData {
		std::string _id;
		std::vector<OptionData> _optionDataList = {};
		void ReadXML(boost::property_tree::ptree::value_type objectNode);
	};



	struct ObjectData { // Object: 
		std::string _id;
		std::vector<OptionData> _optionDataList = {};
		std::vector<SHAUData> _shauDataList = {};
		void ReadXML(boost::property_tree::ptree::value_type objectNode);

	};


	struct SHAUData {
		std::string _id;
		std::vector<MachineData> _machineDataList;
		std::vector<OptionData> _optionDataList;
		void ReadXML(boost::property_tree::ptree::value_type objectNode);
	};

	struct MachineData {
		std::string _id;
		std::vector<UnitData> _unitDataList;
		std::vector<OptionData> _optionDataList;
		void ReadXML(boost::property_tree::ptree::value_type objectNode);
	};

	enum class UnitType {
		UNDEFINED, TEN, FAN, WATER_HEATER, AIR_VALVE,
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
		void ReadXML(boost::property_tree::ptree::value_type objectNode);
	};

}