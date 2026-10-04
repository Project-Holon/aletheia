/*
 * function: func_02074220
 * address:  0x02074220
 * packet:   pkt_020737C0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Relocates a freshly loaded archive header in place and publishes it: copy
 * the 0x30-byte header to the start of the image buffer, turn the three stored
 * file offsets at +0x10/+0x18/+0x20 into absolute pointers at +0x8C/+0x90/+0x88
 * (a zero offset stays a null pointer), clear +0x94, then walk the 0x10-byte
 * records that begin at f88+0xC and relocate each record's +8 word the same
 * way, and finally clear +0x30 and store the object into ptr_0214EA50.
 *
 * PINNED ../2.0/sp2, the pin six cluster siblings carry (func_020737C0,
 * func_02073AD0, func_02073B3C, func_02073CA0, func_020746E8, func_02073F3C,
 * func_02074894).
 *
 * docs/notes/pkt_02073F3C.c.txt flagged this as the packet's best remaining
 * candidate and had the record and the loop right. Three levers closed it,
 * measured at ../2.0/sp2 from a 184-byte first draft:
 *
 * 1. THE NULL ARMS ARE WRITTEN NULL-FIRST. The image emits `moveq r0,#0`
 *    before `addne r0,r4,r0`, so the source is `if (off == 0) p = 0; else
 *    p = base + off;`. Writing the non-null test first swaps both predicated
 *    instructions at all three sites (this front end never reorders an
 *    if/else -- docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * 2. THE LOOP OFFSET IS DERIVED FROM THE COUNTER, NOT CARRIED. A separate
 *    `off` local incremented by 0x10 costs a second zero: the image
 *    materialises ONE `mov r3,#0` and spends it on both the +0x94 store and
 *    the loop counter, then re-derives the byte offset. Spelling the record
 *    address as `(u8 *)h->f88 + 0xc + i * 0x10` took the residue from 48
 *    concrete bytes to 5.
 *
 * 3. THE STORE IS SHARED BY BOTH ARMS. The last 5 bytes were `moveq r0,r1` /
 *    one `str` in the image against a predicated `streq`/`strne` pair in ours:
 *    binding the relocated value to a local and storing it once after the if
 *    is what merges them
 *    (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md, read the
 *    other way round -- here the value, not the block, is what is shared).
 *
 * Both relocation sites resolve (func_02082A90 by label, ptr_0214EA50 by
 * literal), so nothing further was needed.
 *
 * symbols:
 *   ptr_0214EA50   0x0214EA50  data
 *   func_02082A90  0x02082A90  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074220.c \
 *       --func func_02074220 --addr 0x02074220 --cc ../2.0/sp2 --arm
 */
#include "../include/Obj11683.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Tbl { u32 pad0; u32 pad4; u32 count; };

struct Hdr {
    u8  pad00[0x10];
    u32 f10;
    u8  pad14[4];
    u32 f18;
    u8  pad1c[4];
    u32 f20;
    u8  pad24[0xc];
    u32 f30;
    u8  pad34[0x54];
    struct Tbl *f88;
    u32 f8c;
    u32 f90;
    u32 f94;
};

extern struct Hdr *ptr_0214EA50;
extern void func_02082A90(void *dst, void *src, u32 n);

void func_02074220(struct Hdr *h, u8 *base)
{
    u32 i;

    func_02082A90(base, h, 0x30);

    if (h->f18 == 0) h->f90 = 0; else h->f90 = (u32)(base + h->f18);
    if (h->f20 == 0) h->f88 = 0; else h->f88 = (struct Tbl *)(base + h->f20);
    if (h->f10 == 0) h->f8c = 0; else h->f8c = (u32)(base + h->f10);
    h->f94 = 0;

    for (i = 0; i < h->f88->count; i++) {
        u8 *p = (u8 *)h->f88 + 0xc + i * 0x10;
        u32 v = ((struct Obj11683 *)p)->f0;
        u32 r;
        if (v == 0) r = 0;
        else        r = (u32)(base + v);
        ((struct Obj11683 *)p)->f8 = r;
    }

    h->f30 = 0;
    ptr_0214EA50 = h;
}
