/*
 * function: sub_02014A10
 * address:  0x02014A10
 * packet:   pkt_02014444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   sub_02014A10_Table  0x0209E054  data
 *
 * Truncated word-table lookup, unchecked index: reads a u32 out of a table
 * and returns its low halfword.
 *
 * Every concrete byte matches; the table's address appears nowhere else in
 * the image, so the pool word that names it has no witness outside this
 * one function and the entry caps at MATCH under the honesty rule.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 sub_02014A10_Table[];

u16 sub_02014A10(u32 index)
{
    return (u16)sub_02014A10_Table[index];
}
