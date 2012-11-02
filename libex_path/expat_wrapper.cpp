
#include <stdio.h>
#include <expat.h>

#include "expat_wrapper.h"
#include "XPathParser.h"

void * create_parser(){
	return new XPathParser();
}
void free_parser(void * parser){
	delete (XPathParser *)parser;
}
void register_expression(void * parser, const char * expression){
	((XPathParser *)parser)->_expressions.push_back(expression);
}

xpath_result * execute_parser(void * parser, char * buffer, int size, int is_final){
	return ((XPathParser *)parser)->execute(buffer, size, is_final);
}

static void XMLCALL startElement(void *xpathParser, const char *name, const char **atts)
{
	printf("start %s\n", name);
}

static void XMLCALL endElement(void *xpathParser, const char *name)
{
	printf("end %s\n", name);
}


XPathParser::XPathParser(){
	p = XML_ParserCreate(NULL);
	XML_SetUserData(p, this);
	XML_SetElementHandler(p, startElement, endElement);
	printf("constructor\n");
}

XPathParser::~XPathParser(){
	XML_ParserFree(p);
	printf("de-structor\n");
}

xpath_result * XPathParser::execute(const char * buffer, int size, int isFinal){
    if (XML_Parse(this->p, buffer, size, isFinal) == XML_STATUS_ERROR) {
      fprintf(stderr,
              "%s at line %du\n",
              XML_ErrorString(XML_GetErrorCode(this->p)),
              XML_GetCurrentLineNumber(this->p));
      return NULL;
    }
	return NULL;
}