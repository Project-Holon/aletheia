/*
 * function: BG_SYS_LoadPlttEntry
 * address:  0x02040EBC
 * packet:   pkt_02040DA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_LoadPltt  0x02040E78  arm
 */

typedef unsigned int u32;

extern void BG_SYS_LoadPltt(u32, void *, u32, u32);

void BG_SYS_LoadPlttEntry(u32 a0, u32 a1)
{
    BG_SYS_LoadPltt(a0, &a1, 2, 0);
}
