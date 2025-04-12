#pragma once
#include <string>

namespace BaseLogic {

	class GPIO { //
	private:
		std::string _id;
		int _direction = 0b00;  // bit0 - ����, bit1 - �����
		int _typeOfIn = 0b0000; // 0 - �����, 1 - ����., 2 - 0-10�, 3 - 4-20��
		int _typeOfOut = 0b000; // 0 - ����, 1 - ����������, 2 - ������
	};

	

	struct PLCData {
		std::string _id; // �������� json � ����������� � �����������
	};

	class PLC {
	private:
	public:
		virtual ~PLC() = default;

	};

	

}