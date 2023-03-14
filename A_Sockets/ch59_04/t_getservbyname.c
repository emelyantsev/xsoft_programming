#include <netdb.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    struct servent *s;
    char **pp;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s service [protocol]\n", argv[0]);

    s = getservbyname(argv[1], argv[2]);

    if (s == NULL)
        fatal("getservbyname() could not find a matching record");

    printf("Official name: %s\n", s->s_name);
    printf("Aliases:      ");
    
    for (pp = s->s_aliases; *pp != NULL; pp++)
        printf(" %s", *pp);
    
    printf("\n");
    printf("Port:          %u\n", ntohs(s->s_port) );
    printf("Protocol:      %s\n", s->s_proto );

    exit(EXIT_SUCCESS);
}