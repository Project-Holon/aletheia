/*
 * function: func_021EA8B4
 * address:  0x021EA8B4
 * packet:   pkt_ov093_021EA8B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   func_021ED660  0x021ED660  thumb  ov093
 */
#include "../include/Obj13563.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void func_021ED660(char *p, u32 k, u32 a, u32 b);

void func_021EA8B4(char *ctx, u32 a, u32 b)
{
    func_021ED660(*(char * *)&((struct Obj13563 *)ctx)->f17C, a, b, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13563 *)ctx)->f4));
}
