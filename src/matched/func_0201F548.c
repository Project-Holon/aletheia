/*
 * function: func_0201F548
 * address:  0x0201F548
 * packet:   pkt_0201F4A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0008 ABS32 sub_0209E8CA_Map       : 0209E8CA (data, from header) has no witness outside 0201F548..0201F554
 * symbols:
 *   sub_0209E8CA_Map  0x0209E8CA  data
 */

typedef unsigned char u8;

extern u8 sub_0209E8CA_Map[];

u8 func_0201F548(int i)
{
    return sub_0209E8CA_Map[i];
}
