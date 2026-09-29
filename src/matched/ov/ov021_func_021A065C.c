/*
 * function: func_021A065C
 * address:  0x021A065C
 * packet:   pkt_ov021_021A065C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the ov026 lane.
 *
 * symbols:
 *   func_021A065C 0x021A065C thumb ov021
 *   func_021A0CE4 0x021A0CE4 thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern int func_021A0CE4(u16 *p);

int func_021A065C(u8 *p)
{
    return func_021A0CE4((u16 *)(p + 0x484));
}
