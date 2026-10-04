/*
 * function: func_021EA384
 * address:  0x021EA384
 * packet:   pkt_ov093_021EA384
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021ED494  0x021ED494  thumb  ov093
 */
#include "../include/Obj13558.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_021CD9E0(u8 *p);
extern void func_021ED494(char *p, int a, u32 b);

void func_021EA384(char *ctx, int a)
{
    func_021ED494(*(char * *)&((struct Obj13558 *)ctx)->f17C, a, func_021CD9E0(*(u8 * *)&((struct Obj13558 *)ctx)->f4));
}
