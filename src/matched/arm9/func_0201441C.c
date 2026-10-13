/*
 * function: func_0201441C
 * address:  0x0201441C
 * packet:   pkt_0201441C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0008 ABS32 _DirToRailKeyTable       : 0209E050 (data, from header) has no witness outside 0201441C..02014428
 * symbols:
 *   _DirToRailKeyTable  0x0209E050  data
 */

typedef unsigned char u8;

extern u8 _DirToRailKeyTable[];

u8 func_0201441C(int i)
{
    return _DirToRailKeyTable[i];
}
