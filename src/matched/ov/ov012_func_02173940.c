/*
 * function: func_02173940
 * address:  0x02173940
 * packet:   pkt_ov012_02173940
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save) in the ov012 listing: reads the byte at
 * +0x2832. Callee of ov031 func_021EFEC0 (a blocker of its MATCH).
 */

typedef unsigned char u8;

u8 func_02173940(u8 *p)
{
    return p[0x2832];
}
