/*
 * function: func_02182988
 * address:  0x02182988
 * packet:   pkt_ov018_02182988
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): tail call to func_021828B8 with the
 * u16 table at 0x02183A20.
 *
 * symbols:
 *   func_021828B8  0x021828B8  thumb  ov018
 *   d_02183A20     0x02183A20  data   a2
 */

typedef unsigned short u16;

extern u16 d_02183A20[];

void func_021828B8(void *a, void *p, u16 *t);

void func_02182988(void *a, void *p)
{
    func_021828B8(a, p, d_02183A20);
}
