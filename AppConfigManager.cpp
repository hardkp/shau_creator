#include "AppConfigManager.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

namespace AppConfig{

	std::string Manager::GetPathById(std::string id)
	{
        // Создаем объект property_tree
        boost::property_tree::ptree tree;

        // Читаем XML файл в property_tree
        try {
            boost::property_tree::read_xml(APP_CONFIG_FILENAME, tree);
        }
        catch (boost::property_tree::xml_parser_error& e) {
            std::cerr 
                << "[Manager::GetPathById] - Ошибка чтения XML файла: " 
                << e.what() << std::endl;
            return std::string();
        }

        //auto directory_list = tree.get_child("root.directory_list");

        for (const auto& directory : tree.get_child("root.directory_list")) {
        
            auto idPath = directory.second.get<std::string>("<xmlattr>.id");
            
            std::cout << idPath << "\n";

            if (idPath == id) {
                auto path = directory.second.get<std::string>("<xmlattr>.path");
                return path;
            }

        }

        

        /*for (const auto& person : tree.get_child("root")) {
            if (person.first == "person") {
                std::string name = person.second.get<std::string>("name");
                int age = person.second.get<int>("age");
                std::string email = person.second.get<std::string>("email");

                std::cout << "Имя: " << name << ", Возраст: " << age << ", Email: " << email << std::endl;
            }
        }*/

		return std::string();
	}
    
}

/*
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <string>

int main() {
    // Создаем объект property_tree
    boost::property_tree::ptree tree;

    // Читаем XML файл в property_tree
    try {
        boost::property_tree::read_xml("example.xml", tree);
    }
    catch (boost::property_tree::xml_parser_error& e) {
        std::cerr << "Ошибка чтения XML файла: " << e.what() << std::endl;
        return 1;
    }

    // Итерируемся по каждому элементу <person>
    for (const auto& person : tree.get_child("root")) {
        if (person.first == "person") {
            std::string name = person.second.get<std::string>("name");
            int age = person.second.get<int>("age");
            std::string email = person.second.get<std::string>("email");

            std::cout << "Имя: " << name << ", Возраст: " << age << ", Email: " << email << std::endl;
        }
    }

    return 0;
}
*/