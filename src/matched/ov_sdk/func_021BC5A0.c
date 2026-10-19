/*
 * function: Calloc
 * address:  0x021BC5A0
 * packet:   pkt_021C1CF8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   Calloc   0x021BC5A0  thumb
 *   HAND_ITEM_RollChance   0x021DCFD0  data
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm  arm9

 *
 * Allocate a*b bytes through entry 1 of the 0x021DCFD0 dispatch table, clear them, and return the block.
 * Addresses are Black-image addresses.
 *
 * The data symbol carries NO region token on purpose: 0x021DCFD0 is a bss
 * address nine overlays share and another one starts an object at, so an
 * `ov016` hint is contested and refused (see scratch/ov_ov016/o27/report.md).
 * Without the token _overlay_pool() fixes the overlay from the region this
 * function is compiled in, and the site attests sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/Calloc.c \
 *       --func Calloc --addr 0x021BC5A0 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void *(*HAND_ITEM_RollChance[])(int);
typedef unsigned int   u32;
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);

void *Calloc(int a, int b)
{
    int n = a * b;
    void *p = HAND_ITEM_RollChance[1](n);

    if (p)
        MSL_C_LIB_MemsetPtr(p, 0, n);
    return p;
}

