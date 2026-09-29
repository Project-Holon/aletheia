/*
 * function: func_021F84E8
 * address:  0x021F84E8
 * packet:   pkt_ov094_021F84E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, the only blocker of ov093 func_021CDDDC (ov094 code loaded
 * alongside ov093).
 *
 * symbols:
 *   data_0220AF20  0x0220AF20  data
 *   func_02209318  0x02209318  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 *data_0220AF20;
extern void func_02209318(int a, int b, int c);

void func_021F84E8(int a, int b)
{
    func_02209318(*(int *)(data_0220AF20 + 0x1b0), a, b);
}
