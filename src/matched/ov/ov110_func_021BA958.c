/*
 * function: func_021BA958
 * address: 0x021BA958
 * packet: pkt_ov110_021BA958
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF714 0x021BF714 thumb ov110
 *   func_021BC72C 0x021BC72C thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13770.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_021BF714(u8 *);
extern void func_021BC72C(char *p, int i);
extern void func_021B9CBC(u8 *);
void func_021BA958(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BC72C((char *)(*(u8 * *)&((struct Obj13770 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj13770 *)q)->f18));
    func_021B9CBC(p);
}
