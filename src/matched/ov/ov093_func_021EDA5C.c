/*
 * function: func_021EDA5C
 * address:  0x021EDA5C
 * packet:   pkt_ov093_021EDA5C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EDA3C  0x021EDA3C  thumb  ov093
 *   func_021F8504  0x021F8504  thumb  ov094
 *   func_021F8B28  0x021F8B28  thumb  ov094
 *   func_021EDC28  0x021EDC28  thumb  ov093
 */
#include "../include/Obj21609.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021EDA3C(u8 *, u32);
extern void func_021F8504(u32, u32, u32);
extern int func_021F8B28(void);
extern void func_021EDC28(u8 *, u8, int);
void func_021EDA5C(u8 *p, u8 a, int b)
{
    int r = func_021EDA3C(*(u8 * *)&((struct Obj21609 *)p)->f134, a);
    if (r == 0)
        func_021F8504(0, 0, 0);
    func_021F8B28();
    func_021EDC28(p + 0x90 + r * 0x24, a, b);
}
