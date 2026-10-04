/*
 * function: func_0216742C
 * address:  0x0216742C
 * packet:   pkt_0216742C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021673E0  0x021673E0  thumb  ov010
 */
#include "../include/Obj17732.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry32;
extern u8 func_021673E0(struct Entry32 *list, struct Entry32 *out, u32 cap, u32 start, int count);

int func_0216742C(int a0, int a1, int a2, int a3)
{
    unsigned char fr[4];
    int t4;
    int o4;
t4 = a3 + 0;
a3 = 0xa;
    o4 = a3;
a3 = 0;
    a0 = func_021673E0((struct Entry32 *)a0, (struct Entry32 *)a1, a2, a3, o4);
loc_0216743C:
((struct Obj17732 *)((char *)t4))->f0 = a0;
a0 = 0;
    return a0;
}
