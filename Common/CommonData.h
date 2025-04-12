#pragma once
#include <string>
#include <vector>
#include <any>
#include <boost/property_tree/ptree.hpp>

namespace Data {

	struct SHAUData;	
	struct MachineData;
	struct UnitData;

	



	





	


	

	

	

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



}