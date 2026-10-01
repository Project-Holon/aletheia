/*
 * function: func_0200E5E4
 * address:  0x0200E5E4
 * packet:   pkt_0200E5E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf: the low seven bits of the halfword at +0x5C4. Filed
 * as the relocation witness for ov021 func_021D0C58 (wave A1).
 */

typedef unsigned short u16;

u16 func_0200E5E4(void *p)
{
    return *(u16 *)((char *)p + 0x5C4) & 0x7F;
}
