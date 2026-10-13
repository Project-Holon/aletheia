/*
 * function: CLACT_EntryOamSub
 * address:  0x0204BFF4
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   CLACT_EntryOam  0x0204BF40  arm
 *
 * Same forward as CLACT_EntryOamMain, but aimed at the sub-command block at
 * +0x20 of the manager, whose id and payload sit at +0xf2 / +0xf4.
 */

#include "../include/G_Mgr.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Mgr *g_ClactSystem;

struct OamEntry;
struct Win;
extern void CLACT_EntryOam(struct Win *win, struct OamEntry *src, u32 mode, u32 pal, u32 op);

void CLACT_EntryOamSub(u32 a0, u32 a1)
{
    CLACT_EntryOam((struct Win *)((u8 *)g_ClactSystem + 0x20), (struct OamEntry *)a0, a1,
                  g_ClactSystem->unk_f2, g_ClactSystem->unk_f4);
}
