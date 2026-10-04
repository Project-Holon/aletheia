/*
 * function: func_021EA3B8
 * address:  0x021EA3B8
 * packet:   pkt_ov093_021EA3B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021F7A28  0x021F7A28  thumb  ov094
 */
#include "../include/Obj21561.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_021CD9E0(u8 *p);
extern void func_021F7A28(int a, u32 b);

void func_021EA3B8(char *ctx, int a, int b)
{
    if (func_021CD9E0(*(u8 * *)&((struct Obj21561 *)ctx)->f4) == 0) {
        func_021F7A28(a, b);
    }
}
