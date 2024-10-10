#include "XML_Manager.h"
#include "Common/CommonData.h"

#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

namespace XML {

	std::unique_ptr<XML_Manager> XML_Manager::_self = nullptr;

	XML_Manager* XML_Manager::Instance()
	{
		if (!_self) {
			_self = std::move(std::unique_ptr<XML_Manager>{new XML_Manager});
		}

		return _self.get();
	}

	void XML_Manager::ReadXML(std::string filename, XML_Reader*)
	{

	}

	void XML_ObjectReader::Read()
	{
		//auto objectNode = 
		Data::ObjectData objectData;

		for (const auto& objectNode : _tree->get_child("root")) {
 
			objectData._id = objectNode.second.get<std::string>("<xmlattr>.id");	
			objectData.ReadXML(objectNode);

		}

		objectData._id == "";
		
		//std::cout << objectNode << "\n";



		/*for (const auto& directory : tree.get_child("root.directory_list")) {

			auto idPath = directory.second.get<std::string>("<xmlattr>.id");

			std::cout << idPath << "\n";

			if (idPath == id) {
				auto path = directory.second.get<std::string>("<xmlattr>.path");
				return path;
			}

		}*/
	}

	bool XML_Reader::OpenFile(std::string filePath)
	{		
		_tree = std::make_shared<boost::property_tree::ptree>();
		//boost::property_tree::ptree tree;
		// Читаем XML файл в property_tree
		try {
			boost::property_tree::read_xml(filePath, *(_tree.get()));
		}
		catch (boost::property_tree::xml_parser_error& e) {
			std::cerr
				<< "[Manager::GetPathById] - Ошибка чтения XML файла: "
				<< e.what() << std::endl;
			return false;
		}

		return true;
	}

}