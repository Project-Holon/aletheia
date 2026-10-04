/*
 * function: func_021BFE8C
 * address: 0x021BFE8C
 * packet: pkt_ov217_021BFE8C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   func_021C2070 0x021C2070 thumb ov217
 */
#include "../include/Obj14747.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct Params { u32 handles[3]; u16 a, b, c, d, e; };
extern u32 func_021BF9F0(void *, u32);
extern u32 func_021C2070(u32, u32);
void func_021BFE8C(char *p)
{
    struct Params args;
    args.handles[0] = func_021BF9F0(p, 0);
    args.handles[1] = func_021BF9F0(p, 1);
    args.handles[2] = func_021BF9F0(p, 2);
    args.a = 0;
    args.b = 0;
    args.c = 1;
    args.d = 2;
    args.e = 3;
    ((struct Obj14747 *)p)->f2D0 = func_021C2070(((struct Obj14747 *)p)->f4, (u32)&args);
}
