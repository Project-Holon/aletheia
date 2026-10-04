/*
 * function: func_021F8504
 * address:  0x021F8504
 * packet:   pkt_ov094_021F8504
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 *   func_022094BC  0x022094BC  thumb  ov094
 */
typedef unsigned int u32;

extern char *d_0220AF20;
typedef unsigned char  u8;
extern void func_022094BC(u8 *p, int i, int a, int b);

void func_021F8504(u32 a, u32 b, u32 c)
{
    func_022094BC((u8 *)(*(u32 *)(d_0220AF20 + 0x1B0)), a, b, c);
}
