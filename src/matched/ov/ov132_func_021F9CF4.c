/*
 * function: func_021F9CF4
 * address:  0x021F9CF4
 * packet:   pkt_021F9CF4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F9EDC  0x021F9EDC  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14086.h"

typedef unsigned short u16;
extern char *func_021F9EDC(char *p, u16 a);

void func_021F9CF4(char *p)
{
    ((struct Obj14086 *)p)->fBC = func_021F9EDC(((struct Obj14086 *)p)->f6C, 0x36);
}
