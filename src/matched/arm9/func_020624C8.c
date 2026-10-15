/*
 * function: NNS_GfdAllocPlttVram
 * address:  0x020624C8
 * packet:   pkt_02062474
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146BB0      0x02146BB0  data
 *   g_02146BB4      0x02146BB4  data
 *   NNSi_GfdAllocLnkVram   0x02061EB8  arm
 *   NNSi_GfdFreeLnkVram   0x0206207C  arm
 *
 * Promote-first callee of src/pending/NNSi_GfdInitPlttVramManager.c (parks lane 2).
 * Allocate `size` bytes rounded up to eight from the sub-64K heap pair at
 * 0x02146BB0/0x02146BB4 and return a packed handle:
 * (address >> 3) | ((size >> 3) << 16).  Size 0 asks for eight bytes, a
 * request at or past 0x7FFF8 is refused, and the flag argument picks the
 * 8-byte-flag heap or the 0x10-byte-flag one; on the latter a block that
 * would cross 0x10000 is handed back to NNSi_GfdFreeLnkVram and refused.
 *
 * Three spelling details are load-bearing and were each measured:
 *   - the 2.0 front end, not dsi/1.1p1: on 1.1p1 this same C keeps the two
 *     heap addresses in callee-saved r5/r6 (frame 212 bytes, push
 *     {r4,r5,r6,lr}) where the original rematerialises them from the pool at
 *     every call site (204 bytes, push {r4,lr});
 *   - a separate local for the rounded size with `size = n;` after the
 *     if/else: assigning straight back gives `movs r4, r0` where the
 *     original has `cmp r0, #0` (4 bytes);
 *   - the two halves of the packed handle are written size-high first
 *     (`((size >> 3) << 16) | ((addr << 13) >> 16)`): the other order costs
 *     4 more bytes, the accumulator naming its second operand.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_GfdAllocPlttVram.c \
 *       --func NNS_GfdAllocPlttVram --addr 0x020624C8 --cc ../2.0/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */

#include "../include/G_Hdr02062474.h"

typedef unsigned int u32;

extern struct Hdr02062474 g_02146BB0;
extern u32 g_02146BB4;

struct Blk;
extern int NNSi_GfdAllocLnkVram(struct Blk **list, struct Blk **pool, u32 *pRet, u32 size, u32 alignment);
extern int NNSi_GfdFreeLnkVram(void *headp, void *freep, int a2, int a3);

u32 NNS_GfdAllocPlttVram(u32 size, u32 flag)
{
    u32 addr;
    u32 r;
    u32 n;

    if (size == 0)
        n = 8;
    else
        n = (size + 7) & ~7;
    size = n;
    if (size >= 0x7FFF8)
        return 0;
    if (flag != 0) {
        r = NNSi_GfdAllocLnkVram((struct Blk **)(&(*(u32 *)&g_02146BB0)), (struct Blk **)(&g_02146BB4), &addr, size, 8);
        if (addr + size > 0x10000) {
            NNSi_GfdFreeLnkVram(&(*(u32 *)&g_02146BB0), &g_02146BB4, addr, size);
            return 0;
        }
    } else {
        r = NNSi_GfdAllocLnkVram((struct Blk **)(&(*(u32 *)&g_02146BB0)), (struct Blk **)(&g_02146BB4), &addr, size, 0x10);
    }
    if (r == 0)
        return 0;
    return ((size >> 3) << 16) | ((addr << 13) >> 16);
}
