/*
 * function: func_021EBB34
 * address:  0x021EBB34
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBA84  0x021EBA84  thumb  ov170
 *
 * Stage 0x84 of the p+0x2c object with (0, arg1), then index 0xe
 *   with the third argument.
 */
#include "../include/Obj18518.h"


typedef unsigned int   u32;
struct WordSet;
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_021EBA84(char *, int, int);
void func_021EBB34(char *p, int a, int b)
{
    func_0201EF40((struct WordSet *)(*(int *)(((struct Obj18518 *)p)->f2C + 0x84)), 0, a);
    func_021EBA84(p, 0xe, b);
}
