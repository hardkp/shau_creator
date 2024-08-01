#include "XML_Manager.h"

namespace XML {

	std::unique_ptr<XML_Manager> XML_Manager::_self = nullptr;

	XML_Manager* XML_Manager::Instance()
	{
		if (!_self) {
			_self = std::move(std::unique_ptr<XML_Manager>{new XML_Manager});
		}

		return _self.get();
	}

}