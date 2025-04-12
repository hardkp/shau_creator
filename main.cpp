#include <QApplication>
#include <iostream>

#include "AppConfigManager.h"
#include "BaseLogic/ObjectComponentManager.h"


int main(int argc, char** argv) {

	setlocale(LC_ALL, "rus");

	QApplication app{ argc, argv };

	// TODO сериализация XML структуры объекта

	AppConfig::Manager xml_parse;
	auto path = xml_parse.GetPathById("test_object_path");

	BaseLogic::ObjectComponentManager componentMngr{};

	if (!path.empty() && componentMngr.LoadObject(path)) {
		componentMngr.CalculateObject();
	}

	
	return app.exec();

}