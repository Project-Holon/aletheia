/*
 * function: func_0201F53C
 * address:  0x0201F53C
 * packet:   pkt_0201F4A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  +0008 ABS32 sub_0209E8C8_Map       : 0209E8C8 (data, from header) has no witness outside 0201F53C..0201F548
 * symbols:
 *   sub_0209E8C8_Map  0x0209E8C8  data
 */

typedef unsigned char u8;

extern u8 sub_0209E8C8_Map[];

u8 func_0201F53C(int i)
{
    return sub_0209E8C8_Map[i];
}
