/*
 * function: NNS_G2dPopMtx
 * address:  0x02066380
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The matrix-slot POP, the counterpart of NNS_G2dPushMtx.  Returns at once
 * when the slot index g_02147B88.slot (+0x0c) is already 0; otherwise
 * decrements it and, if the "first modified slot" halfword g_020A81F8 now
 * lies above the new index, resets it to the 0xFFFE sentinel.  Every
 * caller passes 1 in r0 (NNSi_G2dRendererDrawCellEntryTransformed, NNSi_G2dRendererDrawCellTransformed, NNSi_G2dRendererDrawMultiCellTransformed) and
 * the body never reads it, so the parameter is kept, unused.
 *
 * TWO LEVERS, both needed (EXACT under dsi/1.1p1 and equally under
 * ../2.0/sp2; the default is kept):
 *   1. The guard's MATERIALISED boolean (`movle r0, #1` / `movgt r0, #0` /
 *      `cmp r0, #0` / `bxne lr`) is `int r = !(g_02147B88.slot > 0);`.
 *      Every spelling of `slot <= 0` (plain, named local, inline helper,
 *      if/else, ternary) folds to a predicated body 24 bytes short, which is
 *      why the earlier drafts in docs/notes/pkt_02065D4C.c.txt and
 *      docs/notes/pkt_02065020.c.txt needed a fake `u16 *` return.  Same
 *      lever as src/matched/NNSi_G2dRendererDrawCellTransformed.c's `!(x == -1)`.
 *   2. The image loads g_020A81F8 BETWEEN the slot load and the subtract
 *      (`ldr r3, [r1, #0xc]` / `ldrh r2, [r0]` / `sub` / `str` / `cmp r2,
 *      r3`).  Without volatile both compilers sink the ldrh below the store
 *      (14 bytes out, immovable by permuter hill 80 and anneal 1200).  The
 *      read-modify-write through `(volatile Manager *)` with the halfword
 *      read through `*(volatile u16 *)` between them pins the order.
 *
 * symbols:
 *   g_02147B88  0x02147B88  data  a4
 *   g_020A81F8  0x020A81F8  data  a2
 */

#include "../include/G_Scr.h"

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct
{
    u16 count;
    u16 limit;
    int unk_04;
    void *obj;
    int slot;
} Manager;

extern Manager g_02147B88;
extern struct Scr g_020A81F8;

void NNS_G2dPopMtx(int n)
{
    int r = !(g_02147B88.slot > 0);
    if (r != 0)
        return;
    {
    int s = ((volatile Manager *)&g_02147B88)->slot - 1;
    u16 c = (*(volatile u16 *)&(*(u16 *)&g_020A81F8));
    ((volatile Manager *)&g_02147B88)->slot = s;
    if (c > s)
        (*(u16 *)&g_020A81F8) = 0xFFFE;
    }
}
