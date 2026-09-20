/*
 * function: func_0201441C
 * address:  0x0201441C
 * packet:   pkt_0201441C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  +0008 ABS32 sub_0209E050_Map       : 0209E050 (data, from header) has no witness outside 0201441C..02014428
 * symbols:
 *   sub_0209E050_Map  0x0209E050  data
 */

typedef unsigned char u8;

extern u8 sub_0209E050_Map[];

u8 func_0201441C(int i)
{
    return sub_0209E050_Map[i];
}
