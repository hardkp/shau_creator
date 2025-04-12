#pragma once
#include <string>

namespace BaseLogic {

	class GPIO { //
	private:
		std::string _id;
		int _direction = 0b00;  // bit0 - вход, bit1 - выход
		int _typeOfIn = 0b0000; // 0 - цифра, 1 - темп., 2 - 0-10В, 3 - 4-20мА
		int _typeOfOut = 0b000; // 0 - реле, 1 - транзистор, 2 - аналог
	};

	

	struct PLCData {
		std::string _id; // добавить json с информацией о контроллере
	};

	class PLC {
	private:
	public:
		virtual ~PLC() = default;

	};

	

}