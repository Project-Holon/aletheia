/*
 * function: func_021A5378
 * address:  0x021A5378
 * packet:   pkt_ov021_021A5378
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A5304  0x021A5304  thumb  ov021
 *   func_021A530C  0x021A530C  thumb  ov021
 */

typedef unsigned int u32;

void func_021A5304(u32 *p, u32 m);
void func_021A530C(u32 *p, u32 m);

void func_021A5378(u32 *p, int on)
{
    if (on == 1)
        func_021A5304(p, 8);
    else
        func_021A530C(p, 8);
}
