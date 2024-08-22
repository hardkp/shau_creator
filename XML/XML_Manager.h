#pragma once
#include <memory>
#include <string>

namespace XML {

	class XML_Reader {
	public:
		virtual ~XML_Reader() = default;
		virtual void Read() {}
	};

	class XML_ObjectReader : public XML_Reader {
	public:
		void Read() override;
	};

	class XML_Manager { // синглтон

	private:
		static std::unique_ptr<XML_Manager> _self;

	public:
		static XML_Manager* Instance();
		void ReadXML(std::string filename, XML_Reader*);

	};

}