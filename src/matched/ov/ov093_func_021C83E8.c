/*
 * function: func_021C83E8
 * address: 0x021C83E8
 * packet: pkt_ov093_021C83E8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: Original loads r1 for func_021BB908 even though its body ignores it.
 * symbols:
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021BB908 0x021BB908 thumb ov093
 */
#include "../include/Obj13342.h"
extern void *func_021B86B8(void ***);
extern void func_021BB908(int *, int);
int func_021C83E8(unsigned char *p, int i)
{
    if ((unsigned int)func_021B86B8(*(void *** *)&((struct Obj13342 *)p)->f4) <= 1) {
        func_021BB908(*(int * *)&((struct Obj13342 *)p)->f0, i);
        return 1;
    }
    return 0;
}
