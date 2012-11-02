#ifndef EXPAT_WRAPPER
#define EXPAT_WRAPPER

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
	char * expression;
	char * result;
} xpath_result;

void * create_parser();
void free_parser(void * parser);
void register_expression(void * parser, const char * expression);
xpath_result * execute_parser(void * parser, char * buffer, int size, int is_final);

#ifdef __cplusplus
}
#endif

#endif
