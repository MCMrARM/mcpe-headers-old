#pragma once

#include <string>

class Localization {

public:

	void _appendTranslations(const std::string&);
	void _load(const std::string&);
	std::string getFullLanguageCode() const;

};