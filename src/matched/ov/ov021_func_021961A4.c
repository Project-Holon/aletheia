/*
 * function: func_021961A4
 * address:  0x021961A4
 * packet:   pkt_ov021_021961A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_02021730  0x02021730  thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 */
#include "../include/Obj12628.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Chan02021FD8;
struct PalAnmSlot;
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *p, int i);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void func_02021540(void *a0);
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207E5D0(void *p, u32 a, u32 size);
extern void func_0207E468(void *p, u32 a, u32 size);

void func_021961A4(u8 *p, u32 a, u32 b)
{
    u32 h;
    u32 n;
    void *d;

    h = (u32)func_02021518(((struct Obj12628 *)p)->f10);
    func_0202155C((struct PalAnmSlot *)h, a, 0x200, ((struct Obj12628 *)p)->f10);
    n = b << 5;
    func_020216D4((struct PalAnmSlot *)h, a, 0, n);
    func_02021FD8((struct Chan02021FD8 *)h, a, 0, (b << 20) >> 16, 6, 0);
    d = (void *)func_02021730((char *)h, a);
    DC_FlushRange(d, n);
    if (a != 1) {
        if (a == 3)
            func_0207E5D0(d, 0, n);
    } else {
        func_0207E468(d, 0, n);
    }
    func_020215A0((struct PalAnmSlot *)h, a);
    func_02021540((void *)h);
}
