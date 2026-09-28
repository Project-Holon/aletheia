/*
 * function: func_02154438
 * address:  0x02154438
 * packet:   pkt_ov002_02154438
 * region:   ov002
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021543E8  0x021543E8  thumb  ov002
 */

typedef int s32;

extern void func_021543E8(s32 a, s32 b, s32 c, s32 d, s32 e);

void func_02154438(s32 a, s32 *b)
{
    func_021543E8(a, b[0], b[1], b[2], b[3]);
}
