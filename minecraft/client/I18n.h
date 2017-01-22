#pragma once

#include "Localization.h"

class I18n {

public:

	static std::string get(const std::string&);
	static Localization getCurrentLanguage();
	static Localization getLocaleFor(const std::string&);

};