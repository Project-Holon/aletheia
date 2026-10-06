/*
 * function: func_021BD20C
 * address:  0x021BD20C
 * packet:   pkt_ov021_021BD20C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BD2D8  0x021BD2D8  thumb  ov021
 *
 * Unlabelled leaf: tail call to func_021BD2D8 (loads +0x44).
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021BD2D8(u8 *p);

unsigned int func_021BD20C(char *p)
{
    return func_021BD2D8((u8 *)p);
}
