/*
 * function: func_02189590
 * address: 0x02189590
 * packet: pkt_ov096_02189590
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020113B0 0x020113B0 thumb
 */
#include "../include/Obj00005.h"
#include "../include/Obj21964.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(u8 *);
struct Cur;
extern void func_020113B0(struct Cur *c, u32 v);
int func_02189590(u8 *a, u8 *b)
{
    u32 t; t = func_0201134C(a); func_020113B0((struct Cur *)a, *(u32 *)&((struct Obj00005 *)a)->f14 + t); return ((struct Obj21964 *)b)->fC4;
}
