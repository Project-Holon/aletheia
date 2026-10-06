/*
 * function: func_021AE454
 * address:  0x021AE454
 * packet:   pkt_ov021_021AE454
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   d_021DE138     0x021DE138  data  a4
 */
#include "../include/Obj07517.h"

extern int d_021DE138;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
struct Obj00020;
void *func_02188CB4(struct Obj00020 *p);

typedef struct { int w[6]; } S24;

void *func_021AE454(int a, int b, S24 *src, int c)
{
    char *p = (char *)func_02030734(a, 0x38, 1, (const char *)&d_021DE138, 0x1fa);

    *(S24 *)(p + 8) = *src;
    ((struct Obj07517 *)p)->f20 = 0;
    ((struct Obj07517 *)p)->f24 = c;
    ((struct Obj07517 *)p)->f30 = b;
    ((struct Obj07517 *)p)->f34 = func_02188CB4((void *)b);
    return p;
}
