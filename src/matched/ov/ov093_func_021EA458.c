/*
 * function: func_021EA458
 * address:  0x021EA458
 * packet:   pkt_ov093_021EA458
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021ED318  0x021ED318  thumb  ov093
 */
#include "../include/Obj13560.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021CD9E0(u8 *p);
extern void func_021ED318(char *p, u16 k, u16 a, int flag);

void func_021EA458(char *ctx, u16 a, u16 b)
{
    func_021ED318(*(char * *)&((struct Obj13560 *)ctx)->f17C, a, b, func_021CD9E0(*(u8 * *)&((struct Obj13560 *)ctx)->f4));
}
