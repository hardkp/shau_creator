#include <QApplication>
#include <iostream>
#include "Unit.h"
#include "XML/XML_Manager.h"

#include "AppConfigManager.h"


int main(int argc, char** argv) {

	setlocale(LC_ALL, "rus");

	QApplication app{ argc, argv };

	// TODO сериализация XML структуры объекта



	/*Data::Parameter p(Data::ParameterType::VOLTAGE, 12.0f);
	std::cout << p.GetValue<float>();*/

	/*Data::Unit::Manager::Instance()->MakeObject("qwerty");
	Data::Unit::Manager::Instance()->MakeObject("qwerty");*/

	AppConfig::Manager xml_parse;
	auto path = xml_parse.GetPathById("test_object_path");

	std::cout << path << "\n";
	auto reader = new XML::XML_ObjectReader;

	if (reader->OpenFile(path)) {
		reader->Read();
	}
	
	return app.exec();
}