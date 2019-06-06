#ifndef __DOCUMENT__H
#define __DOCUMENT__H

#include <hpdf.h>
#include <string>
#include <vector>

class Document
{
public:
	Document(const std::string& fileName);
	~Document();
private:
	HPDF_Doc pdf_;
	std::string fileName_;
	HPDF_STATUS status_;
public:
	HPDF_STATUS status()
	{ return status_;}
	bool saveToFile();
	std::vector<HPDF_BYTE> stream();
};
#endif//__DOCUMENT__H
