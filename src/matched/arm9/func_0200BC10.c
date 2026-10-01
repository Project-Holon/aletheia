/*
 * function: func_0200BC10
 * address:  0x0200BC10
 * packet:   pkt_0200BC10
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 func_021C3378
 * (wave A1, lane 13).
 */

typedef unsigned char u8;

void func_0200BC10(u8 *p)
{
    if (*(int *)(p + 0x1C8) != 1)
        *(int *)(p + 0x1C8) = 1;
}
