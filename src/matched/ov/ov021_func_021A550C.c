/*
 * function: func_021A550C
 * address:  0x021A550C
 * packet:   pkt_ov021_021A550C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5340  0x021A5340  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_021A5334  0x021A5334  thumb  ov021
 */
#include "../include/Obj06014.h"

typedef unsigned int u32;

int func_021A5340(u32 *p);
void *func_021A3960(unsigned char *p);
u32 *func_0216D550(u32 *p, u32 v);
void func_021A5334(u32 a);

void func_021A550C(u32 *p)
{
    if (func_021A5340(p) == 1) {
        func_0216D550(func_021A3960(*(unsigned char * *)&((struct Obj06014 *)p)->fC), 0x18);
        func_021A5334((u32)p);
    }
}
