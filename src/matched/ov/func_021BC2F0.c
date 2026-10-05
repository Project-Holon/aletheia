/*
 * function: func_021BC2F0
 * address:  0x021BC2F0
 * packet:   pkt_021BC2F0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)

 * Virtual call through the field at +0 of the object at +0, passing the object and three of its fields plus the two arguments.
 */
#include "../include/Obj09194.h"


void func_021BC2F0(char *p, int a, int b)
{
    void (*fn)(char *, char *, int, int, int, int);

    fn = *(void (**)(char *, char *, int, int, int, int))(((struct Obj09194 *)p)->f0 + 0xc);
    if (fn != 0)
        fn(p, p + 8, ((struct Obj09194 *)p)->fC, ((struct Obj09194 *)p)->f10, a, b);
}

