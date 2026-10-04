/*
 * function: func_0216375C
 * address: 0x0216375C
 * packet: pkt_ov010_0216375C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216DD04 0x0216DD04 thumb ov010
 *   func_021AC528 0x021AC528 thumb ov021
 */
#include "../include/Obj00110.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_0216DD04(void *p);
extern void func_021AC528(u32 a, u32 b);
void func_0216375C(void *p, u8 *q)
{
    if (!(((struct Obj00110 *)q)->fE & 2) && !func_0216DD04(p))
        func_021AC528((u32)p, *(u32 *)&((struct Obj00110 *)q)->f14);
}
