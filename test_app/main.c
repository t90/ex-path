#include <stdio.h>

#include <expat_wrapper.h>

int main (int argc, char *argv[])
{
 char buf[512];
     int done;
     int len;    
 void * p = create_parser();
 
 register_expression(p, "/project/target/@name");
   do {
     len = (int)fread(buf, 1, sizeof(buf), stdin);
     done = len < sizeof(buf);
     execute_parser(p, buf, len, done);
     
   } while (!done);
 
 
 free_parser(p);
 return 0;
}

