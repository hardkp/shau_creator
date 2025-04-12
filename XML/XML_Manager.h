#pragma once
#include <memory>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include "Common/CommonData.h"
#include "BaseLogic/Object.h"

namespace XML {
	
	class XML_Reader {
	public:
		using XMLTreePtr = std::shared_ptr<boost::property_tree::ptree>;

	protected:
		XMLTreePtr _tree = nullptr;

	public:
		virtual ~XML_Reader() = default;
		virtual bool OpenFile(std::string filePath);
		virtual bool Read() { return false; }
	};

	class XML_ObjectReader : public XML_Reader {
	private:
		BaseLogic::ObjectComponents::ObjectData _objectData;
	public:
		bool Read() override;
		BaseLogic::ObjectComponents::ObjectData GetObjectData();
	};

	class XML_Manager { // синглтон

	private:
		static std::unique_ptr<XML_Manager> _self;

	public:
		static XML_Manager* Instance();
		void ReadXML(std::string filename, XML_Reader*);

	};

}