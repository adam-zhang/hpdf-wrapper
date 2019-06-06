#include "Document.h"

Document::Document()
	: pdf_(0)
{
	pdf = HPDF_New(error_handler, NULL);
	if (setjmp(env))
	{
		HPDF_Free(pdf_);
		pdf_ = 0;
	}
}

Document::~Document()
{
	if (pdf_ != 0)
		HPDF_Free(pdf_);
}
