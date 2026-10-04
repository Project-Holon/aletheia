/*
 * function: func_021B6204
 * address: 0x021B6204
 * packet: pkt_ov070_021B6204
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two zero alignment bytes.
 * symbols:
 *   func_0201EF6C 0x0201EF6C thumb
 */
#include "../include/Obj20662.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
void func_021B6204(u8 *p, int a, unsigned int b, int c, int d)
{
    func_0201EF6C(((struct Obj20662 *)p)->f520, a, b, c, d);
}
