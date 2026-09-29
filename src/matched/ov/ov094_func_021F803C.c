/*
 * function: func_021F803C
 * address:  0x021F803C
 * packet:   pkt_ov094_021F803C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   func_022070C0  0x022070C0  thumb  ov094
 */
typedef unsigned int u32;

extern char *d_0220AF20;
extern void func_022070C0(u32 obj, u32 a, u32 b, u32 mode, u32 c);

void func_021F803C(u32 a, u32 b, u32 c)
{
    switch (*(u32 *)(d_0220AF20 + 0x1BC)) {
    case 2:
        func_022070C0(*(u32 *)(d_0220AF20 + 0x1A4), a, b, 2, c);
        break;
    case 3:
        func_022070C0(*(u32 *)(d_0220AF20 + 0x1A4), a, b, 3, c);
        break;
    default:
        func_022070C0(*(u32 *)(d_0220AF20 + 0x1A4), a, b, 0, c);
        break;
    }
}
