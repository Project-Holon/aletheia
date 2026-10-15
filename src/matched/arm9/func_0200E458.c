/*
 * function: MISC_SAVEDATA_GetHalfword
 * address:  0x0200E458
 * packet:   pkt_0200E458
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module: halfword array index.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

u16 MISC_SAVEDATA_GetHalfword(const u16 *p, int i)
{
    return p[i];
}
