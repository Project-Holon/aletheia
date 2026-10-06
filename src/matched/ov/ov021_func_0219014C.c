/*
 * function: func_0219014C
 * address:  0x0219014C
 * packet:   pkt_ov021_0219014C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021901E8  0x021901E8  thumb  ov021
 *   func_021C7058  0x021C7058  thumb  ov021
 *   func_021C701C  0x021C701C  thumb  ov021
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7C10  0x021C7C10  thumb  ov021
 *   func_021C7AE4  0x021C7AE4  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09472.h"
#include "../include/Obj19581.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021901E8(u8 *p);
extern u32 func_021C7058(u32 a, u32 b, u32 c);
extern u32 func_021C701C(u32 a, u32 b, u32 c);
extern u32 func_021C6F00(u32 a, u16 b, u32 c);
extern u32 func_021C7C10(u32 a, u16 b, void *c, void *d);
extern u32 func_021C7AE4(u32 a, u32 b, void *c);
extern u32 func_02188D38(u8 *p);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);

void func_0219014C(u32 *a)
{
    u32 h = *a;
    u8 *o = (u8 *)func_021901E8((u8 *)a);
    u32 k = ((struct Obj19581 *)o)->f0;
    u8 *q = o + 0x24;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v0 = func_021C7058(h, k, ((struct Obj09472 *)q)->f0);
    v1 = func_021C701C(h, k, ((struct Obj09472 *)q)->f2);
    v2 = func_021C6F00(h, k, ((struct Obj09472 *)q)->f4);
    v3 = func_021C7C10(h, k, o + 0xc, q + 8);
    v4 = func_021C7AE4(h, k, q + 0x14);
    h = func_02188D38((u8 *)h);
    func_021C6DE0((u8 *)h, (u32 *)v0, 0);
    func_021C6DE0((u8 *)h, (u32 *)v1, 0);
    func_021C6DE0((u8 *)h, (u32 *)v2, 0);
    func_021C6DE0((u8 *)h, (u32 *)v3, 0);
    func_021C6DE0((u8 *)h, (u32 *)v4, 0);
}
