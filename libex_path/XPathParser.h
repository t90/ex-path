#ifndef XPATH_PARSER
#define XPATH_PARSER

#include <expat.h>
#include <list>

#include "expat_wrapper.h"

class XPathParser{
public:
	XPathParser();
	~XPathParser();

	std::list<const char *> _expressions;
	
	xpath_result * execute(const char * buffer, int size, int isFinal);

private:
	XML_Parser p;
	
	XPathParser(const XPathParser & p){};
	XPathParser & operator= (const XPathParser & source){};
};

#endif
