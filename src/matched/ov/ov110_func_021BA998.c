/*
 * function: func_021BA998
 * address: 0x021BA998
 * packet: pkt_ov110_021BA998
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13772.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *, u32);
extern void func_021B9CBC(u8 *);
void func_021BA998(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BB6A0(*(u8 * *)&((struct Obj13772 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj13772 *)q)->f18));
    func_021B9CBC(p);
}
