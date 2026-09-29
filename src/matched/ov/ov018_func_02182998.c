/*
 * function: func_02182998
 * address:  0x02182998
 * packet:   pkt_ov018_02182998
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): tail call to func_021828B8 with the
 * u16 table at 0x02183A38.
 *
 * symbols:
 *   func_021828B8  0x021828B8  thumb  ov018
 *   d_02183A38     0x02183A38  data   a2
 */

typedef unsigned short u16;

extern u16 d_02183A38[];

void func_021828B8(void *a, void *p, u16 *t);

void func_02182998(void *a, void *p)
{
    func_021828B8(a, p, d_02183A38);
}
