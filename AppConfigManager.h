#pragma once
#include <string>



namespace AppConfig {
	// рабочий путь
	//const std::string APP_CONFIG_FILENAME = "D:\\source\\repos\\shau_creator_2\\src\\AppConfig\\AppConfig.xml";

	const std::string APP_CONFIG_FILENAME = "..\\..\\src\\AppConfig\\AppConfig.xml";



	class Manager {
	private:
	public:
		std::string GetPathById(std::string id);
	};

}