/*
 * function: func_021F99D0
 * address:  0x021F99D0
 * packet:   pkt_021F99D0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02202744  0x02202744  thumb  ov135
 *   func_022029D4  0x022029D4  thumb  ov135
 *

 *
 * Tear the object down: sub-object at +0x7c, buffer at +0x34, then the object.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct WinMgr;
extern void func_02202744(u8 *p);
extern void func_022029D4(u8 *p);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_020307B0(u32 v);

void func_021F99D0(u8 *p)
{
    func_02202744(p + 0x7c);
    func_022029D4(*(u8 **)(p + 0x34));
    func_0202CA0C(*(struct WinMgr **)(p + 0x18));
    func_020307B0((u32)p);
}
