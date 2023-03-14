#include <stdio.h>
#include <netinet/in.h>

int main() {

    uint16_t x1 = 40181;

    printf("%hu %hx\n", x1, x1) ;

    uint16_t s1 = htons(x1) ;

    printf("%hu %hx\n", s1, s1) ;

    uint16_t h1 = ntohs(s1) ;

    printf("%hu %hx\n", h1, h1) ;



    uint32_t x2 = 4120657109;

    printf("%u %x\n", x2, x2) ;

    uint32_t s2 = htonl(x2) ;

    printf("%u %x\n", s2, s2) ;

    uint32_t h2 = ntohl(s2) ;

    printf("%u %x\n", h2, h2) ;



    return 0;
}