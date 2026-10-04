/*
 * unit:     no
 * function: func_0203A424
 * address:  0x0203A424
 * packet:   pkt_02039CD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj06942.h"

extern int func_020395EC(void *p);
void func_0203A424(char *p, int a, int b, int c)
{
    if (p == 0)
        return;
    ((struct Obj06942 *)p)->f46 = (unsigned short)(a + (b << 8));
    p[0x48] = (char)c;
    if (func_020395EC(p) == 0xff)
        p[0x49] = 0;
    else
        p[0x49] = 1;
}
