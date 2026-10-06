/*
 * function: func_021A6974
 * address:  0x021A6974
 * packet:   pkt_ov021_021A6974
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021A5B6C  0x021A5B6C  thumb  ov021
 *   func_021A6870  0x021A6870  thumb  ov021
 *   func_021A6708  0x021A6708  thumb  ov021
 *   func_021A6744  0x021A6744  thumb  ov021
 *   func_021A6768  0x021A6768  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01658.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0216D608(void *o);
extern int func_021A5B6C(u32 a, u32 b, u32 c, u32 d);
extern void func_021A6870(u8 *p);
extern void func_021A6708(void *a);
extern void func_021A6744(void *a);
extern void func_021A6768(void *a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, u32 v);
extern void func_0216D548(u32 *p, u32 v);
extern void func_021A3964(u8 *o, u32 v);

u32 func_021A6974(u8 *p, u32 a1)
{
    void *o = ((struct Obj01658 *)p)->f1C;
    u32 r7 = func_0216D608(o);

    if (func_021A5B6C((u32)p, (u32)o, r7, 0)) {
        func_021A6870(p);
        return a1;
    }
    func_021A6708(p);
    func_021A6744(p);
    func_021A6768(p);
    func_0216D410(o, func_02197E7C(r7, 0x10));
    func_0216D548(o, 0x18);
    ((struct Obj01658 *)p)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj01658 *)p)->f14, 1);
    return r7;
}
