/*
 * function: func_021EE3E4
 * address:  0x021EE3E4
 * packet:   pkt_ov170_021EE3E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202616C 0x0202616C thumb
 *   func_021EC08C 0x021EC08C thumb
 */
#include "../include/Obj24035.h"

extern unsigned char *func_0202616C(void *obj, unsigned idx);
extern void func_021EC08C(char *p, int i, unsigned short a, unsigned short b, unsigned short c);

void func_021EE3E4(char **p, unsigned idx)
{
    unsigned char *c = func_0202616C(((struct Obj24035 *)(p[11]))->f70, idx);
    func_021EC08C(p[11], 4, c[0], c[1], 0);
}
