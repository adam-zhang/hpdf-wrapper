#ifndef __PAGE__H
#define __PAGE__H

#include <hpdf.h>

class Page
{
public:
	Page();
	~Page();
public:
	float width();
	void setWidth(float);

};
#endif//__PAGE__H
