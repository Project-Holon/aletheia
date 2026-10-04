/*
 * function: func_021B95F0
 * address:  0x021B95F0
 * packet:   pkt_ov100_021B95F0
 * region:   ov100
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: the calls to func_02021730 (site +0050) and func_02021540
 *          (site +0084) have no witness outside this function's range.
 *          Both are unlabelled Thumb leaves in the ARM9 image, so neither
 *          `label` nor `sole-ref/code` can attest them; each call is their
 *          only referrer image-wide.  Every other byte is correct.
 * symbols:
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020216D4  0x020216D4  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   func_02021730  0x02021730  thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_020862F0  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E468  0x0207E468  arm
 */
#include "../include/Obj13704.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Chan02021FD8;
struct PalAnmSlot;
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *p, int i);
extern void func_020862F0(int, int);
extern void func_0207E5D0(int, int, int);
extern void func_0207E468(int, int, int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern int func_02021540(int);

int func_021B95F0(int a, int b, int c)
{
    int r4;
    int t;
    int r7;

    r4 = (int)func_02021518(((struct Obj13704 *)a)->f278);
    func_0202155C((struct PalAnmSlot *)r4, b, 0x200, ((struct Obj13704 *)a)->f278);
    t = c << 5;
    func_020216D4((struct PalAnmSlot *)r4, b, 0, t);
    func_02021FD8((struct Chan02021FD8 *)r4, b, 0, (u16)(c << 4), 6, 0);
    r7 = func_02021730((char *)r4, b);
    func_020862F0(r7, t);
    if (b != 1) {
        if (b == 3)
            func_0207E5D0(r7, 0, t);
    } else {
        func_0207E468(r7, 0, t);
    }
    func_020215A0((struct PalAnmSlot *)r4, b);
    return func_02021540(r4);
}
