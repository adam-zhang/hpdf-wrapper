#ifndef __DOCUMENT__H
#define __DOCUMENT__H

#include <hpdf.h>

class Document
{
public:
	Document();
	~Document();
private:
	HPDF_Doc pdf_;
public:

};
#endif//__DOCUMENT__H
