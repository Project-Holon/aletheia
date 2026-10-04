/*
 * function: func_021BA9B4
 * address: 0x021BA9B4
 * packet: pkt_ov110_021BA9B4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF784 0x021BF784 thumb ov110
 *   func_021BFC64 0x021BFC64 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13773.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021BF784(u8 *);
extern void func_021BFC64(u8 *, u32);
extern void func_021B9CBC(u8 *);
void func_021BA9B4(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BFC64(*(u8 * *)&((struct Obj13773 *)q)->f5C, func_021BF784(*(u8 * *)&((struct Obj13773 *)q)->f18));
    func_021B9CBC(p);
}
