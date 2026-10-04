/*
 * function: func_021ED294
 * address:  0x021ED294
 * packet:   pkt_ov093_021ED294
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7CE4  0x021F7CE4  thumb  ov094
 *   func_021F7F04  0x021F7F04  thumb  ov094
 */
#include "../include/Obj21590.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021B8E70(u8 *, u32);
extern void func_021F80E4(u32);
extern void func_021F7CE4(int);
extern void func_021F7F04(int);
void func_021ED294(u8 *p, u32 k, int x)
{
    u8 r = func_021B8E70(*(u8 * *)&((struct Obj21590 *)p)->f134, k);
    func_021F80E4(r);
    if (x == 0)
        func_021F7CE4(r);
    else
        func_021F7F04(r);
}
