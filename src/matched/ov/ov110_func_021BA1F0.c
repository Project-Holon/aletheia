/*
 * function: func_021BA1F0
 * address: 0x021BA1F0
 * packet: pkt_ov110_021BA1F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   func_021BAE94 0x021BAE94 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BAE94(u8 *p, u8 *q, void *a2);
extern void func_021B9CBC(u8 *);
void func_021BA1F0(void *unused, u8 *p)
{
    func_021BAE94(((struct Obj00135 *)p)->f0, ((struct Obj00135 *)p)->f4, ((struct Obj00135 *)p)->f8);
    func_021B9CBC(p);
}
