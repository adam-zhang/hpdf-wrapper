#include "Document.h"

using std::string;
using std::vector;

Document::Document(const string& fileName)
	: pdf_(0)
	  , fileName(fileName)
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

bool Document::saveToFile()
{
	status_ = HPDF_SaveToFile(pdf_, fileName_.c_str());
	return status_ == HPDF_OK;
}

vector Document::stream()
{
	vector<HPDF_BYTE> vec;
	status_ = HPDF_SaveToStream(pdf_);
	if (status_ != HPDF_OK)
		return vec;
	auto size = HPDF_GetStreamSize(pdf);
	if (size == 0)
		return vec;
	vec = vector<HPDF_BYTE>(size);
	status_ = HPDF_ReadFromStream(pdf_, &vec[0], &size);
	if (status_ != HPDF_OK)
		return vector<HPDF_BYTE>();
	return vec;
}
